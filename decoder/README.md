# Decoder

This project builds and runs a C/C++ decoder application along with unit tests using Docker and Docker Compose.

---
## Assumpitions

The assumption on decoder function is that the decoder runs as a separate process and it fails, likely due to communication issues or a problem with decoder process itself.

The solution is written based on this assumption.

Looking at the decoder, it seems to be implementing ROT13. Other decoding methods usually add  special characters or numbers in the output, but here, the first two decoded messages and from the third message onward we see encoded messages which are free from, hex codes, or special characters. This strongly points that the decoding function used is ROT13. 

## Prerequisites

- [Docker](https://www.docker.com/)
- [Docker Compose](https://docs.docker.com/compose/)

---

## Clone the Repository

 Cloning this repository to your local machine

```bash
git clone https://github.com/yourusername/decoder.git
cd decoder
```

## Build the Project

To build the Docker image from scratch:

```bash
docker compose build --no-cache
```

To run the decoder and decoder-test 

```bash
docker compose up  --force-recreate
```

To stop and remove all containers

```bash
docker compose down --remove-orphans
```

---
### Result 
decoder and decoder test output should look like this 

![Decoder ](https://github.com/JahanaviKrishnakumar/greenbone/blob/main/decoder/decoder.png)

Decoder test

![Decoder ](https://github.com/JahanaviKrishnakumar/greenbone/blob/main/decoder/decoder-test.png)