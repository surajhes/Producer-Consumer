# Producer-Consumer
This is a simple Producer-Consumer problem written is C language. It is also known as bounded buffer problem. In this problem we have two processes producer and consumer who share the same buffer. Producer produces the data and puts it in the buffer. Once the buffer is full then the producer notifies the customer and goes to sleep. The consumers work is to remove the data from buffer and consume it, once the consumer is done consuming it notifies the producer and goes to sleep.

We have to make sure that the producer do not produce data when buffer is full and consumer do not consume data when buffer is empty.

![image](https://cloud.githubusercontent.com/assets/25694725/24351270/acf25792-1302-11e7-8e2e-b06c29803b67.png)
