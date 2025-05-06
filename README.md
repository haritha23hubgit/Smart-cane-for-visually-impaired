# Smart Cane for the Visually Impaired  (> Also see: [Breast Ultrasound Segmentation Project](https://github.com/haritha23hubgit/Segmentation_unet-breast--cancer))


This project is a smart navigation aid for the visually impaired, designed using an Arduino Nano and a set of sensors to detect obstacles, water, potholes, and trigger emergency communication.

## 🔧 Features

| Function | Sensor Used | Feedback |
|----------|-------------|----------|
| Obstacle Detection | Ultrasonic Sensor | Vibration Motor |
| Water Detection | Water Sensor | Buzzer (tone 1) |
| Darkness/Pothole Detection | LDR Sensor | Buzzer (tone 2) |
| Emergency Alert | Push Button + GPS-GSM | Sends SMS via Bluetooth |

## 🧠 My Contribution

- Designed and wired the complete embedded system using Arduino Nano
- Programmed sensor interactions and feedback mechanisms
- Integrated GPS-GSM and Bluetooth module for emergency communication
- Built a working prototype on a physical cane

## 📁 Files

- `smart_cane_code.ino`: Arduino sketch with core logic
- `block_diagram.pdf`: System architecture
- `final_project_photo.pdf`: Final implementation 

## 💡 Future Improvements

- Add camera module to improve real time obstacle detection
- Add voice guidance using speaker module
- Improve GPS parsing for accurate location extraction

## 🛠️ Hardware Used

- Arduino Nano
- HC-SR04 Ultrasonic Sensor
- Water Sensor
- LDR Sensor
- Vibration Motor
- Buzzer
- Push Button
- GPS-GSM Module (e.g., SIM800L)
- Bluetooth Module (e.g., HC-05)
- Lithium-ion battery
- PVC Cane Body

---

> 🔐 This project is published as an academic and assistive technology demo.  
> All ideas and circuits here are open for learning and reuse, and no confidential or patented elements are shared.
