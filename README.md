# Inlines_Hunter
* inline Hooking is the act of detouring the flow of code via hotpatching. Hotpatching is defined as the modification of code during the runtime of an executable . The purpose of inline hooking to be able to capture the instance the program calls a function and then from there, observation and/or manipulation of the call can be accomplished
* the purpose of this project is to Detect API Hooks by scanning opcodes patterns then follow the jump address, and see if it jumps to a legitimate module or injected/malicious module from the av/malware and locate that module in all processes .

  # VIDEO

  https://user-images.githubusercontent.com/60795188/172503817-da29f7bb-af4c-4e62-b993-4ecbd47d432d.mp4


# DETAILS
* if any hook detected ,a MessageBox will pop up with alert 'hook detected' ,with all the details in console.
  ![image](https://user-images.githubusercontent.com/60795188/161443202-3aac7d65-388a-46a6-aef7-738440410c5e.png)

  ![image](https://user-images.githubusercontent.com/60795188/166088109-bf09e1a4-e8b1-440c-8e5c-add6bbad1c10.png)
  
* if no hook detected , a MessageBox will pop up with alert 'no hook detected'

  ![image](https://user-images.githubusercontent.com/60795188/161444125-32d3257d-e1f3-4a36-bd0f-762cef48c96c.png)

  ![image](https://user-images.githubusercontent.com/60795188/166088203-6d6ba2dc-a51b-4ace-91e6-f2e42cdbf26f.png)
  
