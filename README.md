# Assignment week 4 

Group number 1:
    members : 
        Do Hoang Nam 
        Tran Tien Thanh
        Pham Son Hai Duong
        Dinh Quoc An
        Nguyen Minh Quan


## yeu cau co ban
1. Trinh bay mot loai ma dong trong ho eStream da duoc giao vao file ppt

    ma dong nhom trinh bay: MICKEY 2.0
    file ppt: duoc gui kem trong assignment

2. cai dat giai thuat, gui kem link code, ket qua mo phong input va out put 






## yeu cau nang cao 

1. so sanh thoi gian tao dong khoa cung chieu dai khi thuc hien thuat toan RC4 va MICKEY2.0
    g++ -o output.exe RC4.cpp framework.cpp 
    ./output.exe


    Output: 

<!-- Welcome to the encryption testing site!
In this testing site, we are gonna have four different tests for an eStream:
1. Encryption rate for long streams: The testing framework measures the encryption rate by encrypting a long stream in chunks of about 4KB. The encryption speed, in cycles/byte, is calculated by measuring the number of bytes encrypted in 250 µsec.
!) Note that the time to setup the key or the IV is not considered in this test.
2. Packet encryption rate: While a block cipher is likely to be a better choice when encrypting very short packets, it is still interesting to determine at which length a stream cipher starts to take the lead. 
The packet encryption rate is measured by applying with the packets of different lengths. Each call includes a separate IV setup and and the packet lengths (40, 576, and 1500 bytes) were chosen to be representative for the traffic seen on the Internet [JTC-003].
3. Agility : The testing framework performs the following test: it first initiates a large number of sessions (filling 16MB of RAM ), and then encrypts streams of plaintext in short blocks of around 256 bytes
4. Key and IV setup: The last test in the testing framework separately measures the efficiency of the key setup and the IV setup



Welcome to the encryption testing site!
In this testing site, we are gonna have four different tests for an eStream:
1. Encryption rate for long streams: The testing framework measures the encryption rate by encrypting a long stream in chunks of about 4KB. The encryption speed, in cycles/byte, is calculated by measuring the number of bytes encrypted in 250 µsec.
!) Note that the time to setup the key or the IV is not considered in this test.
2. Packet encryption rate: While a block cipher is likely to be a better choice when encrypting very short packets, it is still interesting to determine at which length a stream cipher starts to take the lead. 
The packet encryption rate is measured by applying with the packets of different lengths. Each call includes a separate IV setup and and the packet lengths (40, 576, and 1500 bytes) were chosen to be representative for the traffic seen on the Internet [JTC-003].
3. Agility : The testing framework performs the following test: it first initiates a large number of sessions (filling 16MB of RAM ), and then encrypts streams of plaintext in short blocks of around 256 bytes
4. Key and IV setup: The last test in the testing framework separately measures the efficiency of the key setup and the IV setup



Testing eStream: RC4
====================
Profile: Team 1
Key size: 128 bits

Estimated CPU frequency: 3.11043e+09 Hz
Cycles are measured using RDTSC instruction

Testing memory requirements:
Size of ECRYPT_ctx: 108 bytes

Testing stream encryption speed:

Encrypted 2blocks of 4096 bits (under 1 keys, 2 blocks/key)
Total time: 0.000398238
Encryption speed (cycles/byte):302.574
Encryption speed (Mbps): 9.80883
Testing packet encryption speed:

Encrypted 116packets of 40 bits (under 1 keys, 116 blocks/key)
Total time: 0.00025311Encryption speed (cycles/byte):19691.9
Encryption speed (Mbps): 0.150713

Encrypted 9packets of 40 bits (under 1 keys, 9 blocks/key)
Total time: 0.000292571Encryption speed (cycles/byte):1580.59
Encryption speed (Mbps): 1.87755

Encrypted 4packets of 40 bits (under 1 keys, 4 blocks/key)
Total time: 0.000294804Encryption speed (cycles/byte):611.604
Encryption speed (Mbps): 4.85242

Testing key setup speed: 
Did 7000 key setups under 1 key
Key setup time: 0.0361938 seconds


Welcome to the encryption testing site!
In this testing site, we are gonna have four different tests for an eStream:
1. Encryption rate for long streams: The testing framework measures the encryption rate by encrypting a long stream in chunks of about 4KB. The encryption speed, in cycles/byte, is calculated by measuring the number of bytes encrypted in 250 µsec.
!) Note that the time to setup the key or the IV is not considered in this test.
2. Packet encryption rate: While a block cipher is likely to be a better choice when encrypting very short packets, it is still interesting to determine at which length a stream cipher starts to take the lead. 
The packet encryption rate is measured by applying with the packets of different lengths. Each call includes a separate IV setup and and the packet lengths (40, 576, and 1500 bytes) were chosen to be representative for the traffic seen on the Internet [JTC-003].
3. Agility : The testing framework performs the following test: it first initiates a large number of sessions (filling 16MB of RAM ), and then encrypts streams of plaintext in short blocks of around 256 bytes
4. Key and IV setup: The last test in the testing framework separately measures the efficiency of the key setup and the IV setup



Testing eStream: Mickey2.0>
====================
Profile: Team 1
Key size: 80 bits
IV size: 80 bits

Estimated CPU frequency: 3.11037e+09 Hz
Cycles are measured using RDTSC instruction

Testing memory requirements:
Size of ECRYPT_ctx: 108 bytes

Testing stream encryption speed:

Encrypted 1blocks of 4096 bits (under 1 keys, 1 blocks/key)
Total time: 
Encryption speed (cycles/byte):4078.34
Encryption speed (Mbps): 0.727326
Testing packet encryption speed:

Encrypted 1packets of 40 bits (under 1 keys, 1 blocks/key)
Total time: 0.000400188Encryption speed (cycles/byte):31121.2
Encryption speed (Mbps): 0.0953226

Encrypted 1packets of 40 bits (under 1 keys, 1 blocks/key)
Total time: 0.00649495Encryption speed (cycles/byte):35073.7
Encryption speed (Mbps): 0.0845759

Encrypted 1packets of 40 bits (under 1 keys, 1 blocks/key)
Total time: 0.0169989Encryption speed (cycles/byte):35248.9
Encryption speed (Mbps): 0.0841529

Testing key setup speed: 
Did 7000 key setups under 1 key
Keystream setup time: 2.27061 seconds -->



2. So sanh do nhay khoa cua hai thuat toan RC4 va MICKEY2.0