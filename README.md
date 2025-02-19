# Obstacle-Avoiding Vehicle

## Overview
This project is an autonomous obstacle-avoiding vehicle developed using an Arduino Uno R3. The vehicle moves using two powered wheels and one free-spinning wheel while detecting obstacles using an ultrasonic sensor. When an obstacle is detected, the vehicle will stop, reverse, and change direction to avoid collisions.

![image](https://github.com/user-attachments/assets/9cc1ff3d-a192-4b95-8975-52a1e6516ca1)

![image](https://github.com/user-attachments/assets/b6eeb6fb-e439-4d17-962b-61aa677bd271)

## Features
- **Autonomous movement**
- **Obstacle detection using an ultrasonic sensor**
- **Reverse and turn mechanism upon detecting an obstacle**
- **Adjustable sensitivity for obstacle detection**

## How It Works
1. The vehicle moves forward by default.
2. It continuously checks for obstacles using the ultrasonic sensor.
3. If an obstacle is detected within a certain distance, it:
   - Stops for a brief moment
   - Reverses for a short duration
   - Turns right to change direction
4. The cycle repeats as the vehicle continues its movement.

## Components Used
### Arduino Uno R3
- Serves as the main controller for all components.

### Ultrasonic Sensor
- Detects obstacles by measuring distance through sound waves.

### Motor System
- Two powered wheels controlled by the Arduino for movement.
- One free-spinning wheel for stability.

![image](https://github.com/user-attachments/assets/8f513177-7d27-465f-829a-8a6e70fa26c4)

## Source Code
### Main Functions
- **`setup()`** - Initializes components and serial communication.
- **`loop()`** - Continuously monitors obstacles and determines the vehicle's movement.
- **`turnRight()`** - Turns the vehicle right to avoid obstacles.
- **`reverse()`** - Moves the vehicle backward.
- **`stop()`** - Stops all movement.
- **`drive()`** - Moves the vehicle forward.

### Key Code Snippet
```cpp
void loop() {
  int time, dist;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  time = pulseIn(echo, HIGH);
  dist = (time/2)/29.1;
  Serial.print(dist);
  Serial.print('\n');

  if (dist <= 14) {
    stop();
    delay(1000);
    reverse();
    delay(500);
    stop();
    delay(1000);
    turnRight();
    delay(500);
    stop();
    delay(1000);
  } else {
    drive();
  }
}
```

## Challenges and Solutions
- **Free-spinning rear wheel caused drifting** → Solution: Use a fixed-position wheel for stability.
- **Sensor misreads distances at angles** → Solution: Implement a filtering mechanism to detect patterns of incorrect readings.
- **Occasional sensor inaccuracies** → Solution: Adjust the detection range to minimize false triggers.

## Future Improvements
- Implement 360-degree environment scanning for better navigation.
- Improve motor control for smoother turns and better movement stability.
- Upgrade the chassis for better terrain adaptability.

## Authors
- **Łukasz Sajdak**
- **Jakub Konior**

## License
This project is open-source and available for educational use.

