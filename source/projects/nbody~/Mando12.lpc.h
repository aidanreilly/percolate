float mandoZero = -0.4;

float mandoGains[12] =
{0.5787,0.5460,0.7135,0.4235,0.9745,0.6899,
        0.1493,0.0857,0.1286,0.2817,0.1565,0.2224};

//int mandoMap[8] = {0,1,2,3,9,10,6,11};
int mandoMap[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

/*  
Power and root power in file mand1.snd is 717207.000000 and 846.880747
Power and root power in file mand2.snd is 291724.402212 and 540.115175
Power and root power in file mand3.snd is 642390.531423 and 801.492690
Power and root power in file mand4.snd is 341434.874560 and 584.324289
Power and root power in file mand5.snd is 833810.887883 and 913.132459
Power and root power in file mand6.snd is 927016.172197 and 962.816791
Power and root power in file mand7.snd is 44728.129713 and 211.490259
Power and root power in file mand8.snd is 34059.850679 and 184.553111
Power and root power in file mand9.snd is 84691.174208 and 291.017481
Power and root power in file mand10.snd is 195525.112368 and 442.182216
Power and root power in file mand11.snd is 50692.231523 and 225.149354
Power and root power in file mand12.snd is 104371.815234 and 323.066271
*/

float mandoRef[12] =
{846.8807,540.1151,801.4926,584.3242,913.1324,962.8167,
        211.4902,184.5531,291.0174,442.1822,225.1493,323.0662};

float mando_coeffs[12][12] = {
{-1.796718, 1.863939, -1.473548, 1.047811, -1.015072, 0.945535, 
	-0.889832, 0.878003, -1.027805, 1.057178, -0.780444, 0.307721}, 
{-1.530540, 1.306501, -0.930060, 0.606623, -0.789756, 0.724931, 
	-0.513838, 0.402777, -0.459193, 0.460847, -0.369165, 0.214450}, 
{-1.858580, 1.778506, -0.989400, 0.154717, -0.148924, 0.564142, 
	-0.771660, 0.608833, -0.479801, 0.470707, -0.442776, 0.228736}, 
{-1.754877, 1.859426, -1.435496, 0.861752, -1.132136, 1.181470, 
	-1.117166, 0.909949, -0.528789, 0.374553, -0.099352, 0.002664}, 
{-1.403159, 1.066739, -0.728622, 0.386115, -0.656912, 0.670015, 
	-0.474660, 0.432184, -0.665043, 0.802163, -0.645829, 0.339578}, 
{-2.061367, 2.070011, -1.200862, 0.435803, -0.685231, 1.292073, 
	-1.380526, 0.733703, -0.191041, 0.066080, -0.177785, 0.191294}, 
{-1.972578, 1.992975, -1.557943, 1.060172, -0.969376, 0.901108, 
	-0.789415, 0.684391, -0.723250, 0.606167, -0.340449, 0.191127}, 
{-2.461387, 2.979803, -2.543369, 1.847332, -1.567980, 1.506378, 
	-1.383608, 1.191359, -1.093687, 0.923344, -0.579273, 0.235699}, 
{-2.354346, 3.033594, -2.902969, 2.269601, -1.873127, 1.698947, 
	-1.450701, 1.056937, -0.744702, 0.556784, -0.406556, 0.213016}, 
{-1.935683, 1.868054, -1.647370, 1.392895, -1.326931, 1.209765, 
	-0.957004, 0.932156, -0.963302, 0.784766, -0.531875, 0.244684}, 
{-2.031068, 2.185913, -1.526106, 0.654994, -0.630763, 0.868166, 
	-0.978311, 0.841511, -0.734939, 0.695339, -0.472613, 0.213606}, 
{-1.864361, 1.860422, -1.475492, 1.173806, -1.093002, 0.960444, 
	-0.909551, 0.882869, -0.959513, 0.814220, -0.490048, 0.214404}
}; 
