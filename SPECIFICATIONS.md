### Message Specs

## Types

### TaskUUID

UUID string

Equal to the offenderID in the meta data.

### ToolID

String with one of the following values

Launcher: `ivisCore`  

VideoWall: `ivisReplay`  

GeoMap: `ivisGeoMap`  

Search: `ivisSearch`  

Report/Cutter: `ivisReport`  

PhantomFace: `ivisPhantomFace3D`  

### File Paths

File paths should be relative to VideoDBRoot or TaskDBRoot

### Timestamp

Timestamp in ISO 8601 with Ms

### MugTimeInterval

```
{
  "start": Timestamp,
  "end", Timestamp
}
```

### MugRectangle
```
{
    "width": Unsigned Integer,
    "height": Unsigned Integer,
    "x": Unsigned Integer,
    "y": Unsigned Integer
}
```

## Messages

### setGlobalTimestamp

* timestamp: Timestamp
* toolID: String

Example:
```
{
    "timestamp": "2017-05-08T12:02:40.025",
    "toolID": "ivisReplay"
}
```

### setActiveTask

* taskUUID: String
* toolID: String

Example:
```
{
    "taskUUID": "{983930c1-64c2-4279-9f41-81b0f5f7d80e}",
    "toolID: "ivisReport"
}
```

### setCameraSelected

* cameraID: String
* selected: bool
* toolID: String

Example:
```
{
    "cameraID": "cam1",
	"selected": false,
    "toolID: "ivisReport"
}
```

### addNewItemToCut

* path: path relative to videodb for bounded absolute for single 
* timeInterval: MugTimeInterval
* roiRect: MugRectangle (optional, only in combination with type = "single")
* timestamp: String
* type: ClipType {"bounded", "single"}
* toolID: String

Example:
```
{
   "path": "SampleSequence",
   "timeInterval": {
       "end": "2017-05-08T12:04:48.500",
       "start": "2017-05-08T11:59:10.093"
   },
   "roiRect": {
        "height": 720,
        "width": 1280,
        "x": 0,
        "y": 0
    },
   "timestamp": "2017-05-08T12:00:00.300",
   "type": bounded",
   "toolID": "ivisReplay"
}
```

### addFileImageToSearch

* image: absoulte path
* roiRect: MugRectangle
* toolID: String

Example:
```
{
  "image": "Home/DB/Bildsequenz/00012.MTS___muskat1___2017-05-08_12-02-39-993.png"
  "roiRect": {
    "height": 12,
    "width": 12,
    "x": 95,
    "y": 64
   },
  "toolID": "ivisReplay"
}
```

### requestInitMUSKAT

* toolID: String

Example:
```
{
  "toolID": "ivisReplay"
}
```

### initMUSKAT

* taskDBPath: String
* videoDBPath: String
* targetToolID: String
* toolID: String

Example:
```
{
  "taskDBPath": ".../TaskDatabase",
  "videoDBPath": ".../VideoDatabase",
  "targetToolID": "ivisReplay",
  "toolID": "ivisCore"
}
```

### updateTimeInterval

* timeInterval: MugTimeInterval
* toolID: String

Example:
```
{
  "timeInterval":  {
    "start": "2017-04-11T09:52:56.142Z",
    "end": "2017-04-11T09:52:56.142Z"
  },
  "toolID": "ivisCore"
}
```

### updateSelectedCameraList

* cameraIDs: Array of String
* selected: Array of bool
* toolID: String

Example:
```
{
  "cameraIDs": ["cam1", "cam2"],
  "selected": [true, false],
  "toolID": "ivisCore"
}
```

### displayROI

* timestamp: Timestamp
* cameraID: String
* roi_rect: MugRect
* toolID: String

Example:
```
{
    "timestamp": "2017-04-11T09:52:56.142Z",
    "cameraID": "Cam170",
    "roi_rect": {
    "height": 12,
    "width": 12,
    "x": 95,
    "y": 64
   },
   toolID: "ivisSearch"
}
```

### rememberGlobalTimestamp

* Message to ivisCore Dashboard
*
* note: String
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"note": "Important Moment!",
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### rememberTimeInterval

* Message to ivisCore Dashboard
*
* note: String
* timeInterval: MugTimeInterval
* toolID: String

Example:
```
{
	"note": "This could be an important period of time.",
    "timeInterval":  {
		"start": "2017-04-11T09:52:56.142Z",
		"end": "2017-04-11T09:52:56.142Z"
	},
    "toolID": "ivisCore"
}
```

### rememberFileImageToSearch

* Message to ivisCore Dashboard
*
* note: String
* image: String
* roiRect: MugRect
* toolID: String

Example:
```
{
	"note": "Image important for Task XY",
	"image": "Home/DB/Bildsequenz/00012.MTS_muskat1_2017-05-08_12-02-39-993.png",
	"roiRect": {
    "height": 12,
    "width": 12,
    "x": 95,
    "y": 64
	},
    "toolID": "ivisReplay"
}
```

### rememberCameraID

* Message to ivisCore Dashboard
*
* note: String
* timestamp: Timestamp
* cameraID: String
* toolID: String

Example:
```
{
	"note": "This could be an important period of time.",
    "timestamp": "2017-04-11T09:52:56.142Z",
	"cameraID": "MyCamera",
    "toolID": "ivisReplay"
}
```

### rememberGeoROI

* Message to ivisCore Dashboard
*
* note: String
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"note": "This could be an important period of time.",
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### addCameraToMap

* Message to ivisGeoMap
*
* cameraCaption: String
* cameraDescription: String
* cameraID: String
* cameraIsStatic: Bool (atm unused)
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"cameraCaption": "This is camera 1.",
	"cameraDescription": "Camera facing north",
	"cameraID":"cam1",
	"cameraIsStatic": false,
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### removeCameraFromMap

* Message to ivisGeoMap
*
* cameraID: String
* toolID: String

Example:
```
{
	"cameraID": "cam1",
    "toolID": "ivisReplay"
}
```

### updateCameraStatus

* Message to ivisGeoMap
*
* cameraID: String
* cameraIsStatic: Bool (atm unused)
* extrinsicsFile: String
* intrinsicsFile: String
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"cameraID": "cam1",
	"cameraIsStatic": false,
	"extrinsicsFile": "C:\\DebugCam.MTS___muskat1___2017-05-08_12-02-39-993.yml",
	"intrinsicsFile": "C:\\Cam170.MTS___muskat1___2017-08-24_12-49-07-500.xml",
	"timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### addObjectToMap

* Message to ivisGeoMap
*
* objectCaption: String
* objectClass: String
* objectDescription: String
* objectID: String
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"objectCaption": "Human1",
	"objectClass": "Human",
	"objectDescription":"This is a friendly human.",
	"objectID": "Object1",
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### updateObjectStatus

* Message to ivisGeoMap
*
* objectID: String
* isMotionInfoAvailable: String
* isUncertaintyAvailable: String
* hDatum: String
* position:
    x: Double
    y: Double
    z: Double
* motion:
    dt: Double
    dx: Double
    dy: Double
    dz: Double
* uncertainty:
    ux: Double
    uy: Double
    uz: Double
* toolID: String

Example:
```
{
	"objectID":"Object1",
	"isMotionInfoAvailable": true,
	"isUncertaintyAvailable": false,
	"hDatum": "+proj=utm +zone=32 +datum=WGS84 +units=m +no_defs",
	"position":
	{
		"x": 553969.5516012239,
		"y": 5613777.711541116,
		"z": 263
	},
	"motion": 
	{
		"dt": 1,
		"dx": 1.8878173828125,
		"dy": -1.42138671875,
		"dz": 0.0
	},
	"uncertainty":
	{
		"ux":0.1,
		"uy":0.1,
		"uz":0.1
	},
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### removeObjectToMap

* Message to ivisGeoMap
*
* objectID: String
* timestamp: Timestamp
* toolID: String

Example:
```
{
	"objectID": "Object1",
    "timestamp": "2017-04-11T09:52:56.142Z",
    "toolID": "ivisReplay"
}
```

### setGeoRegionOfInterest

* Message from ivisGeoMap
*
* roiWidthEasting: Double
* roiHeightNorthing: Double
* roiAltitude: Double
* hDatum: String
* x: Double
* y: Double
* z: Double

Example:
```
{
	"roiWidthEasting": 53.7277260879,
	"roiHeightNorthing": -51.9469799129,
	"roiAltitude": 252.824,
	"hDatum": "+proj=utm +zone=32 +datum=WGS84 +units=m +no_defs ",
	"x": 553854.837216432,
	"y": 5613829.336558807,
	"z": 252.824
}
```