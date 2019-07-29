#define CUSTOM_SETTINGS
#define INCLUDE_SMS_SHIELD
#define INCLUDE_VIBRATION_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isMessageSent = false;

int ledPin = 13;

void setup() {
 /* Start communication. */
 OneSheeld.begin();
 /* Set the LED pin as output. */
 pinMode(ledPin,OUTPUT);
}

void messageRecieved(String phoneNumber ,String messageBody) {
   /* Print out the phone Number and message on Terminal shield. */
    Terminal.println(phoneNumber);
    Terminal.println(messageBody);
    /* LED on */
    digitalWrite(ledPin,HIGH);
    /* Vibrate for 1 second every 5 seconds. */
    Vibration.start(1000,5000);
    /* Message recieved */
    TextToSpeech.say("A message has been recieved.");
    /* Wait for 12 seconds. */
    OneSheeld.delay(12000);
    /* Stop the vibration. */
    Vibration.stop();
    /* LED off */
    digitalWrite(ledPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  SMS.setOnSmsReceive(&messageRecieved);
}
