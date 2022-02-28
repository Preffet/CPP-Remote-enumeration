The code reads the content of the files in the home directory of the victim and sends it to the attacker machine via a TCP connection using 5555 port.

The attacker has to set up a listener (for example, using netcat) on port 5555 in order to receive the data. This can be done via terminal:
'''
nc -lvp 5555
'''
And then run the compiled code.