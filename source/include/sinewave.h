float sinewave[2048] = { 3067.954 , 6135.879 , 9203.747 , 12271.528 , 15339.194 , 18406.715 , 21474.062 ,
24541.209 , 27608.123 , 30674.777 , 33741.145 , 36807.195 , 39872.895 , 42938.223
, 46003.145 , 49067.637 , 52131.664 , 55195.203 , 58258.219 , 61320.688 ,
64382.574 , 67443.859 , 70504.523 , 73564.508 , 76623.797 , 79682.375 , 82740.203
, 85797.242 , 88853.477 , 91908.883 , 94963.422 , 98017.062 , 101069.781 ,
104121.555 , 107172.344 , 110222.117 , 113270.859 , 116318.539 , 119365.125 ,
122410.578 , 125454.875 , 128498.000 , 131539.922 , 134580.594 , 137620.000 ,
140658.141 , 143694.922 , 146730.359 , 149764.406 , 152797.062 , 155828.281 ,
158858.016 , 161886.266 , 164913.000 , 167938.156 , 170961.750 , 173983.734 ,
177004.062 , 180022.766 , 183039.734 , 186055.000 , 189068.531 , 192080.250 ,
195090.156 , 198098.250 , 201104.469 , 204108.797 , 207111.203 , 210111.656 ,
213110.156 , 216106.625 , 219101.078 , 222093.453 , 225083.719 , 228071.906 ,
231057.922 , 234041.766 , 237023.422 , 240002.844 , 242979.984 , 245954.859 ,
248927.406 , 251897.641 , 254865.438 , 257830.891 , 260793.922 , 263754.469 ,
266712.531 , 269668.125 , 272621.125 , 275571.625 , 278519.469 , 281464.719 ,
284407.312 , 287347.219 , 290284.469 , 293218.938 , 296150.656 , 299079.594 ,
302005.719 , 304929.000 , 307849.406 , 310766.906 , 313681.469 , 316593.125 ,
319501.781 , 322407.438 , 325310.062 , 328209.594 , 331106.062 , 333999.406 ,
336889.594 , 339776.625 , 342660.469 , 345541.062 , 348418.375 , 351292.500 ,
354163.250 , 357030.688 , 359894.750 , 362755.438 , 365612.719 , 368466.562 ,
371316.906 , 374163.781 , 377007.125 , 379846.906 , 382683.125 , 385515.781 ,
388344.750 , 391170.094 , 393991.750 , 396809.656 , 399623.906 , 402434.344 ,
405241.000 , 408043.875 , 410842.875 , 413638.000 , 416429.250 , 419216.562 ,
421999.969 , 424779.344 , 427554.750 , 430326.156 , 433093.500 , 435856.750 ,
438615.875 , 441370.938 , 444121.812 , 446868.500 , 449611.000 , 452349.250 ,
455083.250 , 457812.969 , 460538.375 , 463259.438 , 465976.156 , 468688.469 ,
471396.375 , 474099.875 , 476798.875 , 479493.375 , 482183.406 , 484868.875 ,
487549.812 , 490226.156 , 492897.812 , 495564.875 , 498227.312 , 500885.000 ,
503538.000 , 506186.312 , 508829.781 , 511468.469 , 514102.406 , 516731.438 ,
519355.656 , 521974.906 , 524589.312 , 527198.750 , 529803.250 , 532402.750 ,
534997.312 , 537586.688 , 540171.062 , 542750.438 , 545324.625 , 547893.688 ,
550457.562 , 553016.312 , 555569.812 , 558118.188 , 560661.188 , 563198.938 ,
565731.375 , 568258.500 , 570780.312 , 573296.812 , 575807.750 , 578313.375 ,
580813.500 , 583308.250 , 585797.500 , 588281.125 , 590759.250 , 593231.875 ,
595698.875 , 598160.312 , 600616.125 , 603066.125 , 605510.562 , 607949.375 ,
610382.375 , 612809.688 , 615231.188 , 617646.875 , 620056.812 , 622460.812 ,
624859.125 , 627251.375 , 629637.750 , 632018.312 , 634392.875 , 636761.438 ,
639124.062 , 641480.562 , 643831.062 , 646175.562 , 648514.000 , 650846.250 ,
653172.375 , 655492.438 , 657806.250 , 660113.938 , 662415.312 , 664710.562 ,
666999.438 , 669282.125 , 671558.500 , 673828.562 , 676092.250 , 678349.562 ,
680600.500 , 682845.125 , 685083.188 , 687314.938 , 689540.125 , 691758.812 ,
693971.062 , 696176.688 , 698375.812 , 700568.375 , 702754.250 , 704933.625 ,
707106.375 , 709272.375 , 711431.750 , 713584.438 , 715730.375 , 717869.562 ,
720002.062 , 722127.750 , 724246.625 , 726358.688 , 728463.938 , 730562.312 ,
732653.875 , 734738.500 , 736816.125 , 738886.875 , 740950.625 , 743007.500 ,
745057.375 , 747100.125 , 749135.938 , 751164.688 , 753186.375 , 755200.938 ,
757208.438 , 759208.750 , 761201.938 , 763187.938 , 765166.812 , 767138.500 ,
769102.875 , 771060.062 , 773010.000 , 774952.625 , 776888.000 , 778816.062 ,
780736.750 , 782650.125 , 784556.125 , 786454.812 , 788345.938 , 790229.750 ,
792106.125 , 793975.062 , 795836.438 , 797690.375 , 799536.812 , 801375.688 ,
803207.125 , 805030.875 , 806847.125 , 808655.750 , 810456.750 , 812250.125 ,
814035.875 , 815813.938 , 817584.375 , 819347.062 , 821102.062 , 822849.312 ,
824588.875 , 826320.625 , 828044.562 , 829760.812 , 831469.188 , 833169.750 ,
834862.500 , 836547.250 , 838224.250 , 839893.312 , 841554.500 , 843207.750 ,
844853.125 , 846490.500 , 848119.938 , 849741.312 , 851354.750 , 852960.188 ,
854557.562 , 856146.938 , 857728.125 , 859301.375 , 860866.500 , 862423.562 ,
863972.438 , 865513.188 , 867045.812 , 868570.250 , 870086.625 , 871594.688 ,
873094.562 , 874586.250 , 876069.688 , 877544.875 , 879011.812 , 880470.438 ,
881920.875 , 883362.938 , 884796.688 , 886222.125 , 887639.250 , 889048.000 ,
890448.250 , 891840.250 , 893223.875 , 894599.062 , 895965.875 , 897324.188 ,
898674.062 , 900015.562 , 901348.500 , 902672.938 , 903988.938 , 905296.312 ,
906595.312 , 907885.750 , 909167.562 , 910440.938 , 911705.688 , 912961.812 ,
914209.375 , 915448.375 , 916678.750 , 917900.375 , 919113.438 , 920317.875 ,
921513.688 , 922700.750 , 923879.125 , 925048.875 , 926209.875 , 927362.188 ,
928505.688 , 929640.562 , 930766.562 , 931883.875 , 932992.438 , 934092.250 ,
935183.188 , 936265.375 , 937338.625 , 938403.188 , 939458.938 , 940505.750 ,
941543.688 , 942572.812 , 943593.125 , 944604.500 , 945607.000 , 946600.625 ,
947585.312 , 948561.000 , 949527.875 , 950485.750 , 951434.750 , 952374.688 ,
953305.750 , 954227.812 , 955140.812 , 956045.000 , 956940.062 , 957826.125 ,
958703.188 , 959571.250 , 960430.250 , 961280.250 , 962121.125 , 962953.000 ,
963775.750 , 964589.562 , 965394.125 , 966189.750 , 966976.250 , 967753.562 ,
968521.812 , 969280.938 , 970031.000 , 970771.875 , 971503.625 , 972226.250 ,
972939.688 , 973644.000 , 974339.125 , 975025.125 , 975701.875 , 976369.500 ,
977027.875 , 977677.125 , 978317.125 , 978947.938 , 979569.562 , 980181.938 ,
980785.062 , 981379.000 , 981963.625 , 982539.125 , 983105.312 , 983662.250 ,
984209.875 , 984748.312 , 985277.500 , 985797.375 , 986307.938 , 986809.188 ,
987301.250 , 987783.938 , 988257.438 , 988721.562 , 989176.312 , 989621.812 ,
990058.062 , 990484.875 , 990902.500 , 991310.688 , 991709.562 , 992099.188 ,
992479.375 , 992850.312 , 993211.812 , 993564.000 , 993906.875 , 994240.312 ,
994564.500 , 994879.188 , 995184.625 , 995480.688 , 995767.312 , 996044.562 ,
996312.500 , 996571.062 , 996820.188 , 997060.000 , 997290.375 , 997511.375 ,
997723.000 , 997925.250 , 998118.062 , 998301.438 , 998475.500 , 998640.188 ,
998795.375 , 998941.250 , 999077.688 , 999204.688 , 999322.375 , 999430.562 ,
999529.375 , 999618.750 , 999698.812 , 999769.375 , 999830.562 , 999882.312 ,
999924.688 , 999957.625 , 999981.188 , 999995.312 , 1000000.000 , 999995.312 ,
999981.188 , 999957.688 , 999924.750 , 999882.312 , 999830.625 , 999769.438 ,
999698.875 , 999618.875 , 999529.500 , 999430.688 , 999322.438 , 999204.812 ,
999077.812 , 998941.375 , 998795.500 , 998640.312 , 998475.688 , 998301.625 ,
998118.250 , 997925.375 , 997723.188 , 997511.562 , 997290.562 , 997060.188 ,
996820.375 , 996571.250 , 996312.750 , 996044.812 , 995767.562 , 995480.875 ,
995184.812 , 994879.500 , 994564.688 , 994240.562 , 993907.125 , 993564.312 ,
993212.125 , 992850.625 , 992479.688 , 992099.438 , 991709.938 , 991311.000 ,
990902.812 , 990485.250 , 990058.438 , 989622.250 , 989176.688 , 988721.938 ,
988257.750 , 987784.375 , 987301.625 , 986809.625 , 986308.312 , 985797.750 ,
985277.875 , 984748.750 , 984210.312 , 983662.688 , 983105.750 , 982539.625 ,
981964.188 , 981379.438 , 980785.562 , 980182.438 , 979570.000 , 978948.500 ,
978317.688 , 977677.625 , 977028.500 , 976370.062 , 975702.438 , 975025.625 ,
974339.750 , 973644.562 , 972940.250 , 972226.875 , 971504.188 , 970772.500 ,
970031.625 , 969281.625 , 968522.500 , 967754.188 , 966976.812 , 966190.375 ,
965394.875 , 964590.188 , 963776.500 , 962953.688 , 962121.812 , 961280.938 ,
960430.938 , 959571.938 , 958703.938 , 957826.875 , 956940.750 , 956045.688 ,
955141.625 , 954228.500 , 953306.500 , 952375.500 , 951435.500 , 950486.562 ,
949528.688 , 948561.875 , 947586.062 , 946601.375 , 945607.812 , 944605.375 ,
943594.000 , 942573.750 , 941544.562 , 940506.625 , 939459.750 , 938404.062 ,
937339.562 , 936266.250 , 935184.062 , 934093.125 , 932993.375 , 931884.812 ,
930767.562 , 929641.500 , 928506.688 , 927363.188 , 926210.812 , 925049.812 ,
923880.188 , 922701.688 , 921514.625 , 920318.875 , 919114.500 , 917901.375 ,
916679.750 , 915449.375 , 914210.438 , 912962.875 , 911706.688 , 910441.938 ,
909168.750 , 907886.875 , 906596.438 , 905297.438 , 903990.000 , 902674.000 ,
901349.562 , 900016.625 , 898675.188 , 897325.250 , 895966.938 , 894600.188 ,
893225.000 , 891841.438 , 890449.438 , 889049.062 , 887640.375 , 886223.250 ,
884797.812 , 883364.062 , 881922.125 , 880471.688 , 879013.062 , 877546.125 ,
876070.938 , 874587.500 , 873095.812 , 871595.938 , 870087.875 , 868571.562 ,
867047.062 , 865514.438 , 863973.688 , 862424.812 , 860867.812 , 859302.625 ,
857729.438 , 856148.188 , 854558.812 , 852961.438 , 851356.000 , 849742.562 ,
848121.312 , 846491.938 , 844854.562 , 843209.188 , 841555.938 , 839894.750 ,
838225.688 , 836548.688 , 834863.812 , 833171.125 , 831470.625 , 829762.250 ,
828046.000 , 826322.000 , 824590.250 , 822850.750 , 821103.438 , 819348.500 ,
817585.750 , 815815.375 , 814037.250 , 812251.688 , 810458.312 , 808657.312 ,
806848.625 , 805032.438 , 803208.625 , 801377.312 , 799538.375 , 797691.938 ,
795838.000 , 793976.562 , 792107.625 , 790231.312 , 788347.562 , 786456.312 ,
784557.688 , 782651.688 , 780738.312 , 778817.625 , 776889.562 , 774954.188 ,
773011.500 , 771061.750 , 769104.562 , 767140.125 , 765168.500 , 763189.625 ,
761203.562 , 759210.438 , 757210.062 , 755202.562 , 753188.000 , 751166.312 ,
749137.625 , 747101.812 , 745059.000 , 743009.125 , 740952.312 , 738888.562 ,
736817.750 , 734740.062 , 732655.438 , 730564.000 , 728465.750 , 726360.500 ,
724248.500 , 722129.500 , 720003.812 , 717871.438 , 715732.188 , 713586.188 ,
711433.500 , 709274.188 , 707108.125 , 704935.438 , 702756.125 , 700570.125 ,
698377.625 , 696178.438 , 693972.750 , 691760.625 , 689541.875 , 687316.625 ,
685085.000 , 682847.000 , 680602.500 , 678351.500 , 676094.188 , 673830.500 ,
671560.438 , 669284.062 , 667001.438 , 664712.438 , 662417.250 , 660115.812 ,
657808.188 , 655494.312 , 653174.250 , 650848.125 , 648515.875 , 646177.500 ,
643833.000 , 641482.500 , 639125.875 , 636763.250 , 634394.875 , 632020.375 ,
629639.875 , 627253.438 , 624861.125 , 622462.875 , 620058.812 , 617648.875 ,
615233.188 , 612811.688 , 610384.375 , 607951.375 , 605512.625 , 603068.188 ,
600618.062 , 598162.312 , 595700.875 , 593233.875 , 590761.250 , 588283.125 ,
585799.375 , 583310.188 , 580815.750 , 578315.562 , 575809.938 , 573298.938 ,
570782.500 , 568260.688 , 565733.562 , 563201.062 , 560663.312 , 558120.250 ,
555572.000 , 553018.375 , 550459.688 , 547895.812 , 545326.688 , 542752.500 ,
540173.188 , 537588.750 , 534999.312 , 532404.750 , 529805.312 , 527201.000 ,
524591.562 , 521977.188 , 519357.875 , 516733.656 , 514104.594 , 511470.688 ,
508831.969 , 506188.500 , 503540.219 , 500887.219 , 498229.500 , 495567.094 ,
492900.000 , 490228.281 , 487551.969 , 484871.062 , 482185.562 , 479495.562 ,
476801.000 , 474102.000 , 471398.531 , 468690.812 , 465978.469 , 463261.750 ,
460540.688 , 457815.250 , 455085.531 , 452351.531 , 449613.281 , 446870.812 ,
444124.094 , 441373.188 , 438618.188 , 435859.031 , 433095.750 , 430328.406 ,
427557.031 , 424781.594 , 422002.156 , 419218.781 , 416431.469 , 413640.188 ,
410845.281 , 408046.250 , 405243.406 , 402436.719 , 399626.281 , 396812.062 ,
393994.125 , 391172.438 , 388347.125 , 385518.094 , 382685.469 , 379849.250 ,
377009.438 , 374166.094 , 371319.219 , 368468.844 , 365615.000 , 362757.750 ,
359897.062 , 357032.969 , 354165.531 , 351294.969 , 348420.875 , 345543.531 ,
342662.906 , 339779.094 , 336892.031 , 334001.844 , 331108.469 , 328212.031 ,
325312.469 , 322409.844 , 319504.156 , 316595.531 , 313683.875 , 310769.281 ,
307851.750 , 304931.344 , 302008.062 , 299081.906 , 296152.969 , 293221.250 ,
290287.000 , 287349.750 , 284409.844 , 281467.219 , 278522.000 , 275574.094 ,
272623.625 , 269670.594 , 266715.031 , 263756.938 , 260796.375 , 257833.328 ,
254867.875 , 251900.047 , 248929.828 , 245957.266 , 242982.391 , 240005.219 ,
237025.797 , 234044.156 , 231060.297 , 228074.250 , 225086.312 , 222096.016 ,
219103.641 , 216109.172 , 213112.703 , 210114.203 , 207113.750 , 204111.328 ,
201106.984 , 198100.750 , 195092.641 , 192082.719 , 189070.984 , 186057.469 ,
183042.188 , 180025.188 , 177006.516 , 173986.156 , 170964.172 , 167940.562 ,
164915.391 , 161888.875 , 158860.625 , 155830.875 , 152799.656 , 149767.000 ,
146732.922 , 143697.469 , 140660.672 , 137622.547 , 134583.125 , 131542.438 ,
128500.523 , 125457.375 , 122413.062 , 119367.594 , 116321.008 , 113273.312 ,
110224.570 , 107174.773 , 104123.969 , 101072.203 , 98019.469 , 94966.047 ,
91911.500 , 88856.094 , 85799.844 , 82742.789 , 79684.953 , 76626.367 , 73567.062
, 70507.062 , 67446.406 , 64385.109 , 61323.203 , 58260.723 , 55197.695 ,
52134.145 , 49070.109 , 46005.605 , 42940.672 , 39875.336 , 36809.625 , 33743.562
, 30677.424 , 27610.758 , 24543.832 , 21476.676 , 18409.316 , 15341.785 ,
12274.107 , 9206.315 , 6138.437 , 3070.501 , 2.535 , -3065.430 , -6133.367 ,
-9201.245 , -12269.038 , -15336.715 , -18404.248 , -21471.607 , -24538.764 ,
-27605.689 , -30672.357 , -33738.492 , -36804.559 , -39870.270 , -42935.605 ,
-46000.539 , -49065.043 , -52129.082 , -55192.629 , -58255.660 , -61318.141 ,
-64380.043 , -67441.344 , -70502.008 , -73562.000 , -76621.312 , -79679.898 ,
-82737.734 , -85794.789 , -88851.039 , -91906.461 , -94961.000 , -98014.422 ,
-101067.148 , -104118.938 , -107169.734 , -110219.523 , -113268.281 , -116315.969
, -119362.562 , -122408.031 , -125452.352 , -128495.484 , -131537.406 ,
-134578.109 , -137617.531 , -140655.656 , -143692.469 , -146727.906 , -149761.969
, -152794.641 , -155825.859 , -158855.609 , -161883.875 , -164910.375 ,
-167935.562 , -170959.156 , -173981.156 , -177001.516 , -180020.219 , -183037.203
, -186052.484 , -189066.000 , -192077.734 , -195087.688 , -198095.781 ,
-201102.016 , -204106.359 , -207108.781 , -210109.250 , -213107.734 , -216104.219
, -219098.688 , -222091.062 , -225081.375 , -228069.328 , -231055.359 ,
-234039.219 , -237020.875 , -240000.312 , -242977.469 , -245952.359 , -248924.906
, -251895.125 , -254863.000 , -257828.438 , -260791.484 , -263752.031 ,
-266710.125 , -269665.719 , -272618.750 , -275569.219 , -278517.094 , -281462.375
, -284404.969 , -287344.906 , -290282.125 , -293216.406 , -296148.156 ,
-299077.094 , -302003.250 , -304926.500 , -307846.938 , -310764.469 , -313679.062
, -316590.688 , -319499.375 , -322405.031 , -325307.656 , -328207.219 ,
-331103.688 , -333997.031 , -336887.281 , -339774.312 , -342658.156 , -345538.750
, -348416.125 , -351290.219 , -354160.781 , -357028.219 , -359892.312 ,
-362753.000 , -365610.312 , -368464.156 , -371314.531 , -374161.406 , -377004.750
, -379844.562 , -382680.812 , -385513.438 , -388342.438 , -391167.781 ,
-393989.438 , -396807.406 , -399621.625 , -402432.094 , -405238.781 , -408041.625
, -410840.656 , -413635.594 , -416426.844 , -419214.188 , -421997.562 ,
-424777.000 , -427552.438 , -430323.844 , -433091.156 , -435854.438 , -438613.625
, -441368.656 , -444119.531 , -446866.250 , -449608.750 , -452347.000 ,
-455081.031 , -457810.750 , -460536.188 , -463257.281 , -465974.000 , -468686.344
, -471394.031 , -474097.562 , -476796.562 , -479491.125 , -482181.125 ,
-484866.625 , -487547.531 , -490223.875 , -492895.594 , -495562.688 , -498225.094
, -500882.812 , -503535.875 , -506184.094 , -508827.625 , -511466.312 ,
-514100.250 , -516729.281 , -519353.500 , -521972.844 , -524587.188 , -527196.688
, -529801.000 , -532400.500 , -534995.000 , -537584.500 , -540168.875 ,
-542748.188 , -545322.438 , -547891.500 , -550455.438 , -553014.250 , -555567.750
, -558116.000 , -560659.125 , -563196.875 , -565729.375 , -568256.500 ,
-570778.312 , -573294.750 , -575805.812 , -578311.375 , -580811.562 , -583306.062
, -585795.312 , -588279.000 , -590757.188 , -593229.750 , -595696.812 ,
-598158.250 , -600614.000 , -603064.125 , -605508.562 , -607947.375 , -610380.438
, -612807.688 , -615229.188 , -617644.875 , -620054.812 , -622458.938 ,
-624857.125 , -627249.500 , -629635.938 , -632016.438 , -634391.000 , -636759.375
, -639122.000 , -641478.625 , -643829.125 , -646173.625 , -648512.000 ,
-650844.250 , -653170.438 , -655490.500 , -657804.375 , -660112.000 , -662413.500
, -664708.688 , -666997.625 , -669280.312 , -671556.625 , -673826.750 ,
-676090.500 , -678347.812 , -680598.812 , -682843.312 , -685081.312 , -687312.938
, -689538.188 , -691756.875 , -693969.125 , -696174.812 , -698374.000 ,
-700566.500 , -702752.500 , -704931.875 , -707104.562 , -709270.625 , -711429.938
, -713582.688 , -715728.625 , -717867.875 , -720000.312 , -722126.062 ,
-724244.938 , -726357.062 , -728462.250 , -730560.500 , -732652.000 , -734736.625
, -736814.312 , -738885.125 , -740948.938 , -743005.750 , -745055.625 ,
-747098.438 , -749134.250 , -751163.000 , -753184.688 , -755199.250 , -757206.625
, -759206.938 , -761200.188 , -763186.188 , -765165.062 , -767136.750 ,
-769101.188 , -771058.375 , -773008.375 , -774951.000 , -776886.375 , -778814.438
, -780735.125 , -782648.500 , -784554.562 , -786453.188 , -788344.375 ,
-790228.188 , -792104.625 , -793973.500 , -795834.938 , -797688.875 , -799535.312
, -801374.250 , -803205.625 , -805029.375 , -806845.688 , -808654.312 ,
-810455.312 , -812248.688 , -814034.438 , -815812.562 , -817582.938 , -819345.688
, -821100.688 , -822848.000 , -824587.500 , -826319.312 , -828043.312 ,
-829759.500 , -831467.625 , -833168.188 , -834860.938 , -836545.750 , -838222.812
, -839891.938 , -841553.062 , -843206.375 , -844851.688 , -846489.062 ,
-848118.500 , -849739.938 , -851353.438 , -852958.812 , -854556.188 , -856145.562
, -857726.875 , -859300.062 , -860865.188 , -862422.250 , -863971.188 ,
-865511.938 , -867044.562 , -868569.000 , -870085.375 , -871593.438 , -873093.375
, -874585.062 , -876068.500 , -877543.688 , -879010.688 , -880469.312 ,
-881919.750 , -883361.812 , -884795.562 , -886221.000 , -887638.125 , -889046.875
, -890447.250 , -891839.250 , -893222.875 , -894598.062 , -895964.812 ,
-897322.938 , -898672.875 , -900014.312 , -901347.250 , -902671.750 , -903987.750
, -905295.250 , -906594.188 , -907884.625 , -909166.500 , -910439.812 ,
-911704.562 , -912960.688 , -914208.312 , -915447.312 , -916677.625 , -917899.375
, -919112.438 , -920316.875 , -921512.688 , -922699.812 , -923878.188 ,
-925047.938 , -926208.938 , -927361.250 , -928504.812 , -929639.625 , -930765.688
, -931883.062 , -932991.562 , -934091.312 , -935182.312 , -936264.438 ,
-937337.812 , -938402.375 , -939458.062 , -940504.938 , -941542.938 , -942572.062
, -943592.375 , -944603.750 , -945606.250 , -946599.812 , -947584.375 ,
-948560.188 , -949527.000 , -950484.938 , -951433.875 , -952373.875 , -953304.938
, -954227.000 , -955140.062 , -956044.188 , -956939.250 , -957825.375 ,
-958702.438 , -959570.438 , -960429.500 , -961279.500 , -962120.438 , -962952.312
, -963775.125 , -964588.812 , -965393.500 , -966189.062 , -966975.562 ,
-967752.938 , -968521.188 , -969280.375 , -970030.375 , -970771.312 , -971503.062
, -972225.688 , -972939.125 , -973643.438 , -974338.562 , -975024.562 ,
-975701.375 , -976368.938 , -977027.438 , -977676.625 , -978316.688 , -978947.438
, -979569.062 , -980181.438 , -980784.625 , -981378.438 , -981963.188 ,
-982538.562 , -983104.750 , -983661.688 , -984209.438 , -984747.812 , -985277.000
, -985796.875 , -986307.438 , -986808.750 , -987300.812 , -987783.562 ,
-988257.000 , -988721.125 , -989176.000 , -989621.438 , -990057.688 , -990484.625
, -990902.125 , -991310.375 , -991709.312 , -992098.875 , -992479.062 ,
-992850.000 , -993211.500 , -993563.688 , -993906.562 , -994240.062 , -994564.188
, -994878.938 , -995184.375 , -995480.438 , -995767.062 , -996044.375 ,
-996312.312 , -996570.812 , -996820.062 , -997059.812 , -997290.188 , -997511.188
, -997722.812 , -997925.062 , -998117.875 , -998301.312 , -998475.375 ,
-998640.000 , -998795.250 , -998941.125 , -999077.562 , -999204.562 , -999322.250
, -999430.500 , -999529.312 , -999618.688 , -999698.688 , -999769.312 ,
-999830.500 , -999882.250 , -999924.688 , -999957.625 , -999981.188 , -999995.312
, -1000000.000 , -999995.312 , -999981.250 , -999957.688 , -999924.750 ,
-999882.375 , -999830.688 , -999769.500 , -999698.938 , -999618.938 , -999529.562
, -999430.688 , -999322.562 , -999204.938 , -999077.875 , -998941.500 ,
-998795.625 , -998640.438 , -998475.812 , -998301.750 , -998118.312 , -997925.500
, -997723.312 , -997511.750 , -997290.750 , -997060.375 , -996820.625 ,
-996571.500 , -996313.000 , -996045.062 , -995767.750 , -995481.125 , -995185.125
, -994879.750 , -994565.000 , -994240.875 , -993907.375 , -993564.625 ,
-993212.375 , -992850.875 , -992480.062 , -992099.812 , -991710.250 , -991311.375
, -990903.125 , -990485.625 , -990058.750 , -989622.562 , -989177.062 ,
-988722.250 , -988258.188 , -987784.750 , -987302.000 , -986810.000 , -986308.750
, -985798.125 , -985278.312 , -984749.125 , -984210.812 , -983663.062 ,
-983106.188 , -982540.000 , -981964.562 , -981379.938 , -980786.062 , -980182.938
, -979570.625 , -978949.000 , -978318.188 , -977678.250 , -977029.000 ,
-976370.625 , -975703.062 , -975026.250 , -974340.312 , -973645.188 , -972940.938
, -972227.438 , -971504.875 , -970773.125 , -970032.188 , -969282.188 ,
-968523.062 , -967754.812 , -966977.500 , -966191.062 , -965395.500 , -964590.875
, -963777.125 , -962954.312 , -962122.500 , -961281.625 , -960431.625 ,
-959572.625 , -958704.562 , -957827.562 , -956941.500 , -956046.375 , -955142.312
, -954229.250 , -953307.188 , -952376.188 , -951436.250 , -950487.250 ,
-949529.438 , -948562.562 , -947586.812 , -946602.312 , -945608.750 , -944606.250
, -943594.875 , -942574.625 , -941545.500 , -940507.500 , -939460.688 ,
-938405.000 , -937340.500 , -936267.125 , -935185.000 , -934094.062 , -932994.312
, -931885.750 , -930768.500 , -929642.438 , -928507.625 , -927364.062 ,
-926211.750 , -925050.812 , -923881.125 , -922702.750 , -921515.625 , -920319.875
, -919115.500 , -917902.438 , -916680.688 , -915450.312 , -914211.375 ,
-912963.875 , -911707.688 , -910442.938 , -909169.688 , -907887.812 , -906597.375
, -905298.500 , -903991.000 , -902675.062 , -901350.562 , -900017.625 ,
-898676.188 , -897326.312 , -895968.188 , -894601.438 , -893226.250 , -891842.688
, -890450.688 , -889050.375 , -887641.625 , -886224.562 , -884799.125 ,
-883365.375 , -881923.312 , -880472.938 , -879014.250 , -877547.312 , -876072.188
, -874588.750 , -873097.062 , -871597.188 , -870089.125 , -868572.812 ,
-867048.375 , -865515.750 , -863975.000 , -862426.125 , -860869.062 , -859303.938
, -857730.750 , -856149.500 , -854560.125 , -852962.812 , -851357.312 ,
-849743.938 , -848122.562 , -846493.125 , -844855.812 , -843210.438 , -841557.188
, -839896.000 , -838226.938 , -836549.938 , -834865.062 , -833172.375 ,
-831471.875 , -829763.750 , -828047.562 , -826323.562 , -824591.812 , -822852.312
, -821105.062 , -819350.062 , -817587.375 , -815817.000 , -814038.875 ,
-812253.188 , -810459.812 , -808658.750 , -806850.125 , -805033.938 , -803210.125
, -801378.812 , -799539.875 , -797693.500 , -795839.562 , -793978.125 ,
-792109.188 , -790232.812 , -788349.062 , -786457.875 , -784559.250 , -782653.250
, -780739.875 , -778819.188 , -776891.188 , -774955.812 , -773013.125 ,
-771063.188 , -769106.000 , -767141.625 , -765170.000 , -763191.125 , -761205.062
, -759211.875 , -757211.562 , -755204.062 , -753189.500 , -751168.188 ,
-749139.438 , -747103.688 , -745060.875 , -743011.000 , -740954.250 , -738890.438
, -736819.625 , -734742.000 , -732657.375 , -730565.875 , -728467.438 ,
-726362.312 , -724250.188 , -722131.312 , -720005.625 , -717873.125 , -715733.938
, -713588.000 , -711435.312 , -709275.938 , -707109.938 , -704937.250 ,
-702757.875 , -700571.938 , -698379.375 , -696180.312 , -693974.625 , -691762.438
, -689543.750 , -687318.500 , -685086.875 , -682848.688 , -680604.188 ,
-678353.188 , -676095.875 , -673832.188 , -671562.125 , -669285.750 , -667003.125
, -664714.188 , -662418.938 , -660117.562 , -657810.250 , -655496.438 ,
-653176.438 , -650850.250 , -648517.938 , -646179.562 , -643835.125 , -641484.625
, -639128.000 , -636765.438 , -634396.875 , -632022.312 , -629641.812 ,
-627255.375 , -624863.062 , -622464.875 , -620060.812 , -617650.938 , -615235.188
, -612813.688 , -610386.438 , -607953.375 , -605514.625 , -603070.188 ,
-600620.062 , -598164.312 , -595702.875 , -593235.938 , -590763.312 , -588285.125
, -585801.500 , -583312.250 , -580817.562 , -578317.375 , -575811.812 ,
-573300.750 , -570784.375 , -568262.562 , -565735.438 , -563203.000 , -560665.188
, -558122.188 , -555574.250 , -553020.688 , -550462.000 , -547898.062 ,
-545329.062 , -542754.812 , -540175.500 , -537591.125 , -535001.625 , -532407.188
, -529807.625 , -527203.125 , -524593.688 , -521979.344 , -519360.000 ,
-516735.844 , -514106.750 , -511472.875 , -508834.188 , -506190.656 , -503542.438
, -500889.406 , -498231.688 , -495569.281 , -492902.219 , -490230.500 ,
-487554.188 , -484873.250 , -482187.812 , -479497.781 , -476803.250 , -474104.219
, -471400.781 , -468692.844 , -465980.500 , -463263.812 , -460542.719 ,
-457817.312 , -455087.594 , -452353.594 , -449615.344 , -446872.844 , -444126.156
, -441375.688 , -438620.656 , -435861.500 , -433098.250 , -430330.906 ,
-427559.531 , -424784.094 , -422004.688 , -419221.312 , -416434.000 , -413642.719
, -410847.562 , -408048.562 , -405245.719 , -402439.062 , -399628.625 ,
-396814.375 , -393996.438 , -391174.781 , -388349.438 , -385520.469 , -382687.844
, -379851.625 , -377011.812 , -374168.469 , -371321.594 , -368471.219 ,
-365617.375 , -362760.094 , -359899.406 , -357035.344 , -354167.875 , -351297.125
, -348423.031 , -345545.688 , -342665.062 , -339781.219 , -336894.188 ,
-334004.000 , -331110.656 , -328214.156 , -325314.625 , -322412.000 , -319506.781
, -316598.156 , -313686.531 , -310771.906 , -307854.406 , -304934.000 ,
-302010.719 , -299084.562 , -296155.625 , -293223.906 , -290289.406 , -287352.219
, -284412.250 , -281469.688 , -278524.406 , -275576.531 , -272626.062 ,
-269673.062 , -266717.469 , -263759.375 , -260798.812 , -257835.812 , -254870.359
, -251902.484 , -248932.281 , -245959.734 , -242984.844 , -240007.688 ,
-237028.266 , -234046.609 , -231062.750 , -228076.719 , -225088.547 , -222098.266
, -219105.875 , -216111.422 , -213114.938 , -210116.453 , -207115.984 ,
-204113.578 , -201109.234 , -198103.000 , -195094.891 , -192085.438 , -189073.719
, -186060.188 , -183044.906 , -180027.938 , -177009.234 , -173988.875 ,
-170966.891 , -167943.297 , -164918.109 , -161891.391 , -158863.125 , -155833.375
, -152802.156 , -149769.500 , -146735.438 , -143699.984 , -140663.172 ,
-137625.047 , -134585.641 , -131544.953 , -128503.023 , -125459.898 , -122415.578
, -119370.109 , -116323.523 , -113275.836 , -110227.086 , -107177.297 ,
-104126.500 , -101074.719 , -98021.992 , -94968.336 , -91913.789 , -88858.383 ,
-85802.133 , -82745.078 , -79687.242 , -76628.656 , -73569.352 , -70509.352 ,
-67448.688 , -64387.871 , -61325.973 , -58263.492 , -55200.465 , -52136.918 ,
-49072.875 , -46008.379 , -42943.445 , -39878.109 , -36812.395 , -33746.336 ,
-30679.957 , -27613.293 , -24546.365 , -21479.209 , -18411.852 , -15344.320 ,
-12276.643 , -9208.852 , -6140.973 , -3073.036 , -5.070};