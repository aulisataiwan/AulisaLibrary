# Requirement
iOS 11

## Installation
Swift Package Manager 

https://github.com/aulisataiwan/AulisaLibrary

# Usage

## Connection

  Scan Bluetooth Device in your Bluetooth Manager : 

      oxiDevice = AUOximeter(peripheral: CBPeripheral, macAddress: mac)
      oxiDevice.delegate = oxiDelegate

  And wait for 

      func didSMConnect(device : AUOximeter)

  is called 

## Baby Sensor Connection

  After 

      func didSMConnect(device : AUOximeter)

  is called , you need to call 

      func getOxi1001Info(type : AUProbeType = .None)
       
  to get vital data



## AUOximeter
      
### Variables

      public var delegate : AUOximeterDataDelegate?
      public private(set) var macAddress : String!
      public private(set) var alarmLimit : AUOximeterAlarmLimit!
      public private(set) var sensorType : AUSensorType!
      public private(set) var sensorGeneration : AUSensorGeneration  
      public private(set) var version : String!
      
### Functions

      public func isConnected() -> Bool
      public func isPowerOff() -> Bool
      public func setAlarmLimit(alarmLimit : AUOximeterAlarmLimit
      public func setProbeType(_ type : AUProbeType)
      public func getOxi1001Info(type : AUProbeType = .None)
      public func stopOxi1001Info()
      public func getRawData(
      public func stopRawData()
      public func currentData() -> AUOximeterData?
      
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
