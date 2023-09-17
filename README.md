# pi-fx
Really hacky fx unit for pi/ hifiberry/ wio terminal setup


```
cmake -B build .
cmake --build build --config Release
./build/pi-fx
# then run jackd on the hifiberry
jackd -d alsa -d hw:3
# then run sclang
sclang 
s.boot
```

Then the ui just writes to control buses 1..n with OSC c_set messages so you can
make a synth like this:

```
SynthDef("fm", {
	var f, c, i;
	f = In.kr(1);
	i = In.kr(2);
	c = PMOsc.ar([f, f], [f/2, f/2], i/50);
	Out.ar(0, c);
}).add;
Synth("fm");
```
and control it with the powermate via the UI.

