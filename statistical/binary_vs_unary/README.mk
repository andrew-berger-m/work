# Unary Versus Binary (n++ or n = n + 1)

Recently, I have got question what is faster in in C/C++.. n++ or n = n + 1? Basically, this is very complex question and it is not easy to answer. The program demonstrates a way how could you find out what is faster in C/C++. Just launch it on your Linux. My results are bellow.
The program could be adjusted for another tests e. g. n = n * 7 or n = n << 3 - n etc.

Note: Output from Kolmogorov-Smirnov Comparison Test And Analysis is coming from the website: http://www.physics.csbsju.edu/stats/KS-test.n.plot_form.html

# Mistakes in measurements

## Mistakes in measurements
- writing results into memory
- calling system function gettimeofday between tests
- wrong location of function unary and binary in compiled code, I hope this will not happen
- comparing float variables with the same time value could be miseading
- so, we will launch 500 tests to get strong results

## Mistakes elimination in measurements
- setting priority for proces to high
- giving system time to change priority level
- launching first loop without measurement
- not writing anything into console
- launching measured functions in 100.0000.000 cycles
- measuring loop time to make sure results are comparable
- comparing results "per partes", not all of them together

# Results

1. Based on the test, I could say: unaryRegister is faster than binaryRegister on my processor and testing program.
1. Based on the test, I could say: binaryMemory is faster than unaryMemory on my processor and testing program.
1. Based on the test, I could say: Operations with registry are faster than operation with memory on my processor and testing program in these two cases.

Do you agree with me?

# Kolmogorov-Smirnov Comparison Test And Analysis

Kolmogorov-Smirnov Comparison of Two Data Sets
The results of a Kolmogorov-Smirnov test performed at 00:30 on 19-NOV-2018
The maximum difference between the cumulative distributions, D, is: 0.9920 with a corresponding P of: 0.000

Data Set 1:
500 data points were entered
Mean = 0.1129
95% confidence interval for actual Mean: 0.1126 thru 0.1133
Standard Deviation = 3.874E-03
High = 0.131 Low = 0.107
Third Quartile = 0.115 First Quartile = 0.110
Median = 0.1118
Average Absolute Deviation from Median = 2.747E-03

KS says it's unlikely this data is normally distributed: P= 0.00 where the normal distribution has mean= 0.1157 and sdev= 4.1997E-03

KS says it's unlikely this data is log normally distributed: P= 0.00 where the log normal distribution has geometric mean= 0.1154 and multiplicative sdev= 1.036

Data Set 2:
500 data points were entered
Mean = 0.1322
95% confidence interval for actual Mean: 0.1319 thru 0.1325
Standard Deviation = 3.459E-03
High = 0.150 Low = 0.129
Third Quartile = 0.133 First Quartile = 0.130
Median = 0.1306
Average Absolute Deviation from Median = 2.275E-03

KS says it's unlikely this data is normally distributed: P= 0.00 where the normal distribution has mean= 0.1352 and sdev= 3.7276E-03

KS says it's unlikely this data is log normally distributed: P= 0.00 where the log normal distribution has geometric mean= 0.1350 and multiplicative sdev= 1.027

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Kolmogorov-Smirnov Comparison of Two Data Sets
The results of a Kolmogorov-Smirnov test performed at 00:31 on 19-NOV-2018
The maximum difference between the cumulative distributions, D, is: 0.8380 with a corresponding P of: 0.000

Data Set 1:
500 data points were entered
Mean = 0.2105
95% confidence interval for actual Mean: 0.2100 thru 0.2109
Standard Deviation = 4.952E-03
High = 0.230 Low = 0.204
Third Quartile = 0.212 First Quartile = 0.207
Median = 0.2084
Average Absolute Deviation from Median = 3.462E-03

KS says it's unlikely this data is normally distributed: P= 0.00 where the normal distribution has mean= 0.2133 and sdev= 4.5441E-03

KS says it's unlikely this data is log normally distributed: P= 0.00 where the log normal distribution has geometric mean= 0.2131 and multiplicative sdev= 1.021

Data Set 2:
500 data points were entered
Mean = 0.2009
95% confidence interval for actual Mean: 0.2005 thru 0.2013
Standard Deviation = 4.585E-03
High = 0.219 Low = 0.195
Third Quartile = 0.202 First Quartile = 0.198
Median = 0.1992
Average Absolute Deviation from Median = 3.157E-03

KS says it's unlikely this data is normally distributed: P= 0.00 where the normal distribution has mean= 0.2035 and sdev= 4.2737E-03

KS says it's unlikely this data is log normally distributed: P= 0.00 where the log normal distribution has geometric mean= 0.2033 and multiplicative sdev= 1.021

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Program Output

---------------- Starting 500 tests

---------------- Measured data

Unary via register:

0.114749 0.118614 0.114669 0.119025 0.130393 0.112519 0.114154 0.109661 0.114500 0.116355 0.115443 0.113183 0.109069 0.111541 0.121399 0.117286 0.125579 0.113178 0.115677 0.117749 0.112643 0.122847 0.110105 0.114636 0.111551 0.112133 0.113729 0.114134 0.109294 0.108951 0.115277 0.114968 0.118221 0.115847 0.113241 0.113983 0.114895 0.122457 0.120836 0.127746 0.130277 0.117195 0.110349 0.119108 0.129938 0.117073 0.127733 0.109895 0.110151 0.109425 0.118209 0.110149 0.109317 0.110710 0.112387 0.115374 0.112398 0.112400 0.111884 0.110896 0.109865 0.113154 0.112013 0.107772 0.115590 0.109874 0.112542 0.108562 0.111058 0.109978 0.112352 0.111103 0.110719 0.109534 0.109896 0.109457 0.115866 0.109000 0.109155 0.112536 0.109319 0.116640 0.110531 0.111062 0.111909 0.110026 0.110257 0.110514 0.110597 0.109526 0.110261 0.111197 0.112028 0.109651 0.109597 0.120056 0.112295 0.112608 0.109245 0.109421 0.110176 0.109318 0.113678 0.108180 0.111250 0.122632 0.123633 0.113154 0.113928 0.110727 0.110849 0.110262 0.112125 0.116093 0.111213 0.113672 0.110832 0.110241 0.111177 0.113253 0.109911 0.115817 0.116193 0.115201 0.113013 0.111625 0.111822 0.113239 0.110634 0.114749 0.112456 0.114258 0.111179 0.109511 0.114186 0.109982 0.112530 0.111196 0.112432 0.114908 0.109991 0.111303 0.110967 0.109087 0.109493 0.110912 0.109226 0.109438 0.109691 0.116992 0.109492 0.113814 0.110577 0.111930 0.110020 0.110992 0.111975 0.108796 0.109784 0.111692 0.111165 0.111326 0.108989 0.112870 0.113264 0.111911 0.111759 0.110558 0.110306 0.111099 0.112331 0.119398 0.110560 0.111052 0.111548 0.108733 0.110794 0.108364 0.111622 0.111559 0.114782 0.113669 0.109162 0.112472 0.115434 0.114707 0.116262 0.110128 0.110758 0.111189 0.110445 0.118440 0.111656 0.112347 0.117213 0.119517 0.120340 0.121713 0.118680 0.118450 0.108171 0.108967 0.109933 0.111968 0.109800 0.113048 0.112070 0.110928 0.115407 0.110814 0.112679 0.111789 0.121192 0.114555 0.109423 0.112391 0.116957 0.113872 0.112076 0.111039 0.109999 0.110561 0.110356 0.114383 0.112026 0.111501 0.111162 0.112251 0.111510 0.113958 0.114684 0.111973 0.114585 0.109224 0.113907 0.111556 0.111517 0.109871 0.111933 0.113781 0.110766 0.118638 0.117845 0.119222 0.118735 0.118471 0.111369 0.112584 0.115042 0.110762 0.113139 0.123082 0.119949 0.118839 0.119788 0.111552 0.111737 0.115902 0.110903 0.110194 0.112716 0.121702 0.122400 0.123711 0.119569 0.113029 0.111870 0.113778 0.115312 0.114413 0.120446 0.120262 0.124117 0.119048 0.118413 0.114318 0.113555 0.109732 0.111439 0.111038 0.112290 0.111249 0.113237 0.113571 0.108823 0.110499 0.109653 0.110457 0.111767 0.111725 0.108300 0.111435 0.110207 0.109344 0.109648 0.111191 0.113960 0.109329 0.111918 0.108353 0.114455 0.112122 0.112023 0.112056 0.113344 0.112752 0.113991 0.112153 0.110776 0.112133 0.110431 0.112039 0.108437 0.112033 0.111374 0.110092 0.114213 0.110131 0.109125 0.108705 0.110133 0.109893 0.109526 0.110663 0.111955 0.110404 0.112367 0.110251 0.112039 0.112012 0.107317 0.110304 0.108598 0.109522 0.109218 0.108966 0.110221 0.111931 0.112920 0.112523 0.111613 0.108272 0.112553 0.110744 0.109959 0.111092 0.109875 0.120631 0.118921 0.118521 0.117902 0.118824 0.110583 0.110655 0.110914 0.111608 0.108635 0.110750 0.111176 0.111230 0.112010 0.109052 0.112798 0.112962 0.112390 0.109601 0.111080 0.112102 0.111110 0.109838 0.108277 0.109508 0.108324 0.109584 0.108852 0.114170 0.110147 0.110170 0.109352 0.113618 0.110263 0.109502 0.111625 0.110970 0.116447 0.110740 0.109966 0.109793 0.109967 0.114886 0.109317 0.109597 0.109746 0.117004 0.118442 0.120971 0.119610 0.119116 0.111838 0.108485 0.108586 0.113393 0.110194 0.121210 0.118485 0.119259 0.118793 0.114775 0.110129 0.110165 0.110739 0.110237 0.116679 0.113757 0.114176 0.112927 0.115600 0.118300 0.116493 0.111363 0.109333 0.111016 0.110173 0.112801 0.114031 0.109109 0.110030 0.108625 0.116849 0.130572 0.117947 0.115536 0.119479 0.113729 0.113207 0.117528 0.116045 0.115033 0.111040 0.111063 0.115370 0.110441 0.114011 0.110119 0.111141 0.110338 0.113971 0.115448 0.109002 0.110491 0.109628 0.109864 0.114400 0.112773 0.111203 0.110386 0.112716 0.115935 0.112882 0.108127 0.116596 0.118247 0.118176 0.111918 0.110383 0.109157 0.116554 0.118863 0.118325 0.110934 0.109193 0.116954 0.115346 0.119679 0.113665 0.111422 0.110116 0.108578 0.110193 0.115049 0.112076 0.111349 0.112199 0.115159 0.118093 0.109792 0.110778 0.110105 0.110823 0.111633 0.110690 0.108880 0.109409 0.113141 0.111636 0.111459 0.112629 0.109535 0.110707 0.110542

Statistics: colected samples: 500, arithmetical average: 0.112939

Binary via register:

0.133897 0.143235 0.133099 0.140967 0.136192 0.131107 0.129748 0.129774 0.131271 0.134543 0.129271 0.130973 0.130381 0.129619 0.138668 0.141273 0.134337 0.132819 0.132563 0.138598 0.137301 0.130442 0.132030 0.132710 0.130415 0.130107 0.133001 0.131327 0.131035 0.130115 0.133500 0.134610 0.137675 0.130249 0.133402 0.135539 0.130775 0.133999 0.143240 0.146458 0.146089 0.135746 0.136356 0.139379 0.149753 0.135686 0.147469 0.129905 0.131585 0.129664 0.132476 0.131387 0.129792 0.129861 0.129608 0.132095 0.129330 0.130414 0.129483 0.130815 0.135626 0.130775 0.144390 0.129129 0.136314 0.135969 0.130226 0.131671 0.129971 0.130087 0.129631 0.130379 0.131180 0.129980 0.130624 0.130519 0.130280 0.131238 0.130719 0.129471 0.130148 0.138094 0.129927 0.130344 0.130469 0.130296 0.131206 0.130039 0.129576 0.131974 0.130814 0.131310 0.129702 0.129840 0.130124 0.139914 0.132395 0.131358 0.130007 0.129967 0.129848 0.136497 0.129935 0.130456 0.133753 0.140635 0.141507 0.135673 0.130561 0.131325 0.137630 0.130155 0.132093 0.130781 0.131471 0.130991 0.130316 0.130455 0.131250 0.129701 0.130014 0.136393 0.135972 0.136490 0.130369 0.129781 0.129784 0.129742 0.132954 0.129774 0.129551 0.130421 0.129917 0.130247 0.130779 0.130111 0.130590 0.129171 0.133218 0.131546 0.129507 0.130074 0.131154 0.130162 0.131429 0.130909 0.130167 0.129896 0.130098 0.134968 0.130029 0.129448 0.130142 0.132281 0.136444 0.130003 0.129930 0.130490 0.130798 0.130229 0.130207 0.129600 0.130034 0.130005 0.130679 0.131471 0.130333 0.130309 0.129844 0.131091 0.131311 0.129918 0.129567 0.129837 0.130965 0.132967 0.130050 0.130493 0.129160 0.131340 0.134194 0.129372 0.129589 0.129099 0.136598 0.136151 0.130960 0.130426 0.130970 0.130564 0.132429 0.132154 0.129964 0.129160 0.130839 0.139386 0.139757 0.140870 0.139797 0.139814 0.129450 0.129966 0.130010 0.129866 0.136529 0.129903 0.131448 0.132879 0.129885 0.129980 0.131802 0.130429 0.131122 0.132070 0.129141 0.129282 0.129916 0.131618 0.132968 0.130014 0.129947 0.129479 0.129459 0.134654 0.130043 0.130253 0.130506 0.129052 0.130903 0.131389 0.129353 0.128893 0.129322 0.131782 0.129829 0.130557 0.130032 0.130100 0.133269 0.130093 0.130365 0.139310 0.139026 0.139306 0.138558 0.139320 0.130900 0.129721 0.130504 0.129924 0.131714 0.139263 0.139105 0.139391 0.138811 0.139037 0.131275 0.130359 0.129263 0.129945 0.130156 0.138834 0.138994 0.139333 0.139089 0.136093 0.130196 0.130516 0.134757 0.130639 0.129750 0.139312 0.138895 0.136898 0.139374 0.131247 0.129795 0.129531 0.129698 0.130534 0.131534 0.130868 0.129545 0.130140 0.130175 0.132252 0.129916 0.130063 0.129545 0.131760 0.131413 0.131047 0.129880 0.129744 0.129543 0.131373 0.131042 0.131406 0.129506 0.128941 0.135821 0.130006 0.130664 0.129515 0.129492 0.133183 0.129685 0.129943 0.129751 0.130078 0.130166 0.129849 0.130195 0.129566 0.131783 0.132555 0.131622 0.130473 0.130975 0.130867 0.133286 0.134938 0.129842 0.130592 0.130019 0.130166 0.133464 0.129448 0.129924 0.129488 0.131099 0.133583 0.130756 0.130337 0.130007 0.130532 0.131036 0.130150 0.129567 0.129788 0.131338 0.131504 0.130004 0.129833 0.129951 0.129736 0.132951 0.139207 0.139602 0.138918 0.139045 0.139082 0.132111 0.131555 0.130094 0.129757 0.130341 0.130121 0.131517 0.130153 0.129907 0.130624 0.131447 0.133889 0.130533 0.130260 0.129879 0.129679 0.134862 0.130222 0.130147 0.130564 0.130963 0.129752 0.129948 0.129289 0.129000 0.129698 0.134372 0.130471 0.129678 0.130715 0.131316 0.133025 0.130677 0.129963 0.130581 0.129732 0.129947 0.131861 0.130029 0.129927 0.129945 0.139259 0.139314 0.140191 0.139217 0.138570 0.129522 0.130692 0.133184 0.130050 0.130281 0.139500 0.139274 0.139274 0.140012 0.138172 0.129985 0.130080 0.129990 0.130133 0.136018 0.134178 0.133155 0.133097 0.133271 0.136350 0.133808 0.130265 0.129813 0.130256 0.130027 0.136875 0.130468 0.130395 0.129345 0.130574 0.135292 0.134328 0.135725 0.134422 0.135470 0.133414 0.133620 0.135885 0.134119 0.132630 0.129654 0.130286 0.133596 0.133456 0.128510 0.128949 0.129864 0.129675 0.135476 0.129705 0.129886 0.130608 0.130119 0.131594 0.130080 0.129588 0.129789 0.132839 0.131275 0.130575 0.129733 0.130181 0.132138 0.136406 0.133311 0.129996 0.134715 0.129592 0.137043 0.136422 0.131431 0.129844 0.137221 0.136553 0.136725 0.135585 0.129717 0.130265 0.130118 0.131238 0.131357 0.129926 0.129884 0.130281 0.130750 0.136296 0.131678 0.129818 0.130420 0.130876 0.129658 0.134478 0.130444 0.130559 0.130177 0.130292 0.133669 0.129239 0.129741 0.129818 0.132267 0.135128

Statistics: colected samples: 500, arithmetical average: 0.132207

Unary via memory:

0.208801 0.222281 0.210656 0.217294 0.208626 0.208318 0.215704 0.207779 0.213154 0.206440 0.205569 0.207430 0.208584 0.210269 0.216991 0.211731 0.209280 0.212319 0.223720 0.210743 0.208773 0.210169 0.207048 0.210442 0.206763 0.211387 0.209087 0.209084 0.213633 0.208714 0.213194 0.212183 0.211879 0.223156 0.220408 0.210610 0.211603 0.230319 0.224895 0.220430 0.222617 0.214114 0.219461 0.207470 0.210315 0.208474 0.208638 0.210628 0.208554 0.209369 0.210755 0.208875 0.210309 0.207894 0.206636 0.208027 0.206007 0.210291 0.206859 0.207568 0.207691 0.208703 0.211661 0.213004 0.207374 0.213058 0.205815 0.206889 0.207368 0.208669 0.208112 0.207642 0.206819 0.210801 0.206959 0.206282 0.207972 0.211612 0.210338 0.207256 0.208006 0.207809 0.206741 0.209941 0.208890 0.208972 0.206120 0.208004 0.207942 0.207676 0.204920 0.206343 0.207827 0.209586 0.209965 0.207776 0.206265 0.208793 0.209146 0.210132 0.207382 0.207990 0.209526 0.217362 0.215999 0.214529 0.221590 0.205872 0.208917 0.209355 0.212657 0.212105 0.207790 0.206488 0.208476 0.213336 0.207370 0.206500 0.207131 0.216450 0.217080 0.207004 0.207259 0.207240 0.216644 0.206053 0.210100 0.206490 0.206951 0.208777 0.209619 0.210871 0.207864 0.207727 0.208500 0.207876 0.213048 0.206284 0.209159 0.208165 0.214219 0.214855 0.210612 0.208500 0.207336 0.214124 0.208879 0.208552 0.206875 0.206901 0.206207 0.219723 0.211057 0.208234 0.206456 0.206294 0.212768 0.212309 0.208399 0.206449 0.206244 0.206540 0.209745 0.207277 0.206514 0.207248 0.205987 0.211261 0.208946 0.206515 0.208159 0.207087 0.210798 0.206455 0.208105 0.207104 0.207221 0.211124 0.208788 0.207736 0.207234 0.207214 0.216993 0.209598 0.207934 0.206429 0.206803 0.216851 0.212945 0.209136 0.207899 0.204917 0.213657 0.214612 0.216022 0.222633 0.220906 0.219976 0.222133 0.208096 0.212739 0.208272 0.206639 0.208405 0.209956 0.210351 0.206780 0.206990 0.207245 0.208599 0.209670 0.206878 0.207098 0.207644 0.205594 0.208373 0.207976 0.207614 0.208700 0.209516 0.210992 0.207667 0.209139 0.206553 0.207753 0.207413 0.209098 0.204844 0.204295 0.205298 0.215411 0.210266 0.207083 0.205220 0.208183 0.207345 0.207152 0.206736 0.207289 0.208050 0.220364 0.221899 0.224021 0.224200 0.221959 0.208283 0.207584 0.208222 0.208434 0.207746 0.220466 0.222301 0.222290 0.220231 0.223028 0.207370 0.207798 0.205466 0.206578 0.210795 0.222149 0.221591 0.222244 0.220125 0.221746 0.211016 0.209174 0.207906 0.206466 0.206324 0.221227 0.222620 0.221827 0.221706 0.219921 0.207932 0.205326 0.210466 0.206103 0.207166 0.206447 0.206169 0.208499 0.207256 0.206971 0.206944 0.206949 0.212821 0.207629 0.206670 0.207449 0.206562 0.209106 0.207781 0.207277 0.206069 0.206291 0.212246 0.208448 0.206624 0.207503 0.206854 0.205777 0.208481 0.209017 0.207746 0.207426 0.205193 0.210115 0.207982 0.206342 0.208347 0.206954 0.211380 0.207508 0.212148 0.206637 0.209635 0.211523 0.207825 0.207462 0.207238 0.205182 0.209634 0.206369 0.206905 0.206464 0.205634 0.211465 0.206954 0.207006 0.206391 0.207083 0.213954 0.209842 0.207608 0.205184 0.205875 0.208665 0.211017 0.207635 0.205369 0.204687 0.208051 0.208274 0.205433 0.211693 0.223433 0.220994 0.223099 0.222485 0.208084 0.206331 0.206304 0.207762 0.211215 0.207550 0.207147 0.206160 0.205913 0.211855 0.209589 0.206299 0.207434 0.206510 0.211030 0.209771 0.207544 0.206337 0.207248 0.207905 0.208883 0.206206 0.206915 0.205851 0.208221 0.209864 0.207637 0.206862 0.206738 0.211927 0.213153 0.206865 0.207199 0.207032 0.209174 0.215655 0.207334 0.205952 0.207181 0.205455 0.211704 0.221882 0.221458 0.221251 0.221213 0.222610 0.206778 0.209331 0.207920 0.205651 0.207443 0.222838 0.221254 0.222683 0.219931 0.220705 0.206847 0.205792 0.209671 0.207025 0.217260 0.215431 0.217548 0.217484 0.217520 0.214077 0.211882 0.211270 0.218676 0.216491 0.211452 0.210818 0.209130 0.207433 0.217462 0.215693 0.215572 0.222392 0.224934 0.221176 0.220521 0.217100 0.215258 0.218501 0.213143 0.215273 0.211941 0.217343 0.212857 0.207411 0.214788 0.209896 0.213799 0.214321 0.210200 0.207931 0.205148 0.210797 0.210517 0.206175 0.204959 0.207315 0.206220 0.212329 0.206430 0.206864 0.208496 0.213670 0.215748 0.207143 0.207810 0.209053 0.217247 0.216791 0.212072 0.208049 0.208254 0.218332 0.216494 0.214214 0.207916 0.207857 0.208302 0.207129 0.208925 0.211828 0.208273 0.207500 0.207634 0.208214 0.213364 0.207742 0.206786 0.209074 0.206753 0.212001 0.208295 0.207494 0.206264 0.213251 0.217143 0.208185 0.207660 0.207124 0.206275 0.211899 0.208904 0.204593 0.207714

Statistics: collected samples: 500, arithmetical average: 0.210478

Binary via memory:

0.200772 0.209184 0.200113 0.204172 0.200337 0.201498 0.197911 0.197863 0.203779 0.197903 0.198699 0.201377 0.198673 0.201895 0.201787 0.200820 0.202531 0.201005 0.204085 0.200693 0.194715 0.210675 0.199860 0.199501 0.198803 0.201387 0.201688 0.209623 0.201312 0.198547 0.200591 0.197603 0.200460 0.199682 0.203310 0.209080 0.197357 0.206854 0.200949 0.214545 0.214428 0.204693 0.211848 0.196104 0.209089 0.201662 0.206056 0.197795 0.199288 0.198738 0.198493 0.203119 0.199147 0.197338 0.199356 0.198794 0.199290 0.200753 0.199052 0.199089 0.197245 0.198804 0.200703 0.199210 0.198511 0.198252 0.196388 0.200029 0.196768 0.197621 0.197384 0.197445 0.203142 0.197597 0.200282 0.197980 0.200564 0.198132 0.196821 0.198267 0.198836 0.196609 0.202610 0.199729 0.198241 0.196981 0.197355 0.198831 0.197683 0.198833 0.197227 0.198018 0.200761 0.200771 0.198029 0.199363 0.199714 0.198048 0.199456 0.197685 0.198185 0.199111 0.201911 0.202266 0.203720 0.201385 0.212491 0.198093 0.200418 0.202506 0.198156 0.197704 0.198673 0.198535 0.204030 0.195180 0.199983 0.196640 0.197818 0.206238 0.198310 0.195570 0.203879 0.199236 0.207292 0.198444 0.197366 0.194740 0.198535 0.196292 0.197924 0.200883 0.199092 0.198861 0.197403 0.200066 0.202886 0.198894 0.198457 0.203397 0.203630 0.198139 0.198036 0.199336 0.198425 0.208632 0.199962 0.197976 0.197643 0.202523 0.206989 0.210767 0.197092 0.197278 0.198690 0.198824 0.203788 0.198052 0.196964 0.197834 0.195313 0.197474 0.195024 0.197570 0.197894 0.197016 0.202504 0.196894 0.196948 0.198437 0.198431 0.201433 0.197028 0.200023 0.200106 0.197355 0.198990 0.199941 0.198079 0.195669 0.199976 0.206367 0.197686 0.197465 0.200068 0.202611 0.199752 0.204131 0.198256 0.198490 0.200313 0.197994 0.203937 0.197430 0.195297 0.211241 0.212253 0.211266 0.210175 0.209700 0.197983 0.197210 0.195617 0.198247 0.201912 0.198554 0.197820 0.198129 0.197293 0.201164 0.199013 0.200366 0.200700 0.197908 0.204008 0.198984 0.196568 0.197393 0.198468 0.204064 0.197983 0.196241 0.195605 0.197965 0.201877 0.197693 0.197354 0.197904 0.198366 0.198707 0.199392 0.195755 0.198327 0.196340 0.200464 0.200120 0.197420 0.197774 0.199010 0.200186 0.204464 0.211678 0.214164 0.211525 0.213299 0.197463 0.203077 0.196831 0.196960 0.197473 0.210659 0.211999 0.211506 0.209868 0.211168 0.196963 0.197294 0.200291 0.200129 0.196257 0.213656 0.210352 0.212140 0.211148 0.211876 0.200661 0.197315 0.196805 0.196422 0.203773 0.211205 0.213094 0.211596 0.211297 0.212709 0.198447 0.203413 0.197293 0.197796 0.197989 0.197262 0.200761 0.198305 0.196021 0.197320 0.198802 0.201992 0.198531 0.196996 0.199191 0.199115 0.201710 0.199041 0.197928 0.198409 0.201336 0.204249 0.200848 0.197205 0.196317 0.198449 0.200466 0.199471 0.200150 0.197380 0.199198 0.197570 0.201267 0.199083 0.198171 0.197049 0.197432 0.202032 0.197254 0.197930 0.197925 0.198389 0.204030 0.198681 0.200123 0.200533 0.200163 0.203590 0.198421 0.200302 0.198898 0.197249 0.198353 0.195696 0.197552 0.198759 0.198128 0.201405 0.199161 0.197607 0.196499 0.199782 0.200191 0.200129 0.198873 0.198085 0.198693 0.197798 0.202311 0.196822 0.197785 0.197923 0.212749 0.210852 0.213869 0.212980 0.214488 0.197043 0.198784 0.201390 0.198690 0.200052 0.199375 0.199035 0.200353 0.199044 0.198395 0.196909 0.199880 0.198865 0.199253 0.198608 0.198630 0.199694 0.198739 0.198876 0.199188 0.199638 0.199495 0.200630 0.204310 0.197364 0.198974 0.198980 0.200874 0.203982 0.197974 0.198289 0.199213 0.199914 0.206344 0.198107 0.200491 0.198944 0.197785 0.201333 0.198467 0.202743 0.210870 0.212962 0.214567 0.212985 0.202796 0.199049 0.199498 0.197863 0.204647 0.206483 0.213250 0.212493 0.211178 0.212065 0.198162 0.202611 0.197569 0.199311 0.205585 0.211267 0.211189 0.206597 0.205205 0.205201 0.205263 0.200879 0.206908 0.198789 0.196586 0.202883 0.197799 0.207523 0.203455 0.201298 0.201849 0.209634 0.218783 0.211114 0.209050 0.208014 0.204558 0.207815 0.204802 0.203435 0.207007 0.203313 0.196776 0.200888 0.200863 0.199997 0.200555 0.199495 0.200252 0.201252 0.199029 0.200637 0.196467 0.196853 0.196944 0.195686 0.202086 0.198976 0.197656 0.198256 0.204585 0.204059 0.197746 0.196173 0.203119 0.206204 0.206004 0.201316 0.198749 0.198356 0.206798 0.206650 0.206215 0.197847 0.198798 0.197756 0.198983 0.197335 0.200945 0.199725 0.197351 0.197715 0.199632 0.202054 0.198724 0.198459 0.202366 0.199625 0.201775 0.200204 0.198009 0.199447 0.198188 0.208474 0.197445 0.199078 0.196813 0.195719 0.202151 0.196261 0.197547 0.196795 0.199118

Statistics: collected samples: 500, arithmetical average: 0.200936

Loop:

0.138040 0.142472 0.136465 0.136269 0.134719 0.134222 0.137600 0.140342 0.142296 0.133198 0.133180 0.133354 0.133666 0.136848 0.140438 0.135930 0.138734 0.134669 0.140678 0.136770 0.135779 0.133322 0.134773 0.137844 0.134705 0.134133 0.133295 0.138063 0.133158 0.138594 0.139433 0.145143 0.139823 0.139270 0.143533 0.138367 0.133487 0.152041 0.149184 0.154926 0.137662 0.135872 0.144658 0.144385 0.134873 0.152230 0.134519 0.133935 0.138966 0.134496 0.137459 0.134223 0.132980 0.134384 0.132922 0.132509 0.135496 0.134888 0.132947 0.132909 0.133089 0.134250 0.133664 0.139792 0.135067 0.133102 0.133362 0.132850 0.133738 0.135555 0.133031 0.133290 0.133605 0.132940 0.134912 0.133654 0.135586 0.133233 0.133717 0.133767 0.133794 0.133786 0.133269 0.133433 0.135450 0.132587 0.132851 0.133338 0.133264 0.134599 0.132588 0.133420 0.133772 0.132746 0.135748 0.132908 0.133096 0.134896 0.133826 0.135199 0.133913 0.132782 0.133666 0.139457 0.146935 0.148407 0.134169 0.134184 0.133520 0.133762 0.133523 0.136071 0.134346 0.133850 0.133434 0.132933 0.134568 0.133375 0.134066 0.133992 0.139350 0.139556 0.132955 0.132724 0.133453 0.133940 0.136346 0.133684 0.132895 0.133098 0.133180 0.135721 0.133780 0.133411 0.133425 0.133389 0.133201 0.136132 0.133331 0.133091 0.133300 0.139231 0.136844 0.133236 0.133833 0.133001 0.133384 0.133591 0.133133 0.133077 0.133594 0.132975 0.139008 0.134327 0.134222 0.133994 0.133902 0.135229 0.134777 0.133654 0.133720 0.133244 0.132433 0.136317 0.133697 0.133669 0.133093 0.133512 0.140049 0.133673 0.134562 0.133436 0.133159 0.135827 0.133225 0.133798 0.133929 0.133877 0.139693 0.133381 0.134623 0.132852 0.133085 0.139511 0.134200 0.133989 0.132916 0.132969 0.135949 0.136159 0.132951 0.133271 0.134054 0.135020 0.143102 0.144384 0.143705 0.142722 0.142705 0.132573 0.137486 0.134400 0.133344 0.133384 0.132196 0.139162 0.134762 0.135007 0.133878 0.133760 0.133450 0.135740 0.132712 0.133450 0.134170 0.136663 0.135586 0.133005 0.133583 0.134009 0.133411 0.136983 0.133450 0.134740 0.133108 0.133329 0.134905 0.133322 0.132910 0.133344 0.135241 0.135641 0.135002 0.132800 0.133032 0.132988 0.133865 0.135166 0.133133 0.133361 0.143159 0.142181 0.142923 0.142701 0.142530 0.134513 0.133589 0.134145 0.136333 0.133045 0.142673 0.142242 0.143079 0.142510 0.142986 0.136088 0.133904 0.134783 0.132492 0.133722 0.142758 0.143730 0.142043 0.143468 0.142714 0.133618 0.137372 0.133428 0.133263 0.133407 0.142161 0.142429 0.142387 0.142754 0.143169 0.133710 0.133591 0.133639 0.138315 0.133033 0.133759 0.134118 0.133599 0.135438 0.132883 0.132827 0.133248 0.133646 0.138657 0.133997 0.133594 0.133022 0.133701 0.133094 0.133257 0.132502 0.133901 0.132785 0.134171 0.134059 0.133525 0.133244 0.132627 0.134350 0.134715 0.133327 0.133326 0.133031 0.132845 0.134637 0.134702 0.133228 0.133234 0.133220 0.136247 0.136030 0.132895 0.133605 0.133268 0.137770 0.135681 0.136970 0.134514 0.133491 0.136428 0.133966 0.133879 0.132816 0.132623 0.137252 0.133260 0.133144 0.133572 0.133402 0.139298 0.133003 0.133422 0.136366 0.132824 0.134970 0.134389 0.134107 0.134883 0.132771 0.133448 0.133204 0.142231 0.143208 0.142518 0.142455 0.141951 0.136917 0.133306 0.133745 0.132658 0.133262 0.137339 0.133313 0.133614 0.133230 0.134679 0.138644 0.134602 0.143532 0.133155 0.134580 0.136990 0.133142 0.133612 0.133096 0.133049 0.133985 0.134372 0.133348 0.132676 0.133070 0.133457 0.134783 0.133975 0.132953 0.135637 0.137610 0.137316 0.132910 0.133772 0.134674 0.133960 0.135135 0.132674 0.133289 0.133162 0.133966 0.142180 0.142899 0.142314 0.142076 0.142222 0.132965 0.132900 0.136116 0.133657 0.133212 0.142301 0.142001 0.142147 0.143220 0.141746 0.133798 0.133266 0.132484 0.135877 0.137722 0.136816 0.137795 0.138213 0.139003 0.139301 0.134039 0.134541 0.137721 0.136879 0.134498 0.134187 0.134247 0.133958 0.134081 0.134853 0.139831 0.138839 0.140964 0.139140 0.139962 0.137312 0.138838 0.140210 0.137422 0.137554 0.134511 0.137151 0.138920 0.134108 0.135366 0.133732 0.133435 0.135093 0.133605 0.135711 0.133035 0.133716 0.134223 0.135070 0.133340 0.133756 0.133510 0.139875 0.134693 0.132876 0.133103 0.133047 0.140045 0.138404 0.132849 0.133318 0.138723 0.134775 0.139441 0.135209 0.133312 0.137179 0.139201 0.139177 0.139949 0.133401 0.140245 0.137330 0.132970 0.134931 0.133922 0.133515 0.133981 0.133446 0.139571 0.138075 0.132913 0.133483 0.133792 0.133004 0.137815 0.138732 0.133826 0.133347 0.133355 0.138361 0.135100 0.132836 0.133260 0.133020 0.135297 0.133791 0.133289

Statistics: collected samples: 500, arithmetical average: 0.135647

---------------- Registry results:

Unary calls were faster in 100% tests.

---------------- Memory results:

Unary calls were faster in 1% tests.

Testing program was runing 397.380563 seconds.

Press <RETURN> to close this window...
