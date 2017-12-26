first run this when in src
```
cd threads; make; cd ../userprog/; make; cd ../utils/ ; make; cd ../vm/; make ; cd ../examples/; make ; cd ../filesys/ ; make; cd ..;
```
run this when in userprog/build

```
cd ../../examples/ && make && cd ../userprog/build/ && make && pintos --filesys-size=2 -p ../../examples/echo -a echo -- -f run 'echo'
```

REFERENCES:

- [github ref](https://github.com/ryantimwilson/Pintos-Project-2/blob/master/src/userprog/syscall.c)
- [another github ref](https://github.com/pindexis/pintos-project2/blob/master/userprog/syscall.c)
- [running pintos with qemu](https://github.com/ivogeorg/os-playground/blob/master/pintos-with-qemu.md)
- [stanford pintos doc](https://web.stanford.edu/~ouster/cgi-bin/cs140-winter16/pintos/pintos.html#SEC_Top)
- [running user programs in pintos](http://www.scs.stanford.edu/15au-cs140/pintos/pintos_3.html#SEC32)