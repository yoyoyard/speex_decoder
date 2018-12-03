# SpeexDecoder

Ruby gem to convert Wechat `.speex` voice file into `.wav`


### Install
Need the `speex` libs, should install the speex first.

for mac
```
brew install speex
```

for Ubuntu 
```
sudo apt-get install speex build-essential libspeex-dev
```

### Usage 
```
SpeexDecoder.decode('path/a.speex', 'path/a.wav')
```
