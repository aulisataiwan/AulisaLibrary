- [**Requirement**](#requirement)
- [**Installation**](#installation)
- [**Oximeter Usage**](#oximeter-usage)
  - [Connection](#connection)
  - [Baby Connection](#baby-sensor-connection)
  - [AUOximeter](#auoximeter)
  - [AUOximeterDataDelegate](#auoximeterdatadelegate)
  - [AUOximeterData](#auoximeterdata)
  - [AUOximeterAlarmLimit](#auoximeteralarmlimit)
  - [AUOximeterRawData](#auoximeterrawdata)
- [**Thermometer Usage**](#thermometer-usage)
  - [Connection](#connection-1)
  - [AUThermometer](#authermometer)
  - [AUThremometerDataDelegate](#authermometerdatadelegate)
  - [AUTemperatureData](#autemperaturedata)
  - [AUTemperatureAlarmLimit](#autemperaturealarmlimit)
- [**ECG Usage**](#ecg-usage)
  - [Connection](#connection-2)
  - [AUECGDevice](#auecgdevice)
  - [AUECGDataDelegate](#auecgdatadelegate)
  - [AUECGData](#auecgdata)
  - [AUECGAlarmLimit](#auecglimit)
  - [AUECGRawData](#auecgrawdata)


- [**Example**](#example)

# Requirement
**iOS 11**

# Installation <br>
Swift Package Manager 

https://github.com/aulisataiwan/AulisaLibrary

# Oximeter Usage
  
## Connection <br><br>
   Scan Bluetooth Device in your Bluetooth Manager : 

      oxiDevice = AUOximeter(peripheral: CBPeripheral, macAddress: mac)
      oxiDevice.delegate = oxiDelegate

  And wait for 

      func didSMConnect(device : AUOximeter)


## Baby Sensor Connection <br><br>

  After 

      func didSMConnect(device : AUOximeter)

  is called , you need to call 

      func getOxi1001Info(type : AUProbeType = .None)
       
  to get vital data
  <br><br>

## AUOximeter
      
      public var delegate : AUOximeterDataDelegate?
      public private(set) var macAddress : String!
      public private(set) var sensorType : AUSensorType!
      public private(set) var sensorGeneration : AUSensorGeneration  
      public private(set) var version : String!
      public private(set) var alarmLimit : AUOximeterAlarmLimit!
      public func currentData() -> AUOximeterData?
      public func isConnected() -> Bool
      public func isPowerOff() -> Bool
      public func setAlarmLimit(alarmLimit : AUOximeterAlarmLimit)
      public func setProbeType(_ type : AUProbeType)
      public func getOxi1001Info(type : AUProbeType = .None)
      public func stopOxi1001Info()
      public func getRawData()
      public func stopRawData()

### Hardware & firmware info

      var macAddress   
      var sensorType : Adult(Oxi1000) or Baby(Oxi1001) Sensor
      var sensorGeneration : First or Second 
      var version : Firmware Version

### Current Data & Alarm Setting     
    
      func currentData()
      var alarmLimit
      func isConnected()
      func isPowerOff()

### Command <br><br>

  To Change Alarm Limit :  

      setAlarmLimit : 

  You will Have

    func notifyAlarmLimit(device : AUOximeter , alarmLimit : AUOximeterAlarmLimit)

  To get/stop baby sensor oxi info : 

      getOxi1001Info/stopOxi1001Info 

  To get/stop raw data (Only available on 2nd adult sensor):

      getRawData() / stopRawData() 
  
  To Change your sensor probe type (Infant/Pediatric): 

      setProbeType  
      
## AUOximeterDataDelegate

      func didSMConnect(device : AUOximeter)
      func didSMPowerOff(device : AUOximeter)
      func notifyInfo(device : AUOximeter , info : AUOximeterData) 
      func notifyAlarmLimit(device : AUOximeter , alarmLimit : AUOximeterAlarmLimit)
      func notifyRawData(device : AUOximeter , rawData : AUOximterRawData)


  When sensor is Ready
  
      func didSMConnect(device : AUOximeter)
      
  User Press the power button
  
      func didSMPowerOff(device : AUOximeter)

  Oximeter Vital Data
  
      func notifyInfo(device : AUOximeter , info : AUOximeterData)

  After user update Alarm Limit
  
      func notifyAlarmLimit(device : AUOximeter , alarmLimit : AUOximeterAlarmLimit)

  Oximeter Raw Data
  
      func notifyRawData(device : AUOximeter , rawData : AUOximeterRawData)

## AUOximeterData 
<br>
    
  Vital Sign <br>

    public private(set) var SpO2 : Int 
    public private(set) var PR : Int 
    public private(set) var PA : Double 
    public private(set) var batteryStatus : BatteryStatus = .Full
    public private(set) var systemState : Int
    public private(set) var motionCount : Int 
    public private(set) var isMotionData : Bool 

  Only in specific firmware version<br>

    public private(set) var rValue : Double 
    public private(set) var redGain : Int 
    public private(set) var irGain : Int 
    public private(set) var redCurrent : Int 
    public private(set) var irCurrent : Int 

  Is Valid Data<br>
    
     public func isInvalidData() -> Bool

  Is Empty Data<br>

    public func isNoneValueData() -> Bool

  System state<br>

    public func isPowerOff() -> Bool
    public func isSensorOff() -> Bool
    public func isFingerOff() -> Bool
    public func isPositionWrong() -> Bool

  Alarm State<br>

    public func isSpo2High() -> Bool
    public func isSpo2Low() -> Bool
    public func isPrHigh() -> Bool
    public func isPrLow() -> Bool

## AUOximeterAlarmLimit

    public var sensorType : AUSensorType
    public var spo2High : Int?
    public var spo2Low : Int?
    public var prHigh : Int?
    public var prLow : Int?

If any variable is nil , it means that alarm limit is off <br><br>

### Alarm Limit Range & Defulat Value <br>

|    | Adult  | Infant |
| :----: | :----: | :----:|
| SPO2_MAX DEFAULT | 100 | 100 |
| SPO_MAX RANGE | 85~100 | 85~100 |
| SPO2_MIN DEFAULT | 85 | 85 |
| SPO2_MIN RANGE | 50~95 | 50~95 |
| PR_MAX DEFAULT | 150 | 200 |
| PR_MAX RANGE | 70~275 | 70~275 |
| PR_MIN DEFAULT | 50 | 75 |
| PR_MIN RANGE | 30~110 | 30~110 |


## AUOximeterRawData
<br>

### Enable/Disable RawData

    AUOximeterDevice.getRawData()
    AUOximeterDevice.stopRawData()

### RawData Listener 
<br>
in AUOximeterDataDelegate 

    func notifyRawData(device : AUOximeter , rawData : AUOximeterRawData)

### RawData Format
<br>

**Data Type**

    WAVE_FORM_RED
    WAVE_FORM_IR

**Data Array**

    func toArrayList(waveFormType : Int) -> [Int]

# Thermometer Usage

## Connection 
<br>
 Scan Bluetooth Device in your Bluetooth Manager : 

      tempDevice = AUThermometer(peripheral: CBPeripheral, macAddress: mac)
      tempDevice.delegate = tempDelegate
       
And wait for 

      func didSMConnect(device : AUThermometer)

## AUThermometer

    public var delegate : AUThermometerDataDelegate?
    public private(set) var macAddress : String!
    public private(set) var alarmLimit : AUTemperatureAlarmLimit!
    public private(set) var version = ""
    public func currentData() -> AUTemperatureData?
    public func isConnected() -> Bool
    public func setAlarmLimit(alarmLimit : AUTemperatureAlarmLimit)

### Hardware & firmware info

      var macAddress   
      var version : Firmware Version

### Current Data & Alarm Setting     
    
      func currentData()
      var alarmLimit
      func isConnected()

### Command <br><br>

  To Change Alarm Limit :  

      setAlarmLimit : 

  You will Have

    func notifyAlarmLimit(device : AUThermometer , alarmLimit : AUTemperatureAlarmLimit)

## AUThermometerDataDelegate

    func didSMConnect(device : AUThermometer)
    func notifyInfo(device : AUThermometer , info : AUTemperatureData)
    func notifyAlarmLimit(device : AUThermometer , alarmLimit : AUTemperatureAlarmLimit)

  When sensor is Ready
  
      func didSMConnect(device : AUThermometer)
      
  Thermometer Vital Data
  
      func notifyInfo(device : AUThermometer , info : AUTemperatureData)

  After user update Alarm Limit
  
      func notifyAlarmLimit(device : AUThermometer , alarmLimit : AUTemperatureAlarmLimit)


## AUTemperatureData

**Vital Sign** <br>

    public private(set) var temperature : Double 
    public private(set) var batteryStatus : BatteryStatus 
    public private(set) var systemState : Int
    public var scale : Int

**Temperature Scale** <br>

    public static let SCALE_CELSIUS = 0;
    public static let SCALE_FAHRENHEIT = 1;

**Value** <br>
    
    public var getValueOfTemperature: String
    public var getValueOfScale : String

**Alarm & State** <br>

    public func isTempOutOfDisplayRange() -> Bool
    public func isTempHigh() -> Bool
    public func isTempLow() -> Bool

## AUTemperatureAlarmLimit

    public var tempHigh : Double?
    public var tempLow : Double?

If any variable is nil , it means that alarm limit is off <br><br>

# ECG Usage
## Connection 
## AUECGDevice
## AUECGDataDelegate
## AUECGData
## AUECGAlarmLimit
## AUECGRawData


# Example

https://github.com/aulisataiwan/AulisaLibraryDemo_iOS

