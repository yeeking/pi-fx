s.boot
~verb = Synth("reverbEffect");


SynthDef("fm", {
	var f, c, i;
	f = In.kr(1);
	i = In.kr(2);
	c = PMOsc.ar([f, f], [f/2, f/2], i/50);
	Out.ar(0, c);
}).add;

// reverb that reads settings off buses 1 and 2
// the little gui writes its values there
(
SynthDef(\reverbEffect, {

    var src, reverbSig, roomSizeControl, dampControl;

    // Read from the input bus
    src = SoundIn.ar([0, 1], 2);

    // Read room size and damp values from their respective buses
    roomSizeControl = In.kr(1, 1);
    dampControl = In.kr(2, 1);

    // Apply the reverb
    reverbSig = FreeVerb.ar(src, mix: dampControl/1000, room: roomSizeControl/1000.0, damp: dampControl/1000.0);

    // Output to the specified bus
    Out.ar(0, reverbSig);
}).add;
)

