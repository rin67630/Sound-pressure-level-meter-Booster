{
	"description": "Summary Dashboard",
	"name": "Summary Dashboard",
	"properties": {
		"border_radius": "10px",
		"columns": 12,
		"row_height": 40,
		"show_template": true
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "Summary Dashboard",
			"widgets": [
				{
					"layout": {
						"col": 0,
						"row": 12,
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
						"size": "50px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Hourly Battery Charge Status"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 6,
						"sizeX": 12,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "50px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Hourly Lequ (Steady Noise Level Equivalent, ongoing)"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 12,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "50px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Hourly NAT (Number Above Threshold, ongoing)"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 18,
						"sizeX": 12,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "50px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"source": "value",
							"value": "Midnight Rec: Lequ  ,  Lden (Level DayEveningNight)  ,   NAT  ,   Battery"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "03h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "00h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "01h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "21h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "01h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "02h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "00h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "06h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "06h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "21h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "04h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "23h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "06h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "07h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "08h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "09h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "10h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "11h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "12h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "13h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "14h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "15h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "16h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "17h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#b8cded",
						"title": "Lden"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "19h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "20h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "05h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "22h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "02h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "03h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "04h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "23h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "NAT Daytime"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "Daytime",
								"property": "NATu",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "07h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "08h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "09h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "10h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "11h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "12h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "13h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "14h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "15h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "16h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "17h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "18h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "19h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "20h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "05h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "NAT 22-24h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "NAT22-24",
								"property": "NATu",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#b7eaa2",
						"colors": [],
						"currentColor": "#b7eaa2",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Battery voltage"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "v",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "BluSCC",
								"interval": 60,
								"mapping": "BatV",
								"resource": "measure",
								"update": "interval"
							},
							"device_property": {
								"device": "BluSCC",
								"mapping": "voltageDelta",
								"property": "persistance",
								"user": "CLOUDNAM        "
							},
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "18h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "Leq Day (24h)"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "Leq Daytime"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "Leq Nighttime"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "Leq 22-24h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "06h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "NAT (24h)"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "Day",
								"property": "NATu",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "22h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#8db0e2",
						"title": "NAT Nightime"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "25px",
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
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "Bat Today"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "Today",
								"property": "BAT",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#dfe9f7",
						"title": "Bat Yesterdy"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "DEVCNAME        ",
								"mapping": "Yesterday",
								"property": "BAT",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "22h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "22h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "00h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "00h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "01h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "01h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "02h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "02h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "03h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "03h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "04h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "04h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "07h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "07h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "08h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "08h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "09h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "09h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 10,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "10h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "10h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "11h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "11h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 9,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "21h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "21h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "12h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "12h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "13h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "13h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "14h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "14h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "15h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "15h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "16h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "16h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "17h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "17h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "18h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "18h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "19h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "19h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#d9f2d9",
						"currentColor": "#d9f2d9",
						"showOffline": {
							"type": "none"
						},
						"title": "20h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "20h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 11,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "23h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "23h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#95db95",
						"currentColor": "#95db95",
						"showOffline": {
							"type": "none"
						},
						"title": "05h"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "25px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "BluSCC",
								"mapping": "05h",
								"property": "statVh",
								"user": "CLOUDNAM        "
							},
							"source": "device_property"
						}
					],
					"type": "text"
				}
			]
		}
	],
	"widgets": [
		{
			"data": {
				"source": "value",
				"value": "Hourly Battery Load Balance (ongoing)"
			},
			"layout": {
				"col": 0,
				"row": 12,
				"sizeX": 12,
				"sizeY": 2
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "50px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"source": "value",
				"value": "Hourly Lequ (Steady Noise Level Equivalent, ongoing)"
			},
			"layout": {
				"col": 0,
				"row": 6,
				"sizeX": 12,
				"sizeY": 2
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "50px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"source": "value",
				"value": "Hourly NAT (Number Above Threshold, ongoing)"
			},
			"layout": {
				"col": 0,
				"row": 0,
				"sizeX": 12,
				"sizeY": 2
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "50px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"source": "value",
				"value": "Midnight Rec: Lequ  ,  Lden (Level DayEveningNight)  ,   NAT  ,   Battery"
			},
			"layout": {
				"col": 0,
				"row": 18,
				"sizeX": 12,
				"sizeY": 2
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "50px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "03h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "03h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "00h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "00h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "01h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "01h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "21h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "21h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "01h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "01h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "04h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "04h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "02h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "02h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "00h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "00h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "00h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "00h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "01h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "01h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "02h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "02h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "21h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "21h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "03h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "03h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "04h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "04h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "23h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "23h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "06h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "06h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "07h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "07h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "08h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "08h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "09h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "09h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "10h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "10h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "11h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "11h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "12h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "12h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "13h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "13h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "14h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "14h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "23h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "23h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "05h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "05h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "15h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "15h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "16h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "16h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "17h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "17h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Lden",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#b8cded",
				"title": "Lden"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "19h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "19h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "20h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "20h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "05h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 8,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "05h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "22h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "22h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "02h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "02h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "03h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "03h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "04h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "04h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "23h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "23h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Daytime",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "NAT Daytime"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "07h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "07h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "08h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "08h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "09h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "09h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "10h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "10h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "11h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "11h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "12h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "12h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "13h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "13h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "14h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "14h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "15h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "15h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "16h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "16h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "17h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "17h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "18h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "18h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "19h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "19h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "20h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "20h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "05h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "05h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "NAT22-24",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "NAT 22-24h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "06h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "06h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "voltageDelta",
					"property": "persistance",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#b7eaa2",
				"colors": [],
				"title": "Volt Delta@4h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "v",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "08h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "08h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "09h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "09h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "10h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "10h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "11h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "11h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "12h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "12h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "13h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "13h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "14h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "14h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "15h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 3,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "15h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "16h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "16h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "17h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "17h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "18h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "18h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "19h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "19h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "20h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 8,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "20h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "21h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 9,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "21h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "22h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 16,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "22h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "18h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 10,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "18h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Day",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 4,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "Leq Day (24h)"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Daytime",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 0,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "Leq Daytime"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Nighttime",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 1,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "Leq Nighttime"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "L22-24h",
					"property": "lequ",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 2,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "Leq 22-24h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "dB",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "05h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 6,
				"row": 2,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "06h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Day",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 5,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "NAT (24h)"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "22h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 4,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "22h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "22h",
					"property": "NATu",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#8db0e2",
				"title": "NAT Nightime"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 0,
				"icon": "",
				"size": "25px",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "07h",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 7,
				"row": 14,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "07h"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Today",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 10,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "Bat Today"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device_property": {
					"device": "DEVCNAME        ",
					"mapping": "Yesterday",
					"property": "BAT",
					"user": "CLOUDNAM        "
				},
				"source": "device_property"
			},
			"layout": {
				"col": 11,
				"row": 20,
				"sizeX": 1,
				"sizeY": 2
			},
			"panel": {
				"color": "#dfe9f7",
				"title": "Bat Yesterdy"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "25px",
				"unit": "Ah",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		}
	],
	"placeholders": {
		"sources": []
	}
}
