{
  "controls": {
    "aggregation": {
      "auto": true,
      "period": "1m"
    },
    "hide_hours_picker": true,
    "timespan": {
      "magnitude": "day",
      "mode": "relative",
      "period": "latest",
      "value": 2
    }
  },
  "description": "Kettwig v.d.B. Langzeit (Zeitspanne einstellbar) und Statistik",
  "name": "Kettwig v.d.B.  Langzeit (Minutentakt)",
  "properties": {
    "background_image": "#888888",
    "border_radius": "10px",
    "columns": 12,
    "row_height": 40
  },
  "tabs": [
    {
      "icon": "fas fa-tachometer-alt",
      "name": "TAGESSTATISTIK",
      "widgets": [
        {
          "layout": {
            "col": 5,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "17h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "17h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 25,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "showOffline": {
              "type": "none"
            },
            "title": "Nacht"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "Nighttime",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "22h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "22h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "05h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "05h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "04h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "04h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "03h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "03h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "02h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "02h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "01h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "01h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L18h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L18h",
                "user": "LO1Noisewatch"
              },
              "name": "L18h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "16h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "16h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "15h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "15h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "14h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "14h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "12h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "12h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "21h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "21h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 6,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            },
            "title": "Fast (125mS)"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB ( A)",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "fast",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "10h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "10h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "09h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "09h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "08h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "08h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "07h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "07h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "06h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "06h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "20h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "20h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "letztens um..."
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "peakTime",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "18h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "18h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "13h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "13h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 27,
            "sizeX": 12,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Äquivalenter Schallpegel pro Stunde  (Laufend)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 41,
            "sizeX": 12,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Äquivalenter Schallpegel pro Stunde (Tag gestern)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L05h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L05h",
                "user": "LO1Noisewatch"
              },
              "name": "L05h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L04h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L04h",
                "user": "LO1Noisewatch"
              },
              "name": "L04h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L03h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L03h",
                "user": "LO1Noisewatch"
              },
              "name": "L03h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L02h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L02h",
                "user": "LO1Noisewatch"
              },
              "name": "L02h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L01h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L01h",
                "user": "LO1Noisewatch"
              },
              "name": "L01h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L23h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L23h",
                "user": "LO1Noisewatch"
              },
              "name": "L23h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L21h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L21h",
                "user": "LO1Noisewatch"
              },
              "name": "L21h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L12h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L12h",
                "user": "LO1Noisewatch"
              },
              "name": "L12h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L11h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L11h",
                "user": "LO1Noisewatch"
              },
              "name": "L11h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L10h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L10h",
                "user": "LO1Noisewatch"
              },
              "name": "L10h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L09h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L09h",
                "user": "LO1Noisewatch"
              },
              "name": "L09h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L08h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L08h",
                "user": "LO1Noisewatch"
              },
              "name": "L08h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L07h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L07h",
                "user": "LO1Noisewatch"
              },
              "name": "L07h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L06h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L06h",
                "user": "LO1Noisewatch"
              },
              "name": "L06h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L17h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L17h",
                "user": "LO1Noisewatch"
              },
              "name": "L17h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L16h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L16h",
                "user": "LO1Noisewatch"
              },
              "name": "L16h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L15h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L15h",
                "user": "LO1Noisewatch"
              },
              "name": "L15h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L14h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L14h",
                "user": "LO1Noisewatch"
              },
              "name": "L14h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L13h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L13h",
                "user": "LO1Noisewatch"
              },
              "name": "L13h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L20h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L20h",
                "user": "LO1Noisewatch"
              },
              "name": "L20h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#fafafa",
            "title": "L19h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L19h",
                "user": "LO1Noisewatch"
              },
              "name": "L19h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 45,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L22h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L22h",
                "user": "LO1Noisewatch"
              },
              "name": "L22h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 43,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "L00h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "L00h",
                "user": "LO1Noisewatch"
              },
              "name": "L00h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 33,
            "sizeX": 12,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Erkannte Überflüge  pro Stunde  (Laufend)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "00h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "00h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "21h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "21h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "04h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "04h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "03h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "03h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "02h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "02h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "01h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "01h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "23h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "23h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "05h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "05h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "11h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "10h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "10h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "09h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "09h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "08h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "08h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "07h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "07h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "06h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "06h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "19h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "17h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "17h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "16h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "16h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "15h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "15h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "14h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "14h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "13h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "13h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "12h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "12h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "18h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "18h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "20h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "20h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 37,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "22h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "22h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N21h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N21h",
                "user": "LO1Noisewatch"
              },
              "name": "N21h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 47,
            "sizeX": 12,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Erkannte Überflüge  pro Stunde (Tag gestern)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 35,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "00h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "00h",
                "property": "NATu",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N04h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N04h",
                "user": "LO1Noisewatch"
              },
              "name": "N04h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N22h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N22h",
                "user": "LO1Noisewatch"
              },
              "name": "N22h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N01h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N01h",
                "user": "LO1Noisewatch"
              },
              "name": "N01h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N00h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N00h",
                "user": "LO1Noisewatch"
              },
              "name": "N00h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N05h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N05h",
                "user": "LO1Noisewatch"
              },
              "name": "N05h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N08h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N08h",
                "user": "LO1Noisewatch"
              },
              "name": "N08h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N07h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N07h",
                "user": "LO1Noisewatch"
              },
              "name": "N07h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N06h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N06h",
                "user": "LO1Noisewatch"
              },
              "name": "N06h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N10h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N10h",
                "user": "LO1Noisewatch"
              },
              "name": "N10h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N09h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N09h",
                "user": "LO1Noisewatch"
              },
              "name": "N09h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N11h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N11h",
                "user": "LO1Noisewatch"
              },
              "name": "N11h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N12h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N12h",
                "user": "LO1Noisewatch"
              },
              "name": "N12h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N02h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N02h",
                "user": "LO1Noisewatch"
              },
              "name": "N02h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 49,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N03h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N03h",
                "user": "LO1Noisewatch"
              },
              "name": "N03h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N18h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N18h",
                "user": "LO1Noisewatch"
              },
              "name": "N18h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 5,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N17h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N17h",
                "user": "LO1Noisewatch"
              },
              "name": "N17h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N16h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N16h",
                "user": "LO1Noisewatch"
              },
              "name": "N16h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N15h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N15h",
                "user": "LO1Noisewatch"
              },
              "name": "N15h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N14h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N14h",
                "user": "LO1Noisewatch"
              },
              "name": "N14h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N13h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N13h",
                "user": "LO1Noisewatch"
              },
              "name": "N13h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N20h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N20h",
                "user": "LO1Noisewatch"
              },
              "name": "N20h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#f9fafa",
            "title": "N19h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N19h",
                "user": "LO1Noisewatch"
              },
              "name": "N19h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 51,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "N23h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "DAY",
                "mapping": "N23h",
                "user": "LO1Noisewatch"
              },
              "name": "N23h",
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 6,
            "sizeX": 11,
            "sizeY": 21
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            },
            "title": "Nur erkannte Überflüge"
          },
          "properties": {
            "axis": true,
            "fill": true,
            "legend": true,
            "multiple_axes": false
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "backgr",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "color": "#bebc11",
              "name": "Backgr",
              "source": "bucket",
              "timespan": {
                "mode": "configurable"
              }
            },
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "LEtr",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "color": "#3e1505",
              "name": "LEmax",
              "source": "bucket",
              "timespan": {
                "mode": "configurable"
              }
            }
          ],
          "type": "chart"
        },
        {
          "layout": {
            "col": 11,
            "row": 15,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#dcdfdc",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Gestern"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 0,
            "sizeX": 3,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "..."
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Letzte Überflugerkennung"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 29,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "11h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 3,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            },
            "title": "Slow"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB ( A)",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "slow",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "title": "19h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "Leq (Max-190dB)"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "less10dBLeq",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "NAT in Stunde"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "NAT",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "Spitze"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "eventPeak",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 8,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "LEqu (>55dB)"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "aboveThreshLeq",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "Für___Max-10dB"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "Sek.",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "less10dBDuration",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#d0ffd5",
            "showOffline": {
              "type": "none"
            },
            "title": "Für____>58dB"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "40px",
            "unit": "Sek.",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "EVENT",
                "mapping": "aboveThreshDuration",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "19h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "bucket",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 9,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            },
            "title": "Impulse"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB ( A)",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "impulse",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 12,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            },
            "title": "Background"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB ( A)",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "backgr",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "11h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 31,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "title": "23h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "23h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 21,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            },
            "title": "06h-22h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "Daytime",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 0,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Aktuell"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 19,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            },
            "title": "24h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "Day",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 39,
            "sizeX": 12,
            "sizeY": 2
          },
          "panel": {
            "color": "#000000",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": ""
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 9,
            "row": 3,
            "sizeX": 2,
            "sizeY": 3
          },
          "panel": {
            "color": "#808080",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#e8df6d",
            "decimal_places": 0,
            "icon": "",
            "size": "48px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Hintergrund"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 11,
            "row": 23,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#c2e7fa",
            "showOffline": {
              "type": "none"
            },
            "title": "22h-24h"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "L22-24h",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 3,
            "sizeX": 8,
            "sizeY": 3
          },
          "panel": {
            "color": "#808080",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#6e341a",
            "decimal_places": 0,
            "icon": "",
            "size": "48px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Messtelle Kettwig nah an DUS Station 14 (filtriert auf  Überflüge)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 0,
            "sizeX": 1,
            "sizeY": 6
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "refresh_interval": 0,
            "size": "40px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "image_url": "https://gemeinsam-fuer-stadtwandel.de/wp-content/uploads/2022/07/BgF_Logo.png",
              "source": "image_url",
              "value": "Bürger gegen Fluglärm"
            }
          ],
          "type": "image"
        },
        {
          "layout": {
            "col": 11,
            "row": 17,
            "sizeX": 1,
            "sizeY": 2
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "type": "none"
            },
            "title": "Lden"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 2,
            "icon": "",
            "size": "40px",
            "unit": "dB",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "Lden",
                "property": "lequ",
                "user": "LO1Noisewatch"
              },
              "source": "device_property",
              "timespan": {
                "mode": "latest"
              }
            }
          ],
          "type": "text"
        }
      ]
    }
  ],
  "widgets": [],
  "placeholders": {
    "sources": []
  }
}
