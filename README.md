# Chickenshed-Door-Watcher

## Description

An ESP8266-based monitoring tool designed to keep an eye on the state of a chickenshed door operated by a light sensor. The project periodically fetches the current time and sunrise or sunset times to determine if the door should be open or closed. If the door is not in the expected state, a notification is sent out via IFTTT webhooks.

## Installation

1. Clone this repository.
2. Install the required libraries.
3. Flash the firmware onto your ESP8266.

## How it Works

The system periodically checks the state of the door by reading the reed switch. It then fetches the current time and either the sunrise or sunset time, depending on the door's state.

### Door Open

When the door is open, the system fetches the current time and the sunset time. It then calculates the expected closing time. If the current time is past the calculated closing time, a notification is sent out to alert that the door has not been closed.

### Door Closed

Similarly, when the door is closed, the system fetches the current time and the sunrise time. It calculates the expected opening time and sends out a notification if the door has not been opened after this time.

## Notifications

Notifications are sent out using IFTTT webhooks. You'll need to set up an IFTTT account and configure a webhook to receive these notifications.

## Contributing

Contributions to improve this repository are always welcome. If you find any issues or have suggestions for enhancements, please open an issue or submit a pull request.

## License

This repository is licensed under the [MIT License](LICENSE). Feel free to use it as a starting point for your own firmware projects.
