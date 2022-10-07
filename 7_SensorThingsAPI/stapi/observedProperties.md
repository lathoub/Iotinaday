# ObservedProperties

POST:
`http://<host>/FROST-Server/v1.0/ObservedProperties`

## Weighing Scale 
![HX711](res/HX711.png)

### ObservedProperty:
```javascript
{
  "name": "Weight",
  "description": "The force with which a body is attracted toward an astronomical body",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#Weight"
}
```

## Axis Compass Magnetometer  
![hmc5883](res/hmc5883.png)

### ObservedProperty:
```javascript
{
  "name": "Magnetic fields",
  "description": "Direction and the magnitude of Earth’s magnetic fields",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#MagneticField"
}
```

## Temperature and Humidity  
![am2320](res/am2320.png)

### ObservedProperty:
```javascript
{
  "name": "Humidity",
  "description": "Absolute humidity is the mass of water in a particular volume of air. It is a measure of the density of water vapor in an atmosphere",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#AbsoluteHumidity"
}
```

## Accelerometer  
![adxl345](res/adxl345.png)

### ObservedProperty:
```javascript
{
  "name": "Acceleration",
  "description": "Acceleration is the (instantaneous) rate of change of velocity",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#Acceleration"
}
```

## xxxx 
![MAX4466](res/MAX4466.png)

### ObservedProperty:
```javascript
{
  "name": "SignalStrength",
  "description": "Magnitude of the electric field",
  "definition": "http://www.qudt.org/qudt/owl/1.0.0/quantity/Instances.html#SignalStrength"
}
```

## RCWL1601 
![RCWL1601](res/RCWL1601.png)

### ObservedProperty:
```javascript
{
  "name": "Distance",
  "description": "Distance is a numerical measurement of how far apart objects or points are",
  "definition": "https://en.wikipedia.org/wiki/Distance"
}
```
