# Hooks_Hunter
* API Hooking is the act of detouring the flow of code via hotpatching. Hotpatching is defined as the modification of code during the runtime of an executable . The purpose of inline hooking to be able to capture the instance the program calls a function and then from there, observation and/or manipulation of the call can be accomplished

* Example of an API hook 

  ![image](https://user-images.githubusercontent.com/60795188/180610747-b5428363-939a-4afe-965a-bb0b9c93ebfb.png)

* the purpose of this project is to Detect API Hooks by scanning opcodes patterns then follow the jump address, and see if it jumps to a legitimate module or injected/malicious module from the av/malware and locate that module in all processes .

# DETAILS

* first the program will scan for any hooking signs if any hook detected its will read the jump address and follow it and retrieves the base address of the jump address then enumerate over all processes modules in the system and locate that module in all of them.

* an Example of hooked function

  ![image](https://user-images.githubusercontent.com/60795188/161443202-3aac7d65-388a-46a6-aef7-738440410c5e.png)

* if hook detected an alert will pop up

  ![image](https://user-images.githubusercontent.com/60795188/166088109-bf09e1a4-e8b1-440c-8e5c-add6bbad1c10.png)
  
* if no hook detected , a MessageBox will pop up with alert 'no hook detected'

* an example of clean function 

  ![image](https://user-images.githubusercontent.com/60795188/161444125-32d3257d-e1f3-4a36-bd0f-762cef48c96c.png)

  ![image](https://user-images.githubusercontent.com/60795188/166088203-6d6ba2dc-a51b-4ace-91e6-f2e42cdbf26f.png)
  
  # VIDEO

  https://user-images.githubusercontent.com/60795188/172503817-da29f7bb-af4c-4e62-b993-4ecbd47d432d.mp4
