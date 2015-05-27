float violinZero = -0.4;

float violinGains[12] = 
{0.3048,0.3132,0.3937,0.6520,0.2992,0.2933,
        0.2576,0.1583,0.1097,0.2799,0.2010,0.4073};

//int violinMap[8] = {0,1,2,3,9,10,7,11};
int violinMap[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

/*
Power and root power in file viol1.snd is 400515.985631 and 632.863323
Power and root power in file viol2.snd is 556424.527603 and 745.938689
Power and root power in file viol3.snd is 1295785.358709 and 1138.325682
Power and root power in file viol4.snd is 532230.530880 and 729.541315
Power and root power in file viol5.snd is 563566.817998 and 750.710875
Power and root power in file viol6.snd is 249991.578523 and 499.991578
Power and root power in file viol7.snd is 237112.774389 and 486.942270
Power and root power in file viol8.snd is 101803.470885 and 319.066562
Power and root power in file viol9.snd is 102326.489791 and 319.885120
Power and root power in file viol10.snd is 578576.313083 and 760.642040
Power and root power in file viol11.snd is 208398.872448 and 456.507253
Power and root power in file viol12.snd is 934622.525586 and 966.758773
*/

float violinRef[12] =
{632.8633,745.9386,1138.3256,729.5413,750.7108,499.9915,
        486.9422,319.0665,319.8851,760.6420,456.5072,966.7587};

float violin_coeffs[12][12] = {
{-2.023804, 2.376192, -2.312166, 1.949804, -1.431758, 1.159479, 
	-1.362664, 1.709662, -1.684887, 1.397267, -0.943157, 0.356009}, 
{-2.208119, 2.834214, -2.977922, 2.750384, -2.088606, 1.512393, 
	-1.414655, 1.477453, -1.287691, 1.010672, -0.591757, 0.230649}, 
{-2.150693, 2.981455, -3.254255, 3.196642, -2.885528, 2.626699, 
	-2.413701, 2.142949, -1.558828, 0.996509, -0.574884, 0.225024}, 
{-1.654185, 1.626393, -1.255666, 1.003613, -0.714274, 0.454166, 
	-0.401226, 0.522852, -0.467512, 0.398846, -0.222780, 0.081895}, 
{-2.235950, 2.792790, -3.009257, 2.999698, -2.589260, 2.107630, 
	-1.784707, 1.346138, -0.800333, 0.440104, -0.354822, 0.230685}, 
{-2.134473, 2.372837, -1.952327, 1.479531, -1.113510, 0.929363, 
	-1.028094, 1.178098, -0.946531, 0.578314, -0.403791, 0.200350}, 
{-1.984254, 2.259482, -2.061651, 1.734264, -1.428259, 1.424010, 
	-1.548107, 1.503281, -1.187227, 0.783834, -0.427325, 0.162490}, 
{-2.126112, 2.333006, -2.198832, 2.091173, -1.815900, 1.489429, 
	-1.524139, 1.569313, -1.083542, 0.492718, -0.241495, 0.164494}, 
{-2.350272, 3.165668, -3.492844, 3.468414, -2.997883, 2.394929, 
	-1.965721, 1.685604, -1.400087, 1.054771, -0.658721, 0.258035}, 
{-2.135691, 2.663804, -2.721467, 2.610525, -2.457327, 2.270490, 
	-2.285632, 2.379867, -2.167305, 1.612971, -0.967602, 0.366572}, 
{-1.984009, 2.177095, -2.193047, 2.395648, -2.387808, 2.153961, 
	-1.920257, 1.679150, -1.292833, 0.988029, -0.715157, 0.289558}, 
{-1.944111, 2.346576, -2.703943, 2.793182, -2.401715, 2.015662, 
	-1.795797, 1.532244, -1.212536, 1.024383, -0.743272, 0.315117}
}; 

