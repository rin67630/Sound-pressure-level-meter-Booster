{
  "controls": {
    "aggregation": {
      "auto": true,
      "period": "1m"
    },
    "hide_hours_picker": true,
    "timespan": {
      "magnitude": "hour",
      "mode": "relative",
      "period": "latest",
      "value": 24
    }
  },
  "description": "Kettwig V.d.B.   Echtzeit Sekundentakt",
  "name": "Kettwig V.d.B.  Echtzeit (Sekundentakt)",
  "properties": {
    "background_image": "#888888",
    "border_radius": "10px",
    "columns": 12,
    "row_height": 40,
    "show_template": false
  },
  "tabs": [
    {
      "icon": "fas fa-tachometer-alt",
      "name": "TAGESSTATISTIK",
      "widgets": [
        {
          "layout": {
            "col": 5,
            "row": 41,
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
            "row": 41,
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
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "col": 4,
            "row": 41,
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
            "row": 41,
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
            "row": 41,
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
            "row": 41,
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
            "row": 41,
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
            "row": 9,
            "sizeX": 1,
            "sizeY": 3
          },
          "panel": {
            "color": "#fdffc5",
            "showOffline": {
              "type": "none"
            },
            "title": "Vergleich"
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
            "col": 10,
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "row": 39,
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
            "row": 41,
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
            "row": 41,
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
            "row": 41,
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
            "row": 37,
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
              "value": "Äquivalenter Dauerschallpegel  pro Stunde (Laufend)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 43,
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
              "value": "Erkannte Überflüge pro Stunde (Laufend)"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 39,
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
            "row": 47,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 47,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 45,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "row": 47,
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
            "col": 0,
            "row": 45,
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
              "color": "#fdfbff",
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 20,
                "mapping": "limit",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "name": "Limit",
              "skipCurrent": 20,
              "source": "device",
              "timespan": {
                "magnitude": "minute",
                "mode": "configurable",
                "value": 15
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
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "slow",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "name": "Slow db(A)",
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "magnitude": "minute",
                "mode": "configurable",
                "value": 15
              }
            },
            {
              "bucket": {},
              "color": "#edd7b0",
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "interval": 1,
                "mapping": "impulse",
                "resource": "noise",
                "update": "interval",
                "user": "LO1Noisewatch"
              },
              "name": "Compare",
              "skipCurrent": 1,
              "source": "device",
              "timespan": {
                "magnitude": "minute",
                "value": 15
              }
            },
            {
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "backgr",
                "tags": {},
                "user": "LO1Noisewatch"
              },
              "color": "#e5e852",
              "device": {
                "id": "SWISS_ARMY_KNIFE",
                "mapping": "backgr",
                "resource": "noise",
                "user": "LO1Noisewatch"
              },
              "name": "Background",
              "source": "device",
              "timespan": {
                "magnitude": "minute",
                "mode": "latest",
                "value": 15
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
              "value": "Tageswerte"
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
              "mjpeg_url": "https://gemeinsam-fuer-stadtwandel.de/wp-content/uploads/2022/07/BgF_Logo.png",
              "source": "mjpeg_url",
              "value": "Meerbusch Büderich"
            }
          ],
          "type": "image"
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
            "row": 39,
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
            "row": 6,
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
            "row": 41,
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
            "title": "Leq (Max-10dB)"
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
            "row": 12,
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
            "row": 3,
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
                "interval": 5,
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
            "row": 41,
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
              "value": "Messwerte"
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
            "row": 49,
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
            "color": "#7f7f7f",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#fef837",
            "decimal_places": 0,
            "icon": "",
            "size": "36px",
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
            "col": 0,
            "row": 27,
            "sizeX": 2,
            "sizeY": 10
          },
          "panel": {
            "color": "#dddddd",
            "showOffline": {
              "type": "none"
            },
            "title": "Temperatur"
          },
          "properties": {
            "majorTicks": 10,
            "max": 40,
            "min": -10,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "°C"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "temperature",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "tachometer"
        },
        {
          "layout": {
            "col": 2,
            "row": 27,
            "sizeX": 2,
            "sizeY": 10
          },
          "panel": {
            "color": "#dddddd",
            "showOffline": {
              "type": "none"
            },
            "title": "Barom. Druck"
          },
          "properties": {
            "majorTicks": 50,
            "max": 1100,
            "min": 900,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "mBar"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "pressure",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "tachometer"
        },
        {
          "layout": {
            "col": 4,
            "row": 27,
            "sizeX": 2,
            "sizeY": 10
          },
          "panel": {
            "color": "#dddddd",
            "showOffline": {
              "type": "none"
            },
            "title": "Rel Feuchtigkeit"
          },
          "properties": {
            "majorTicks": 10,
            "max": 100,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "%"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "humidity",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "tachometer"
        },
        {
          "layout": {
            "col": 6,
            "row": 27,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "timespan": {
                "magnitude": "minute",
                "value": 15
              },
              "type": "timespan"
            },
            "showTs": true,
            "title": "Windrichtung"
          },
          "properties": {
            "color": "#081fbf",
            "majorTicks": 1,
            "max": 360,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "deg"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "direction",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "donutchart"
        },
        {
          "layout": {
            "col": 10,
            "row": 32,
            "sizeX": 2,
            "sizeY": 5
          },
          "panel": {
            "color": "#dddddd",
            "showOffline": {
              "type": "none"
            },
            "title": "OpenWeatherMap.org"
          },
          "properties": {
            "color": "#2f3afc",
            "decimal_places": 0,
            "icon": "",
            "iconSize": 96,
            "majorTicks": 1,
            "max": 15,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "size": "64px",
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "summary",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "value",
              "value": "Wetterstation Lohausen"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 32,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#ffffff",
            "colors": [
              {
                "color": "#b3ffc5",
                "max": 5,
                "min": 0
              },
              {
                "color": "#fdfa9a",
                "max": 15,
                "min": 5
              },
              {
                "color": "#fc0916",
                "max": 25,
                "min": 15
              }
            ],
            "showOffline": {
              "type": "none"
            },
            "title": "Windstärke"
          },
          "properties": {
            "color": "#1d2f9b",
            "decimal_places": 1,
            "gradient": true,
            "icon": "",
            "iconSize": 64,
            "majorTicks": 1,
            "max": 20,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "size": "100px",
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "m/s",
            "unit_size": "20px",
            "weight": "font-normal"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "wind",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 7,
            "row": 27,
            "sizeX": 3,
            "sizeY": 5
          },
          "panel": {
            "color": "#ffffff",
            "showOffline": {
              "timespan": {
                "magnitude": "minute",
                "value": 15
              },
              "type": "timespan"
            },
            "showTs": true,
            "title": "Wetter"
          },
          "properties": {
            "color": "#293499",
            "decimal_places": 0,
            "icon": "",
            "iconSize": 96,
            "majorTicks": 1,
            "max": 15,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "size": "64px",
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-normal"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "summary",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 10,
            "row": 27,
            "sizeX": 2,
            "sizeY": 5
          },
          "panel": {
            "color": "#242424",
            "showOffline": {
              "type": "none"
            },
            "title": "Jetzt ist..."
          },
          "properties": {
            "color": "#15f037",
            "decimal_places": 0,
            "icon": "",
            "iconSize": 96,
            "majorTicks": 1,
            "max": 15,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "size": "75px",
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "summary",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "clock"
        },
        {
          "layout": {
            "col": 1,
            "row": 3,
            "sizeX": 5,
            "sizeY": 3
          },
          "panel": {
            "color": "#7f7f7f",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#502612",
            "decimal_places": 0,
            "icon": "",
            "size": "36px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Messtelle Kettwig V.d.B.   nah an DUS Station 14"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 6,
            "row": 3,
            "sizeX": 3,
            "sizeY": 3
          },
          "panel": {
            "color": "#7f7f7f",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "color": "#edd8b4",
            "decimal_places": 0,
            "icon": "",
            "size": "36px",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "source": "value",
              "value": "Vergleich:  Kettwig Schmachtenb."
            }
          ],
          "type": "text"
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
        },
        {
          "layout": {
            "col": 7,
            "row": 32,
            "sizeX": 3,
            "sizeY": 5
          },
          "panel": {
            "color": "#ffffff",
            "colors": [
              {
                "color": "#b3ffc5",
                "max": 5,
                "min": 0
              },
              {
                "color": "#fdfa9a",
                "max": 15,
                "min": 5
              },
              {
                "color": "#fc0916",
                "max": 25,
                "min": 15
              }
            ],
            "showOffline": {
              "type": "none"
            },
            "title": "Windstärke                      ( Grün: Landerichtung beliebig,              Gelb: Landerichtung vorgegeben,          Rot: zu windig für Messtelle)"
          },
          "properties": {
            "icon": "",
            "iconSize": 64,
            "majorTicks": 1,
            "max": 20,
            "min": 0,
            "plateColor": "#ffffff",
            "showValue": true,
            "textColor": "#1E313E",
            "tickColor": "#000000",
            "unit": "m/s"
          },
          "sources": [
            {
              "color": "#1E313E",
              "device_property": {
                "device": "SWISS_ARMY_KNIFE",
                "mapping": "wind",
                "property": "persistance",
                "user": "LO1Noisewatch"
              },
              "name": "Default",
              "source": "device_property"
            }
          ],
          "type": "progressbar"
        }
      ]
    }
  ],
  "widgets": [],
  "placeholders": {
    "sources": []
  }
}
