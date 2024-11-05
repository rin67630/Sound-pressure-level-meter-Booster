# -------------------------------------------------------------------------------------------------
# *** USER-EDITABLE DEFAULTS (values when the user enters nothing) ***
# Define the user Defaults in Python
Default_DEVCNAME = "Patched"
Default_WIFISSID = "Your SSID"
Default_WIFIPASS = "very,very_secret"
Default_CLOUDNAM = "provider address"
Default_CLOUDUSR = "user@provider"
Default_DEVCCRED = "even-more-secret"
gmtoff = "3600"        # Offset to GMT in secs
dstoff = "7200"        # Summer Offset in secs
longitude = "07.0572"  # Longitude
latitude = "48.7356"   # Latitude

# -------------------------------------------------------------------------------------------------
# *** ESP DEVICE PROGRAMMING TEMPLATE  *** # (mandatory C++ code template, # cf. appendix, end of file)

# -------------------------------------------------------------------------------------------------
# *** PYTHON PATCHER SCRIPT (users, don't change beyond)
import subprocess
import sys
import os
import time
import getpass

import geocoder   # pip3 import geocoder
print("Welcome to PythonPatcher for ESP devices ")
print("From RIN67630 @ https://github.com/rin67630/ESP_Binary_patcher")
# define the same placeholders in Python
Placeholder_DEVCNAME = b"DEVCNAME        "  # Device Name & Host.   (exactly 16 chars incl spaces)
Placeholder_WIFISSID = b"WIFISSID        "  # WiFi SSID.            (exactly 16 chars incl spaces)
Placeholder_WIFIPASS = b"WIFIPASS                "  # WiFi Password.(exactly 24 chars incl spaces)
Placeholder_CLOUDNAM = b"CLOUDNAM        "  # Cloud Name.           (exactly 16 chars incl spaces)
Placeholder_DEVCCRED = b"DEVCCRED        "  # Device Credentials    (exactly 16 chars incl spaces)
Placeholder_DEVCUSER = b"DEVCUSER        "  # Device User           (exactly 16 chars incl spaces)
Placeholder_TZ_OFF   = b"TZ_OFF  "          # Offset to GMT in secs (exactly  8 chars incl spaces)
Placeholder_DST_OFF  = b"DST_OFF "          # Summer Offset in secs (exactly  8 chars incl spaces)
Placeholder_LONGITUD = b"LONGTD  "          # Longitude             (exactly  8 chars incl spaces)
Placeholder_LATITUDE = b"LATITD  "          # Latitude              (exactly  8 chars incl spaces)

# Listing potential files to patch in current directory
print()
print("Please select a file from: ")
fileList = [name for name in os.listdir() if name.endswith(".bin")]
for cnt, fileName in enumerate(fileList, 1):
    print(f"[{cnt}] {fileName}")

# Choosing the one you want to process
choice = int(input(f"Select .bin file[1-{cnt}]: "))
infile = fileList[choice - 1]

f = open(infile, 'rb')
content_to_patch = f.read()
f.close()

if not Placeholder_WIFISSID in content_to_patch or not Placeholder_WIFIPASS in content_to_patch :  # flash directly without patching
    print(f"Working on {infile}, without patching !")

    answer = input("Flashing as it is to the ESP device on the first valid serial port? ")
    if answer.upper() in ["Y", "YES"]:
        subprocess.run([sys.executable, "esptool.py", "write_flash", "-z", " 0x0000", infile])
        print("You many want to note your device's MAC address from the upload protocol")
        print("Enjoy your ESP device on-line ! ")
        exit()

    answer = input("Flash the ESP Over The Air? (must have Arduino-OTA)")
    if answer.upper() in ["Y", "YES"]:
        IP = input("Enter IP of the device to flash [nnn.nnn.nnn.nnn]")
        subprocess.run([sys.executable, "espota.py", "-i", IP, "-f", outfile])
        print("Enjoy your re-flashed ESP device ! ")
        exit()
    exit()

print(f"Working on {infile}, let's begin to patch !")
# Preparing the output filename
outfile = infile.replace(".bin", "_patched.bin")

# get user WIFISSID
User_WIFISSID = input("Enter SSID:") or Default_WIFISSID
if len(User_WIFISSID) > len(Placeholder_WIFISSID):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_WIFISSID = User_WIFISSID.encode("ascii")
# fill data to become exactly the length of the placeholders.
User_WIFISSID = User_WIFISSID.ljust(len(Placeholder_WIFISSID), b"\0")
content_patched = content_to_patch.replace(Placeholder_WIFISSID, User_WIFISSID)

# get user WIFIPASS
User_WIFIPASS = getpass.getpass(prompt='Please enter Password:')  # variant hiding the password
# User_WIFIPASS = input('Please enter Password:') or Default_WIFIPASS
if len(User_WIFIPASS) > len(Placeholder_WIFIPASS):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_WIFIPASS = User_WIFIPASS.encode("ascii")
# fill data to become exactly the length of the placeholders.
User_WIFIPASS = User_WIFIPASS.ljust(len(Placeholder_WIFIPASS), b"\0")
content_patched = content_patched.replace(Placeholder_WIFIPASS, User_WIFIPASS)

# get user DVCNAME
User_DEVCNAME = input("Please enter Device Name:") or Default_DEVCNAME
if len(User_DEVCNAME) > len(Placeholder_DEVCNAME):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_DEVCNAME = User_DEVCNAME.encode("ascii")
# fill data to become exactly the length of the placeholders.
User_DEVCNAME = User_DEVCNAME.ljust(len(Placeholder_DEVCNAME), b"\0")
content_patched = content_patched.replace(Placeholder_DEVCNAME, User_DEVCNAME)

# get user CLOUDNAM
User_CLOUDNAM = input("Please enter Cloud Service name or IP") or Default_CLOUDNAM
if len(User_CLOUDNAM) > len(Placeholder_CLOUDNAM):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_CLOUDNAM = User_CLOUDNAM.encode("ascii")
# ill data to become exactly the length of the placeholders.
User_CLOUDNAM = User_CLOUDNAM.ljust(len(Placeholder_CLOUDNAM), b"\0")
content_patched = content_patched.replace(Placeholder_CLOUDNAM, User_CLOUDNAM)

# get user DEVCUSER
User_DEVCUSER = input("Please enter Device User:") or Default_DEVCUSER
if len(User_DEVCUSER) > len(Placeholder_DEVCUSER):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_DEVCUSER = User_DEVCUSER.encode("ascii")
# fill data to become exactly the length of the placeholders.
User_DEVCUSER = User_DEVCUSER.ljust(len(Placeholder_DEVCUSER), b"\0")
content_patched = content_patched.replace(Placeholder_DEVCCRED, User_DEVCUSER)


# get user DEVCCRED
User_DEVCCRED = input("Please enter Device Credentials:") or Default_DEVCCRED
if len(User_DEVCCRED) > len(Placeholder_DEVCCRED):
    raise Exception("Input too long")

# convert that String to ascii bytes
User_DEVCCRED = User_DEVCCRED.encode("ascii")
# fill data to become exactly the length of the placeholders.
User_DEVCCRED = User_DEVCCRED.ljust(len(Placeholder_DEVCCRED), b"\0")
content_patched = content_patched.replace(Placeholder_DEVCCRED, User_DEVCCRED)

# Process Geo Part only if geo-placholders exist
if Placeholder_LATITUDE in content_to_patch :  #process Geo part
    # Obtain the Parameters for the ESP NTC library
    tm = time.localtime()
    gmtoff = str(tm.tm_gmtoff)
    dstoff = str(tm.tm_isdst * 3600)

    # Obtain the Geo Information from your IP
    ip = geocoder.ip("me")
    print(f"\nYour IP appears to be: {ip.ip}")
    print(f"Accordingly, you appear to be in: {ip.city}")
    # print(f"Which timezone is: {ip.timezone}")
    print(f"Time zone offset is:  {gmtoff} seconds ahead of Greenwich")
    print(f"Daylight saving is:  {dstoff} seconds")
    latitude = str(ip.latlng[0])
    longitude = str(ip.latlng[1])
    print(f"Your latitude is: {latitude}")
    print(f"Your longitude is: {longitude}")

    answer = input(f"Patch the ESP device with these values?(y), or manually enter values?(n)")

    # Get manual values?
    if answer.upper() in ["N", "NO"]:
        gmtoff = input("Please enter GMT offset in seconds ahead, or behind (-) Greenwich:") or gmtoff
        testval = int(gmtoff)
        if not -43200 <= testval <= 43200:
            raise Exception("GMT offset must be in range -43200...43200")

        dstoff = input("Please enter Daylight Saving offset in seconds ahead, or behind (-) Greenwich: ") or dstoff
        testval = int(dstoff)
        if not -43200 <= testval <= 43200:
            raise Exception("Daylight Saving offset must be in range -43200...43200")

        latitude = input("Please enter the device's latitude (-180...180): ") or latitude
        latitude = latitude[0:7]
        testval = float(latitude)
        if not -180 <= testval <= 180:
            raise Exception("latitude must be in range -180...180")

        longitude = input("Please enter the device's longitude (-90...90: ") or longitude
        longitude = longitude[0:7]
        testval = float(longitude)
        if not -90 <= testval <= 90:
            raise Exception("longitude must be in range -90...90")

    # Patch the Geo Information to your device
    gmtoff = gmtoff.encode("ascii")
    User_TZ_OFF = gmtoff.ljust(len(Placeholder_TZ_OFF), b"\0")
    content_patched = content_patched.replace(Placeholder_TZ_OFF, User_TZ_OFF)

    dstoff = dstoff.encode("ascii")
    User_DST_OFF = dstoff.ljust(len(Placeholder_DST_OFF), b"\0")
    content_patched = content_patched.replace(Placeholder_DST_OFF, User_DST_OFF)

    latitude = latitude.encode("ascii")
    User_LATITUDE = latitude.ljust(len(Placeholder_LATITUDE), b"\0")
    content_patched = content_patched.replace(Placeholder_DEVCCRED, User_DEVCCRED)

    longitude = longitude.encode("ascii")

    User_LONGITUD = longitude.ljust(len(Placeholder_LONGITUD), b"\0")
    content_patched = content_patched.replace(Placeholder_DEVCCRED, User_DEVCCRED)

# Verify that the patched file has kept its length
if not len(content_patched) == len(content_to_patch):
        raise Exception("Something went wrong, patched file length different")

# write back the patched content.
f = open(outfile, 'wb')
f.write(content_patched)
f.close()

# Patching done, now flashing your device
print(f"Patched binary {outfile} saved")

answer = input("Flashing it now to the ESP device on the first valid serial port? ")
if answer.upper() in ["Y", "YES"]:
    subprocess.run([sys.executable, "esptool.py", "write_flash", "-z", " 0x0000", outfile])
    print("You many want to note your device's MAC address from the upload protocol")
    print("Enjoy your ESP device on-line ! ")

# esptool.py read_mac

answer = input("Re-flash the ESP Over The Air?(OTA, needs device IP )")
if answer.upper() in ["Y", "YES"]:
    IP = input("Enter IP of the device to flash [nnn.nnn.nnn.nnn]")
    subprocess.run([sys.executable, "espota.py", "-i", IP, "-f", outfile])
    print("Enjoy your re-flashed ESP device ! ")

"""
// *** ESP DEVICE PROGRAMMING TEMPLATE  ***
// These original Placeholders must be defined defined in your C++ code
#define DEVICE_NAME          "DEVCNAME        "
#define WIFI_SSID            "WIFISSID        "
#define WIFI_PASS            "WIFIPASS                "
#define SERVICE_PROViDER     "CLOUDNAM        "
#define DEVICE_USER          "DEVCUSER        "
#define DEVICE_CREDENTIALS   "DEVCCRED        "
#define TZ_OFF   = "TZ_OFF  "       
#define DST_OFF  = "DST_OFF "
#define LONGITUD = "LONGTD  "
#define LATITUDE = "LATITD  "
int   tz_off  = int(TZ_OFF);
int   dst_off = int(DST_OFF);
float longtd  = float(LONGTD);
float latitd  = float(LATITD);
"""
    
fileList = [name for name in os.listdir() if (name.endswith(".h") and "z_Thinger" in name) ]
print(f"\nI found these Thinger.io dashboards templates: {fileList}")

answer = input("Personalising these templates with your credentials ?")
if answer.upper() in ["Y", "YES"]:
    print(f"Opening each file and replacing b'Cloudname' with {User_CLOUDNAM}; replacing b'Device' with {User_DEVCNAME} ...")
else:
    sys.exit("Proud to have served you as user, enjoy https://console.thinger.io")

for file in fileList:
    f = open(file , 'rb')
    template = f.read()
    f.close()
    template = template.replace(b'Cloudname', User_CLOUDNAM)
    template = template.replace(b'Device', User_DEVCNAME)
    f = open(file , 'wb')
    f.write(template)
    f.close()
print("Done!")
print("Please read the instructions to post-configure the dashboards @ Thinger.io: PostConfigureThinger.txt")
print("Proud to have served you as user, enjoy https://console.thinger.io")   
    
    
