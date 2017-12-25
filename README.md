first run this when in src
```
cd threads; make; cd ../userprog/; make; cd ../utils/ ; make; cd ../vm/; make ; cd ../examples/; make ; cd ../filesys/ ; make; cd ..;
```
run this when in userprog/build

```
cd ../../examples/ && make && cd ../userprog/build/ && make && pintos --filesys-size=2 -p ../../examples/echo -a echo -- -f run 'echo'
```

REF:
[github ref](https://github.com/ryantimwilson/Pintos-Project-2/blob/master/src/userprog/syscall.c)
