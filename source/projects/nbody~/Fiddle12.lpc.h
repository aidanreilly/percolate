float fiddleZero = -0.7;

float fiddleGain = 0.5;

float fiddleGains[12] = 
{0.2082,0.2597,0.3563,0.2197,0.3128,0.1374,
        0.2401,0.0917,0.0463,0.3184,0.2569,0.4064};

//int fiddleMap[8] = {0,1,2,3,9,10,6,11};
int fiddleMap[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
//int fiddleRevMap[8] = {6, 6, 6, 6, 3, 11, 0, 5};

/*
Power and root power in file fidl1.snd is 238958.007547 and 488.833313
Power and root power in file fidl2.snd is 542273.649560 and 736.392320
Power and root power in file fidl3.snd is 1232975.414340 and 1110.394261
Power and root power in file fidl4.snd is 228084.920503 and 477.582370
Power and root power in file fidl5.snd is 1105513.889811 and 1051.434206
Power and root power in file fidl6.snd is 185422.720503 and 430.607386
Power and root power in file fidl7.snd is 306765.608553 and 553.864251
Power and root power in file fidl8.snd is 80987.884277 and 284.583703
Power and root power in file fidl9.snd is 88810.549937 and 298.010990
Power and root power in file fidl10.snd is 604611.363019 and 777.567594
Power and root power in file fidl11.snd is 159892.434717 and 399.865521
Power and root power in file fidl12.snd is 490729.687044 and 700.521011
*/

float fiddleRef[12] =
{488.8333,736.3923,1110.3942,477.5823,1051.4342,430.6073,
        553.8642,284.5837,298.0109,777.5675,399.8655,700.5210};


float fiddle_coeffs[12][12] = {
{-2.295268, 2.820711, -2.960941, 2.866363, -2.315769, 1.811879, 
	-1.413994, 0.941507, -0.505028, 0.175051, -0.013214, 0.047657}, 
{-2.521144, 3.513609, -3.710510, 3.321420, -2.625328, 2.116837, 
	-1.716614, 1.341164, -0.987442, 0.725933, -0.418365, 0.180243}, 
{-2.494267, 3.512346, -3.769954, 3.543511, -3.021232, 2.647696, 
	-2.283476, 1.900723, -1.464033, 1.096493, -0.621567, 0.184962}, 
{-2.172383, 2.773964, -2.796562, 2.429504, -1.942114, 1.697234, 
	-1.462710, 0.985798, -0.307786, -0.097372, 0.150433, -0.008240}, 
{-2.682536, 3.808416, -4.216564, 4.021561, -3.385033, 2.863937, 
	-2.404327, 1.785294, -1.169739, 0.672836, -0.237228, 0.055824}, 
{-2.576571, 3.404093, -3.641464, 3.593374, -3.150658, 2.802349, 
	-2.484344, 1.911201, -1.356636, 0.921326, -0.436043, 0.110209}, 
{-2.504965, 3.096390, -2.706621, 2.163552, -1.756821, 1.825524, 
	-1.912370, 1.410702, -0.688781, 0.360137, -0.220333, 0.085211}, 
{-2.627386, 3.495076, -3.591938, 3.481045, -3.174183, 2.813469, 
	-2.424637, 1.879715, -1.180992, 0.581764, -0.236771, 0.100601}, 
{-3.058262, 5.050920, -6.473746, 7.211713, -7.035944, 6.598280, 
	-6.190514, 5.375162, -4.135546, 2.772461, -1.372876, 0.358111}, 
{-2.258006, 2.835578, -2.976823, 2.843613, -2.472261, 2.060865, 
	-1.599611, 1.224850, -0.824636, 0.460089, -0.257898, 0.139322}, 
{-2.066864, 2.127224, -1.806725, 1.521238, -1.115419, 0.945230, 
	-0.805019, 0.613595, -0.611126, 0.646246, -0.370760, 0.102717}, 
{-1.902391, 2.006613, -2.081684, 2.078642, -1.696361, 1.346484, 
	-1.025655, 0.600574, -0.401052, 0.299115, 0.036156, -0.074934}
}; 