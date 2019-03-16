from etherscan.accounts import Account
import json

with open('api_key.json', mode='r') as key_file:
    key = json.loads(key_file.read())['key']

address = '0xddbd2b932c763ba5b1b7ae3b362eac3e8d40121a'

api = Account(address=address, api_key=key)
balance = api.get_balance()
print(balance)

address_1 = '0xb215cFebB90D91b1D2F499843800d3105b1366Fc'
address_2 = '0xE84c0cb5a6D2AE7E84Dcdcc0AAAb2A36cBc95c07'
contract_address = '0x89d24a6b4ccb1b6faa2625fe562bdd9a23260359'

from time import sleep

#import serial
#ser = serial.Serial("COM7", 9600) # Establish the connection on a specific port

def getETH(address):
    # Get address
    api = Account(address=address, api_key=key)
#    print ("Status Code: ", address_balance.response_status_code)
#    print ("Satus: ", address_balance.message)

    # Get ethereum balance
    balance = api.get_balance()
    balance = balance / 10**18
    print("ETH Reading:", balance)
    return balance

def printDAI(address, token_balance):
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
    return

def doSerialStuff ():
    # Send serial message to Arduino
    if counter % 2 == 0:
        print("Counter is Even")
        ser.write(b'0')
    else:
        print("Counter is Odd")
        ser.write(b'1')

    # Read the newest output from the Arduino        
    print("Arduino Reading:", ser.readline())

def run():
    counter = 0
    balance_1 = 0
    balance_2 = 0

    while True:
        # Increase counter by 1
        counter += 1
        print("Reading #", counter)

        # Print addresses and balances
        print("Address 1:", address_1)
        new_balance_1 = getETH(address_1)
        difference_1 = new_balance_1 - balance_1
        balance_1 = new_balance_1
        print("Difference is:", difference_1)
        print("Address 2:", address_2)
        new_balance_2 = getETH(address_2)
        difference_2 = new_balance_2 - balance_2
        print("Difference is:", difference_2)
        balance_2 = new_balance_2

        if(difference_1 > 0):
            print("ACCOUNT 1 IS WINNING!")
        if(difference_2 > 0):
            print("ACCOUNT 2 IS WINNING!")

        #do the Serial stuff
#        doSerialStuff():
        
        # Print new line
        print('\n')

        # Sleep
        sleep(2)

run()

ser.close()
