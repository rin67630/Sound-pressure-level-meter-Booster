{
	"controls": {
		"aggregation": {
			"auto": true,
			"period": "1m"
		},
		"hide_hours_picker": true,
		"timespan": {
			"mode": "relative",
			"period": "latest",
			"value": 2,
			"magnitude": "day"
		}
	},
	"description": "Overview  (by the minute)",
	"name": "Configurable Dashboard",
	"placeholders": {
		"sources": []
	},
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
			"name": "Daily Summary",
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
								"device": "DEVCNAME        ",
								"mapping": "17h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#c2e7fa",
						"showOffline": {
							"type": "none"
						},
						"title": "Night"
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
								"device": "DEVCNAME        ",
								"mapping": "Nighttime",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "22h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "05h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "04h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "03h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "02h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "01h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "16h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "15h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "14h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "12h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "21h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "10h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "09h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "08h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "07h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						},
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
								"device": "DEVCNAME        ",
								"mapping": "06h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "20h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": "last one at..."
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "18h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "13h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#ffffff",
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
							"value": "Equivalent Sound Level Leq (per hour)"
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
						"currentColor": "#ffffff",
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
							"value": "Number Above Treshold (NAT)"
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
								"device": "DEVCNAME        ",
								"mapping": "00h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "21h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "04h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "03h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "02h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "01h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "23h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "05h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "10h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "09h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "08h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "07h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "06h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "17h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "16h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "15h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "14h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "13h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "12h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "18h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "20h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "22h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "00h",
								"property": "NATu",
								"user": "CLOUDNAM        "
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
					"$loadAttemps": 300,
					"layout": {
						"col": 0,
						"row": 5,
						"sizeX": 11,
						"sizeY": 22
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						},
						"title": ""
					},
					"properties": {
						"axis": true,
						"fill": true,
						"legend": false,
						"multiple_axes": false
					},
					"sources": [
						{
							"$timespan": {
								"magnitude": "minute",
								"mode": "configurable",
								"value": 15
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "Bat%",
								"tags": {},
								"user": "CLOUDNAM        "
							},
							"color": "#fdfbff",
							"device": {
								"id": "DEVCNAME        ",
								"interval": 20,
								"mapping": "limit",
								"resource": "noise",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"name": "Limit",
							"skipCurrent": 20,
							"source": "value",
							"timespan": {
								"magnitude": "day",
								"mode": "relative",
								"period": "latest",
								"value": 2
							},
							"value": 85
						},
						{
							"$timespan": {
								"magnitude": "minute",
								"mode": "configurable",
								"value": 15
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "LEtr",
								"tags": {},
								"user": "CLOUDNAM        "
							},
							"color": "#3e1505",
							"device": {
								"id": "DEVCNAME        ",
								"interval": 1,
								"mapping": "slow",
								"resource": "noise",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"name": "Slow db(A)",
							"skipCurrent": 1,
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "relative",
								"period": "latest",
								"value": 24
							}
						},
						{
							"$timespan": {
								"magnitude": "minute",
								"mode": "configurable",
								"value": 15
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "backgr",
								"tags": {},
								"user": "CLOUDNAM        "
							},
							"color": "#e5e852",
							"device": {
								"id": "DEVCNAME        ",
								"mapping": "backgr",
								"resource": "noise",
								"user": "CLOUDNAM        "
							},
							"name": "Background",
							"source": "bucket",
							"timespan": {
								"magnitude": "hour",
								"mode": "relative",
								"period": "latest",
								"value": 24
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
						"currentColor": "#dcdfdc",
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
							"value": "Day stats"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": "..."
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Last Peak Event Detected"
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
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"row": 12,
						"sizeX": 1,
						"sizeY": 3
					},
					"panel": {
						"color": "#1dc40f",
						"colors": [
							{
								"color": "#ff0000",
								"max": 11.5,
								"min": 0
							},
							{
								"color": "#ffff00",
								"max": 12,
								"min": 11.5
							}
						],
						"currentColor": "#1dc40f",
						"showOffline": {
							"type": "none"
						},
						"title": "Battery"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "40px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "DEVCNAME        ",
								"interval": 1,
								"mapping": "voltage",
								"resource": "energy",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": "NAT in Hour"
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": "Peak"
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": "> Max-10dB for..."
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#d0ffd5",
						"showOffline": {
							"type": "none"
						},
						"title": ">58dB for..."
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
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "19h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"id": "DEVCNAME        ",
								"interval": 1,
								"mapping": "impulse",
								"resource": "noise",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#fdffc5",
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
								"id": "DEVCNAME        ",
								"interval": 5,
								"mapping": "backgr",
								"resource": "noise",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "23h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
								"device": "DEVCNAME        ",
								"mapping": "Daytime",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"currentColor": "#fdffc5",
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
							"value": "Current"
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
								"device": "DEVCNAME        ",
								"mapping": "Day",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"sizeY": 2
					},
					"panel": {
						"color": "#7f7f7f",
						"currentColor": "#7f7f7f",
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
							"value": "Background"
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
								"device": "DEVCNAME        ",
								"mapping": "L22-24h",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"sizeX": 2,
						"sizeY": 10
					},
					"panel": {
						"color": "#dddddd",
						"currentColor": "#dddddd",
						"showOffline": {
							"type": "none"
						},
						"title": "Temperature"
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
								"device": "DEVCNAME        ",
								"mapping": "temperature",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 41,
						"sizeX": 2,
						"sizeY": 10
					},
					"panel": {
						"color": "#dddddd",
						"currentColor": "#dddddd",
						"showOffline": {
							"type": "none"
						},
						"title": "Air Pressure"
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
								"device": "DEVCNAME        ",
								"mapping": "pressure",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 41,
						"sizeX": 2,
						"sizeY": 10
					},
					"panel": {
						"color": "#dddddd",
						"currentColor": "#dddddd",
						"showOffline": {
							"type": "none"
						},
						"title": "Rel. Humidity"
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
								"device": "DEVCNAME        ",
								"mapping": "humidity",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 41,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"timespan": {
								"magnitude": "minute",
								"value": 15
							},
							"type": "timespan"
						},
						"showTs": true,
						"title": "Wind Direction"
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
								"device": "DEVCNAME        ",
								"mapping": "direction",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 46,
						"sizeX": 2,
						"sizeY": 5
					},
					"panel": {
						"color": "#dddddd",
						"currentColor": "#dddddd",
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
						"size": "48px",
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
								"device": "DEVCNAME        ",
								"mapping": "summary",
								"property": "persistance",
								"user": "CLOUDNAM        "
							},
							"name": "Default",
							"source": "value",
							"value": "Weather Station Kettwig"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 46,
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
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						},
						"title": "Wind Speed"
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
								"device": "DEVCNAME        ",
								"mapping": "wind",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 41,
						"sizeX": 3,
						"sizeY": 5
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"timespan": {
								"magnitude": "minute",
								"value": 15
							},
							"type": "timespan"
						},
						"showTs": true,
						"title": "Weather"
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
								"device": "DEVCNAME        ",
								"mapping": "summary",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"row": 41,
						"sizeX": 2,
						"sizeY": 5
					},
					"panel": {
						"color": "#242424",
						"currentColor": "#242424",
						"showOffline": {
							"type": "none"
						},
						"title": "Clock (local time)"
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
								"device": "DEVCNAME        ",
								"mapping": "summary",
								"property": "persistance",
								"user": "CLOUDNAM        "
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
						"sizeX": 6,
						"sizeY": 2
					},
					"panel": {
						"color": "#7f7f7f",
						"currentColor": "#7f7f7f",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ffffff",
						"decimal_places": 0,
						"icon": "",
						"size": "36px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Measuring values (1 minute, timeline configurable)"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 3,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#7f7f7f",
						"currentColor": "#7f7f7f",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#674918",
						"decimal_places": 0,
						"icon": "",
						"size": "36px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Slow"
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
								"device": "DEVCNAME        ",
								"mapping": "Lden",
								"property": "lequ",
								"user": "CLOUDNAM        "
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
						"row": 46,
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
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						},
						"title": "Wind Speed"
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
								"device": "DEVCNAME        ",
								"mapping": "wind",
								"property": "persistance",
								"user": "CLOUDNAM        "
							},
							"name": "Default",
							"source": "device_property"
						}
					],
					"type": "progressbar"
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
						"currentColor": "#fdffc5",
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
								"id": "DEVCNAME        ",
								"interval": 1,
								"mapping": "slow",
								"resource": "noise",
								"update": "interval",
								"user": "CLOUDNAM        "
							},
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "11h",
								"property": "lequ",
								"user": "CLOUDNAM        "
							},
							"skipCurrent": 1,
							"source": "device",
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
	"widgets": []
}
