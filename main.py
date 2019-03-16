from pyetherscan import Client
from pyetherscan import Address

client = Client()
address = '0xb296D9e83c966bf65065E5D4e5F1Bf802A881950'
contract_address = '0x89d24a6b4ccb1b6faa2625fe562bdd9a23260359'

counter = 0
token_balance = 0

from time import sleep

import serial
ser = serial.Serial("COM7", 9600) # Establish the connection on a specific port

while True:

    # Increase counter by 1
    counter += 1
    print("Reading #", counter)

    # Get address
    address_balance = client.get_single_balance(address)
#    print ("Status Code: ", address_balance.response_status_code)
#    print ("Satus: ", address_balance.message)

    # Get ethereum balance
    balance = address_balance.balance
    balance = balance / 10**18
    print("ETH Reading:", balance)

    # Get token balance
    ethereum_address = Address(address)
    new_token_balance = ethereum_address.token_balance(contract_address)
    new_token_balance = new_token_balance / 10**18

    # Print previous and current token balance
    print("Previous DAI Reading:", token_balance)
    print("New DAI Reading:", new_token_balance)

    # Display token difference
    token_difference = new_token_balance - token_balance
#    print("Difference: ", token_difference)
    token_balance = new_token_balance
#    print("Dai Balance set to: ", token_balance)

    if counter % 2 == 0:
        print("Counter is Even")
        ser.write(b'0')
    else:
        print("Counter is Odd")
        ser.write(b'1')

    print("Arduino Reading:", ser.readline()) # Read the newest output from the Arduino
    sleep(5)

#    if token_difference > 0:
#        print("WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO")


#        sleep(5) # may need 5 seconds
        #number = 5
        #thisByteArray = number.to_bytes(64, byteorder = 'big')
#        number = int(token_balance)
#        numberInByteArray = number.to_bytes(64, byteorder = 'big')
        #byte = chr(0x31)
        #print("writing...")
        #print(byte)
        #realbyte = byte.encode
        #print(realbyte)
        #ser.write(byte.encode()) # byte0<=i<=255
#        ser.write(numberInByteArray)
#        sleep(2)
#        print("reading line...")
#        print(ser.readline()) # Read the newest output from the Arduino
#        thisString = str(ser.readline())

    # Print new line
    print('\n')

ser.close()
