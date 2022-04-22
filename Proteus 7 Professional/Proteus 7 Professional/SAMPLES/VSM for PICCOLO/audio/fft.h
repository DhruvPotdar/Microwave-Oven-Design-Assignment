/*===================================================================
File name   :   FFT.H                   
                    
Originator  :   Digital Control Systems Group
                Texas Instruments
Description:  
Header file containing  object definitions, proto type declaration and 
default object initializers for FFT modules.
===================================================================
History:
-------------------------------------------------------------------
20-3-2000   Release Rev 1.0                                                  
--------------------------------------------------------------------*/

#ifndef __FFT_H__
#define __FFT_H__ 
  
#define NULL    0         
typedef struct {   
        long *ipcbptr;
        long *tfptr;               
        int size;
        int nrstage;             
        long *magptr;
        long *winptr; 
        long peakmag;
        int peakfrq;
		int ratio;
        void (*init)(void *);
        void (*izero)(void *);
        void (*calc)(void *);
        void (*mag)(void *);
        void (*win)(void *);
        }CFFT32;

typedef struct {
        int acqflag;
        int count;
        long input; 
        long *tempptr;
        long *buffptr;
        int size;
        void (*update)(void *); 
       }CFFT32_ACQ;   
       
typedef struct {   
        long *ipcbptr;
        long *tfptr;               
        int size;
        int nrstage;             
        long *magptr;
        long *winptr; 
        long peakmag;
        int peakfrq;
		int ratio;
        void (*init)(void *);
        void (*calc)(void *);
        void (*split)(void *);
        void (*mag)(void *);
        void (*win)(void *);
        }RFFT32;


typedef struct {
        int acqflag;
        int count;
        long input; 
        long *tempptr;
        long *buffptr;
        int size;
        void (*update)(void *); 
        }RFFT32_ACQ;  

typedef CFFT32  CFFT32_handle;
typedef RFFT32 *RFFT32_handle;
       
#define CFFT32_128P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        128,\
        7,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        8,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_izero,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))CFFT32_mag,\
        (void (*)(void *))CFFT32_win} 
 
 
#define CFFT32_256P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        256,\
        8,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        4,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_izero,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))CFFT32_mag,\
        (void (*)(void *))CFFT32_win} 
        
        
#define CFFT32_512P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        512,\
        9,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        2,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_izero,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))CFFT32_mag,\
        (void (*)(void *))CFFT32_win}  
        
#define CFFT32_1024P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        1024,\
        10,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        1,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_izero,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))CFFT32_mag,\
        (void (*)(void *))CFFT32_win}   
  

#define CFFT32_ACQ_DEFAULTS    { 1,\
        0,\
        0,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        (void (*)(void *))CFFT32_acq}
        

#define RFFT32_128P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        64,\
        6,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        16,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))RFFT32_split,\
        (void (*)(void *))RFFT32_mag,\
        (void (*)(void *))RFFT32_win} 

#define RFFT32_256P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        128,\
        7,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        8,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))RFFT32_split,\
        (void (*)(void *))RFFT32_mag,\
        (void (*)(void *))RFFT32_win} 

#define RFFT32_512P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        256,\
        8,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        4,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))RFFT32_split,\
        (void (*)(void *))RFFT32_mag,\
        (void (*)(void *))RFFT32_win} 

#define RFFT32_1024P_DEFAULTS    { (long *)NULL,\
        (long *)NULL,\
        512,\
        9,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        0,\
        2,\
        (void (*)(void *))CFFT32_init,\
        (void (*)(void *))CFFT32_calc,\
        (void (*)(void *))RFFT32_split,\
        (void (*)(void *))RFFT32_mag,\
        (void (*)(void *))RFFT32_win} 

#define FFTRACQ_DEFAULTS    { 1,\
        0,\
        0,\
        (long *)NULL,\
        (long *)NULL,\
        0,\
        (void (*)(void *))RFFT32_acq}
        
/*-------------------------------------------------------------
 Prototypes for the functions
---------------------------------------------------------------*/
void CFFT32_acq(void *); 
void CFFT32_brev1(long *src, long *dst, int size);
void CFFT32_brev2(long *src, long *dst, int size); 
void CFFT32_izero(void *);
void CFFT32_win(void *); 
void CFFT32_mag(void *);
void CFFT32_calc(void *); 

void CFFT32_init(void *);


void RFFT32_acq(void *); 
void RFFT32_brev(long *src, long *dst, int size);
void RFFT32_win(void *); 
void RFFT32_split(void *); 
void RFFT32_mag(void *); 
                     

#define HAMMING128 {\
        171798692,173007400,176630566,182659324,191078920,201868750,215002410,230447760,248167001,268116772,\
        290248253,314507284,340834499,369165472,399430870,431556631,465464137,501070410,538288317,577026777,\
        617190993,658682676,701400287,745239291,790092406,835849869,882399703,929627993,977419164,1025656263,\
        1074221246,1122995265,1171858963,1220692762,1269377158,1317793011,1365821841,1413346111,1460249523,1506417296,\
        1551736450,1596096081,1639387633,1681505166,1722345610,1761809022,1799798828,1836222061,1870989588,1904016325,\
        1935221452,1964528604,1991866061,2017166925,2040369280,2061416345,2080256615,2096843985,2111137863,2123103269,\
        2132710921,2139937309,2144764748,2147181425}

#define HAMMING256{\
        171798692,172098549,172997940,174496318,176592774,179286034,182574464,186456068,190928488,195989010,\
        201634561,207861715,214666690,222045355,229993231,238505492,247576971,257202161,267375218,278089966,\
        289339901,301118192,313417688,326230924,339550120,353367189,367673745,382461101,397720279,413442017,\
        429616770,446234717,463285771,480759579,498645534,516932776,535610204,554666479,574090031,593869070,\
        613991586,634445364,655217987,676296842,697669134,719321888,741241958,763416036,785830661,808472224,\
        831326981,854381056,877620454,901031065,924598677,948308983,972147587,996100019,1020151735,1044288135,\
        1068494565,1092756330,1117058701,1141386923,1165726227,1190061837,1214378979,1238662889,1262898826,1287072076,\
        1311167962,1335171858,1359069189,1382845449,1406486202,1429977096,1453303871,1476452364,1499408522,1522158409,\
        1544688213,1566984256,1589033004,1610821069,1632335224,1653562409,1674489736,1695104501,1715394188,1735346479,\
        1754949262,1774190636,1793058920,1811542658,1829630629,1847311852,1864575593,1881411371,1897808966,1913758421,\
        1929250055,1944274463,1958822522,1972885402,1986454565,1999521772,2012079091,2024118899,2035633885,2046617060,\
        2057061755,2066961630,2076310674,2085103212,2093333905,2100997757,2108090115,2114606674,2120543477,2125896920,\
        2130663753,2134841081,2138426370,2141417443,2143812482,2145610036,2146809011,2147408681}

 
#define HAMMING512 {\
        171798692,171873366,172097377,172470691,172993252,173664981,174485775,175455512,176574044,177841202,\
        179256795,180820609,182532407,184391930,186398898,188553007,190853931,193301322,195894811,198634005,\
        201518490,204547830,207721567,211039221,214500291,218104253,221850563,225738654,229767938,233937807,\
        238247629,242696753,247284506,252010195,256873106,261872503,267007630,272277711,277681950,283219528,\
        288889610,294691337,300623833,306686200,312877523,319196864,325643270,332215764,338913354,345735026,\
        352679750,359746476,366934134,374241640,381667886,389211752,396872096,404647760,412537569,420540330,\
        428654833,436879851,445214140,453656441,462205478,470859957,479618570,488479993,497442887,506505896,\
        515667650,524926765,534281839,543731459,553274196,562908608,572633237,582446614,592347255,602333663,\
        612404328,622557728,632792328,643106580,653498924,663967791,674511597,685128747,695817638,706576652,\
        717404163,728298535,739258120,750281260,761366291,772511535,783715308,794975915,806291655,817660817,\
        829081681,840552522,852071604,863637187,875247521,886900852,898595417,910329449,922101174,933908811,\
        945750576,957624678,969529322,981462709,993423034,1005408488,1017417261,1029447536,1041497494,1053565314,\
        1065649172,1077747239,1089857688,1101978687,1114108404,1126245005,1138386655,1150531518,1162677759,1174823540,\
        1186967026,1199106381,1211239769,1223365356,1235481309,1247585796,1259676987,1271753054,1283812171,1295852516,\
        1307872266,1319869607,1331842723,1343789804,1355709045,1367598643,1379456801,1391281725,1403071629,1414824729,\
        1426539249,1438213418,1449845470,1461433648,1472976198,1484471377,1495917446,1507312674,1518655339,1529943727,\
        1541176129,1552350849,1563466196,1574520491,1585512061,1596439246,1607300392,1618093859,1628818014,1639471236,\
        1650051914,1660558449,1670989252,1681342746,1691617365,1701811558,1711923782,1721952508,1731896220,1741753415,\
        1751522603,1761202306,1770791062,1780287420,1789689945,1798997215,1808207823,1817320377,1826333499,1835245826,\
        1844056011,1852762722,1861364642,1869860471,1878248925,1886528735,1894698650,1902757434,1910703869,1918536754,\
        1926254904,1933857152,1941342350,1948709365,1955957084,1963084411,1970090268,1976973596,1983733355,1990368523,\
        1996878095,2003261090,2009516540,2015643501,2021641046,2027508268,2033244281,2038848217,2044319228,2049656489,\
        2054859192,2059926549,2064857796,2069652187,2074308996,2078827520,2083207076,2087447001,2091546655,2095505418,\
        2099322690,2102997896,2106530478,2109919905,2113165662,2116267259,2119224227,2122036120,2124702512,2127222999,\
        2129597202,2131824760,2133905338,2135838620,2137624314,2139262151,2140751883,2142093284,2143286151,2144330305,\
        2145225588,2145971864,2146569020,2147016966,2147315634,2147464979}
        
#define HAMMING1024 {\
		171798692,171817324,171873220,171966378,172096793,172264462,172469378,172711533,172990918,173307523,\
		173661335,174052341,174480527,174945876,175448371,175987992,176564720,177178533,177829407,178517318,\
		179242240,180004146,180803006,181638792,182511470,183421009,184367375,185350530,186370439,187427062,\
		188520360,189650292,190816815,192019885,193259457,194535484,195847917,197196708,198581805,200003156,\
		201460707,202954404,204484191,206050008,207651799,209289501,210963053,212672392,214417454,216198173,\
		218014481,219866310,221753591,223676251,225634219,227627421,229655781,231719223,233817669,235951040,\
		238119255,240322233,242559890,244832143,247138905,249480090,251855608,254265371,256709288,259187265,\
		261699211,264245030,266824626,269437902,272084759,274765097,277478816,280225813,283005983,285819223,\
		288665427,291544486,294456293,297400737,300377707,303387091,306428776,309502647,312608588,315746481,\
		318916209,322117651,325350687,328615195,331911052,335238134,338596315,341985468,345405465,348856178,\
		352337477,355849229,359391303,362963564,366565879,370198111,373860123,377551777,381272935,385023454,\
		388803195,392612014,396449767,400316311,404211498,408135183,412087217,416067451,420075735,424111917,\
		428175846,432267368,436386329,440532573,444705944,448906285,453133437,457387240,461667535,465974159,\
		470306951,474665746,479050381,483460690,487896506,492357663,496843992,501355323,505891487,510452313,\
		515037628,519647259,524281033,528938774,533620308,538325457,543054044,547805890,552580817,557378644,\
		562199190,567042274,571907712,576795321,581704917,586636315,591589328,596563770,601559453,606576188,\
		611613787,616672058,621750813,626849858,631969002,637108051,642266812,647445090,652642689,657859414,\
		663095067,668349452,673622370,678913622,684223009,689550330,694895384,700257969,705637884,711034926,\
		716448890,721879573,727326770,732790274,738269881,743765384,749276574,754803245,760345187,765902192,\
		771474050,777060551,782661484,788276638,793905801,799548761,805205304,810875218,816558288,822254301,\
		827963041,833684292,839417840,845163467,850920958,856690095,862470659,868262434,874065201,879878740,\
		885702833,891537260,897381801,903236234,909100340,914973897,920856684,926748479,932649059,938558202,\
		944475684,950401284,956334776,962275938,968224545,974180373,980143198,986112793,992088934,998071396,\
		1004059953,1010054379,1016054448,1022059933,1028070608,1034086247,1040106622,1046131506,1052160672,1058193892,\
		1064230939,1070271586,1076315604,1082362765,1088412841,1094465605,1100520826,1106578278,1112637732,1118698959,\
		1124761731,1130825818,1136890992,1142957024,1149023686,1155090748,1161157982,1167225159,1173292049,1179358425,\
		1185424057,1191488716,1197552174,1203614201,1209674570,1215733052,1221789417,1227843439,1233894887,1239943534,\
		1245989152,1252031513,1258070388,1264105551,1270136772,1276163826,1282186484,1288204519,1294217704,1300225812,\
		1306228618,1312225893,1318217413,1324202951,1330182280,1336155177,1342121415,1348080769,1354033015,1359977927,\
		1365915283,1371844856,1377766425,1383679766,1389584655,1395480870,1401368189,1407246389,1413115248,1418974545,\
		1424824060,1430663571,1436492858,1442311702,1448119883,1453917181,1459703378,1465478256,1471241596,1476993183,\
		1482732797,1488460224,1494175247,1499877650,1505567218,1511243737,1516906992,1522556770,1528192858,1533815043,\
		1539423113,1545016856,1550596062,1556160520,1561710020,1567244352,1572763309,1578266681,1583754262,1589225844,\
		1594681220,1600120185,1605542534,1610948063,1616336566,1621707842,1627061687,1632397900,1637716279,1643016623,\
		1648298733,1653562409,1658807453,1664033667,1669240854,1674428816,1679597360,1684746289,1689875410,1694984529,\
		1700073453,1705141990,1710189949,1715217139,1720223372,1725208458,1730172209,1735114437,1740034957,1744933583,\
		1749810130,1754664414,1759496251,1764305461,1769091860,1773855269,1778595508,1783312398,1788005762,1792675421,\
		1797321201,1801942925,1806540420,1811113512,1815662028,1820185797,1824684648,1829158412,1833606920,1838030003,\
		1842427496,1846799231,1851145045,1855464774,1859758254,1864025323,1868265820,1872479587,1876666462,1880826290,\
		1884958912,1889064172,1893141917,1897191992,1901214244,1905208522,1909174674,1913112552,1917022007,1920902890,\
		1924755057,1928578362,1932372659,1936137807,1939873663,1943580086,1947256937,1950904076,1954521366,1958108672,\
		1961665856,1965192786,1968689327,1972155349,1975590721,1978995312,1982368995,1985711642,1989023127,1992303325,\
		1995552113,1998769367,2001954967,2005108792,2008230724,2011320644,2014378436,2017403985,2020397177,2023357898,\
		2026286037,2029181484,2032044128,2034873863,2037670582,2040434179,2043164549,2045861590,2048525201,2051155280,\
		2053751728,2056314447,2058843342,2061338315,2063799274,2066226125,2068618777,2070977140,2073301124,2075590642,\
		2077845608,2080065936,2082251543,2084402346,2086518265,2088599218,2090645129,2092655919,2094631513,2096571837,\
		2098476816,2100346380,2102180457,2103978979,2105741878,2107469087,2109160540,2110816175,2112435929,2114019741,\
		2115567550,2117079299,2118554930,2119994388,2121397619,2122764569,2124095187,2125389423,2126647228,2127868555,\
		2129053357,2130201590,2131313210,2132388176,2133426447,2134427984,2135392749,2136320705,2137211818,2138066055,\
		2138883381,2139663768,2140407186,2141113606,2141783001,2142415348,2143010621,2143568798,2144089859,2144573783,\
		2145020552,2145430150,2145802561,2146137771,2146435767,2146696538,2146920075,2147106368,2147255411,2147367198,\
		2147441726,2147478990}

 
#define HANNING128 {\
        1273398,5090574,11442471,20314026,31684195,45526009,61806638,80487465,101524182,124866892,\
        150460228,178243486,208150767,240111135,274048782,309883213,347529432,386898147,427895979,470425686,\
        514386393,559673828,606180576,653796328,702408144,751900723,802156673,853056793,904480353,956305383,\
        1008408960,1060667498,1112957048,1165153583,1217133300,1268772908,1319949923,1370542961,1420432019,1469498766,\
        1517626821,1564702030,1610612736,1655250043,1698508077,1740284235,1780479427,1818998316,1855749539,1890645926,\
        1923604707,1954547707,1983401533,2010097746,2034573027,2056769322,2076633984,2094119897,2109185586,2121795317,\
        2131919181,2139533165,2144619209,2147165251} 
 
 
#define HANNING256 {\
        320879,1283326,2886763,5130234,8012398,11531531,15685531,20471914,25887820,31930012,\
        38594879,45878437,53776332,62283845,71395891,81107023,91411437,102302975,113775126,125821035,\
        138433501,151604986,165327617,179593194,194393189,209718757,225560739,241909664,258755763,276088966,\
        293898914,312174961,330906186,350081391,369689117,389717644,410155002,430988975,452207111,473796729,\
        495744925,518038580,540664371,563608773,586858074,610398378,634215615,658295550,682623790,707185796,\
        731966886,756952250,782126955,807475952,832984093,858636131,884416734,910310494,936301934,962375520,\
        988515667,1014706753,1040933124,1067179103,1093429005,1119667141,1145877827,1172045399,1198154216,1224188675,\
        1250133213,1275972325,1301690567,1327272567,1352703037,1377966775,1403048683,1427933770,1452607161,1477054111,\
        1501260007,1525210382,1548890922,1572287472,1595386050,1618172849,1640634250,1662756828,1684527362,1705932838,\
        1726960464,1747597671,1767832125,1787651733,1807044647,1825999278,1844504297,1862548642,1880121531,1897212459,\
        1913811211,1929907867,1945492806,1960556713,1975090585,1989085735,2002533798,2015426737,2027756845,2039516754,\
        2050699434,2061298202,2071306722,2080719014,2089529452,2097732769,2105324063,2112298796,2118652800,2124382278,\
        2129483804,2133954329,2137791182,2140992070,2143555078,2145478677,2146761714,2147403425}

#define HANNING512 {\
        80536,322131,724751,1288333,2012793,2898024,3943891,5150239,6516886,8043627,\
        9730233,11576451,13582005,15746592,18069890,20551549,23191196,25988436,28942850,32053993,\
        35321400,38744581,42323021,46056183,49943509,53984415,58178294,62524517,67022433,71671367,\
        76470621,81419476,86517188,91762994,97156107,102695717,108380993,114211083,120185112,126302183,\
        132561380,138961763,145502373,152182227,159000324,165955641,173047136,180273743,187634379,195127940,\
        202753302,210509320,218394832,226408654,234549584,242816402,251207866,259722719,268359682,277117461,\
        285994741,294990191,304102461,313330184,322671977,332126438,341692148,351367673,361151561,371042344,\
        381038540,391138647,401341152,411644523,422047216,432547669,443144307,453835541,464619767,475495368,\
        486460711,497514152,508654033,519878683,531186417,542575541,554044344,565591107,577214098,588911572,\
        600681776,612522944,624433299,636411054,648454414,660561570,672730708,684960001,697247616,709591708,\
        721990427,734441911,746944294,759495700,772094245,784738041,797425190,810153789,822921929,835727695,\
        848569165,861444413,874351508,887288513,900253488,913244488,926259564,939296764,952354132,965429710,\
        978521535,991627644,1004746071,1017874849,1031012006,1044155574,1057303580,1070454052,1083605017,1096754502,\
        1109900536,1123041145,1136174359,1149298207,1162410721,1175509934,1188593881,1201660598,1214708127,1227734509,\
        1240737791,1253716022,1266667255,1279589548,1292480961,1305339561,1318163419,1330950612,1343699220,1356407333,\
        1369073043,1381694450,1394269662,1406796791,1419273958,1431699293,1444070930,1456387014,1468645698,1480845143,\
        1492983517,1505059002,1517069785,1529014064,1540890048,1552695955,1564430014,1576090465,1587675559,1599183558,\
        1610612736,1621961378,1633227781,1644410256,1655507125,1666516724,1677437401,1688267517,1699005449,1709649584,\
        1720198328,1730650097,1741003323,1751256453,1761407949,1771456289,1781399965,1791237485,1800967374,1810588172,\
        1820098436,1829496739,1838781671,1847951840,1857005869,1865942402,1874760097,1883457631,1892033699,1900487016,\
        1908816314,1917020341,1925097869,1933047685,1940868597,1948559431,1956119034,1963546272,1970840031,1977999216,\
        1985022753,1991909589,1998658692,2005269048,2011739665,2018069574,2024257824,2030303488,2036205658,2041963449,\
        2047575997,2053042461,2058362020,2063533876,2068557254,2073431399,2078155582,2082729093,2087151245,2091421377,\
        2095538846,2099503036,2103313352,2106969222,2110470098,2113815454,2117004789,2120037624,2122913505,2125632000,\
        2128192701,2130595224,2132839209,2134924319,2136850241,2138616686,2140223390,2141670111,2142956632,2144082761,\
        2145048328,2145853189,2146497222,2146980332,2147302445,2147463514}



#define HANNING1024 {\
		20173,80693,181557,322760,504299,726165,988351,1290847,1633641,2016721,\
		2440072,2903679,3407523,3951586,4535847,5160285,5824876,6529595,7274415,8059309,\
		8884248,9749199,10654131,11599010,12583799,13608463,14672962,15777257,16921306,18105066,\
		19328493,20591540,21894160,23236305,24617924,26038964,27499373,28999096,30538075,32116255,\
		33733574,35389973,37085388,38819758,40593015,42405094,44255927,46145443,48073573,50040243,\
		52045380,54088908,56170750,58290829,60449064,62645375,64879679,67151891,69461928,71809701,\
		74195123,76618104,79078553,81576377,84111483,86683775,89293157,91939530,94622796,97342853,\
		100099600,102892931,105722744,108588931,111491384,114429995,117404653,120415247,123461662,126543786,\
		129661501,132814691,136003237,139227020,142485918,145779809,149108569,152472074,155870195,159302807,\
		162769780,166270983,169806286,173375555,176978656,180615453,184285811,187989591,191726655,195496860,\
		199300067,203136132,207004910,210906257,214840026,218806070,222804238,226834381,230896347,234989985,\
		239115139,243271655,247459377,251678147,255927807,260208197,264519157,268860524,273232135,277633827,\
		282065432,286526786,291017720,295538066,300087654,304666312,309273870,313910153,318574987,323268197,\
		327989608,332739040,337516317,342321258,347153683,352013410,356900257,361814040,366754574,371721675,\
		376715154,381734824,386780498,391851985,396949094,402071635,407219414,412392239,417589914,422812245,\
		428059036,433330088,438625205,443944187,449286834,454652946,460042320,465454755,470890047,476347992,\
		481828384,487331018,492855687,498402184,503970299,509559824,515170549,520802263,526454754,532127810,\
		537821218,543534763,549268231,555021407,560794075,566586017,572397016,578226853,584075310,589942167,\
		595827202,601730196,607650927,613589171,619544706,625517307,631506752,637512813,643535267,649573886,\
		655628443,661698711,667784463,673885468,680001499,686132325,692277715,698437440,704611267,710798964,\
		717000300,723215040,729442952,735683801,741937353,748203373,754481625,760771874,767073883,773387415,\
		779712233,786048100,792394778,798752027,805119609,811497285,817884815,824281959,830688477,837104128,\
		843528670,849961864,856403465,862853234,869310927,875776302,882249115,888729124,895216085,901709755,\
		908209888,914716242,921228571,927746631,934270177,940798964,947332746,953871278,960414314,966961609,\
		973512916,980067990,986626583,993188450,999753343,1006321017,1012891224,1019463718,1026038251,1032614577,\
		1039192448,1045771617,1052351838,1058932862,1065514442,1072096332,1078678284,1085260050,1091841383,1098422036,\
		1105001762,1111580313,1118157443,1124732903,1131306447,1137877829,1144446800,1151013114,1157576525,1164136786,\
		1170693650,1177246871,1183796203,1190341399,1196882214,1203418402,1209949717,1216475914,1222996748,1229511973,\
		1236021345,1242524619,1249021551,1255511897,1261995412,1268471854,1274940979,1281402543,1287856304,1294302019,\
		1300739447,1307168345,1313588472,1319999587,1326401448,1332793815,1339176448,1345549107,1351911552,1358263545,\
		1364604847,1370935220,1377254425,1383562225,1389858383,1396142664,1402414829,1408674644,1414921874,1421156284,\
		1427377639,1433585706,1439780252,1445961043,1452127848,1458280434,1464418571,1470542028,1476650575,1482743982,\
		1488822020,1494884462,1500931078,1506961643,1512975929,1518973710,1524954761,1530918857,1536865775,1542795290,\
		1548707180,1554601222,1560477196,1566334880,1572174055,1577994500,1583795998,1589578330,1595341279,1601084628,\
		1606808162,1612511665,1618194923,1623857723,1629499852,1635121098,1640721249,1646300096,1651857428,1657393037,\
		1662906714,1668398253,1673867447,1679314091,1684737980,1690138910,1695516679,1700871083,1706201923,1711508997,\
		1716792106,1722051052,1727285638,1732495666,1737680940,1742841266,1747976450,1753086299,1758170621,1763229225,\
		1768261921,1773268520,1778248833,1783202673,1788129855,1793030193,1797903503,1802749602,1807568307,1812359439,\
		1817122816,1821858259,1826565592,1831244636,1835895217,1840517159,1845110288,1849674433,1854209421,1858715082,\
		1863191247,1867637747,1872054417,1876441089,1880797598,1885123782,1889419477,1893684522,1897918757,1902122023,\
		1906294162,1910435016,1914544431,1918622252,1922668326,1926682501,1930664625,1934614550,1938532126,1942417207,\
		1946269647,1950089301,1953876025,1957629677,1961350116,1965037202,1968690797,1972310764,1975896965,1979449268,\
		1982967537,1986451642,1989901450,1993316833,1996697662,2000043810,2003355151,2006631561,2009872916,2013079096,\
		2016249979,2019385446,2022485380,2025549664,2028578183,2031570823,2034527471,2037448017,2040332351,2043180364,\
		2045991949,2048767001,2051505416,2054207090,2056871922,2059499812,2062090662,2064644373,2067160849,2069639998,\
		2072081724,2074485937,2076852545,2079181461,2081472596,2083725865,2085941183,2088118466,2090257633,2092358604,\
		2094421298,2096445640,2098431553,2100378962,2102287794,2104157977,2105989442,2107782119,2109535940,2111250841,\
		2112926756,2114563623,2116161379,2117719966,2119239324,2120719397,2122160129,2123561465,2124923353,2126245741,\
		2127528581,2128771824,2129975423,2131139333,2132263510,2133347912,2134392499,2135397230,2136362069,2137286978,\
		2138171924,2139016873,2139821793,2140586654,2141311427,2141996085,2142640603,2143244955,2143809120,2144333076,\
		2144816803,2145260284,2145663501,2146026440,2146349087,2146631429,2146873457,2147075160,2147236532,2147357566,\
		2147438258,2147478605}

        
        
#define BLACKMAN128{\
        0,473487,1898954,4291345,7675325,12084923,17563032,24160782,31936780,40956239,\
        51289992,63013410,76205232,90946324,107318373,125402533,145278045,167020830,190702088,216386905,\
        244132891,273988862,305993574,340174541,376546925,415112538,455858948,498758704,543768701,590829678,\
        639865867,690784787,743477211,797817274,853662754,910855514,969222092,1028574459,1088710919,1149417155,\
        1210467412,1271625800,1332647724,1393281404,1453269502,1512350807,1570262006,1626739476,1681521135,1734348285,\
        1784967470,1833132309,1878605298,1921159561,1960580537,1996667585,2029235493,2058115879,2083158474,2104232265,\
        2121226499,2134051531,2142639517,2146944934}
 
#define BLACKMAN256 {\
        0,117367,469778,1058155,1884038,2949569,4257492,5811141,7614426,9671820,\
        11988344,14569547,17421488,20550711,23964223,27669465,31674290,35986929,40615961,45570283,\
        50859071,56491753,62477963,68827510,75550340,82656491,90156056,98059143,106375831,115116129,\
        124289933,133906983,143976819,154508741,165511761,176994566,188965470,201432376,214402729,227883484,\
        241881055,256401285,271449402,287029982,303146917,319803375,337001771,354743733,373030070,391860748,\
        411234860,431150600,451605242,472595119,494115603,516161088,538724977,561799666,585376538,609445954,\
        633997243,659018706,684497611,710420195,736771670,763536228,790697051,818236321,846135237,874374029,\
        902931978,931787438,960917856,990299802,1019908997,1049720339,1079707940,1109845162,1140104645,1170458357,\
        1200877625,1231333185,1261795218,1292233403,1322616960,1352914698,1383095070,1413126216,1442976023,1472612174,\
        1502002202,1531113547,1559913610,1588369809,1616449636,1644120714,1671350853,1698108106,1724360829,1750077736,\
        1775227953,1799781077,1823707231,1846977114,1869562063,1891434097,1912565973,1932931238,1952504275,1971260350,\
        1989175663,2006227387,2022393715,2037653900,2051988291,2065378376,2077806811,2089257459,2099715414,2109167036,\
        2117599970,2125003178,2131366951,2136682935,2140944142,2144144966,2146281194,2147350013}
        
#define BLACKMAN512 {\
        0,29222,116908,263115,467939,731513,1054010,1435638,1876645,2377317,\
        2937974,3558975,4240717,4983630,5788181,6654875,7584249,8576874,9633357,10754339,\
        11940490,13192517,14511155,15897171,17351362,18874557,20467609,22131403,23866850,25674885,\
        27556472,29512597,31544270,33652525,35838416,38103019,40447429,42872760,45380142,47970724,\
        50645670,53406156,56253373,59188525,62212825,65327497,68533771,71832887,75226090,78714631,\
        82299761,85982737,89764815,93647252,97631301,101718216,105909243,110205624,114608594,119119380,\
        123739200,128469260,133310755,138264864,143332755,148515577,153814463,159230525,164764856,170418530,\
        176192594,182088074,188105968,194247250,200512864,206903725,213420718,220064697,226836481,233736856,\
        240766572,247926343,255216844,262638713,270192545,277878895,285698278,293651161,301737969,309959082,\
        318314832,326805504,335431334,344192508,353089163,362121382,371289200,380592594,390031489,399605757,\
        409315213,419159614,429138663,439252003,449499221,459879843,470393337,481039109,491816508,502724819,\
        513763265,524931010,536227154,547650734,559200726,570876040,582675525,594597966,606642083,618806534,\
        631089911,643490744,656007496,668638571,681382303,694236967,707200772,720271865,733448327,746728179,\
        760109377,773589816,787167329,800839686,814604597,828459711,842402616,856430841,870541857,884733076,\
        899001850,913345477,927761197,942246196,956797602,971412494,986087893,1000820771,1015608049,1030446596,\
        1045333232,1060264732,1075237819,1090249175,1105295434,1120373187,1135478983,1150609330,1165760696,1180929511,\
        1196112166,1211305017,1226504385,1241706560,1256907796,1272104321,1287292331,1302467996,1317627460,1332766843,\
        1347882240,1362969728,1378025362,1393045180,1408025202,1422961436,1437849874,1452686499,1467467281,1482188185,\
        1496845168,1511434183,1525951179,1540392104,1554752908,1569029540,1583217956,1597314117,1611313990,1625213552,\
        1639008792,1652695711,1666270324,1679728662,1693066776,1706280734,1719366629,1732320573,1745138706,1757817195,\
        1770352233,1782740045,1794976888,1807059052,1818982862,1830744681,1842340909,1853767988,1865022401,1876100674,\
        1886999379,1897715135,1908244608,1918584514,1928731621,1938682750,1948434775,1957984627,1967329294,1976465820,\
        1985391313,1994102940,2002597931,2010873579,2018927244,2026756351,2034358394,2041730933,2048871602,2055778102,\
        2062448210,2068879772,2075070712,2081019027,2086722792,2092180156,2097389350,2102348679,2107056533,2111511377,\
        2115711761,2119656315,2123343752,2126772867,2129942541,2132851736,2135499501,2137884968,2140007358,2141865973,\
        2143460206,2144789533,2145853518,2146651813,2147184154,2147450369}        


#define BLACKMAN1024 {\
		0,7291,29165,65626,116680,182334,262601,357492,467024,591214,\
		730082,883651,1051946,1234994,1432825,1645471,1872966,2115346,2372651,2644922,\
		2932202,3234537,3551975,3884568,4232366,4595425,4973803,5367558,5776753,6201450,\
		6641716,7097618,7569228,8056616,8559859,9079031,9614213,10165484,10732927,11316627,\
		11916672,12533148,13166148,13815764,14482091,15165224,15865263,16582307,17316459,18067823,\
		18836504,19622609,20426249,21247533,22086574,22943487,23818388,24711393,25622623,26552197,\
		27500237,28466869,29452215,30456404,31479563,32521822,33583311,34664162,35764508,36884485,\
		38024228,39183874,40363561,41563428,42783617,44024267,45285523,46567527,47870424,49194359,\
		50539478,51905929,53293860,54703419,56134756,57588021,59063365,60560940,62080897,63623389,\
		65188571,66776594,68387614,70021785,71679262,73360201,75064757,76793085,78545343,80321686,\
		82122271,83947254,85796791,87671041,89570158,91494300,93443624,95418285,97418439,99444243,\
		101495852,103573422,105677107,107807063,109963443,112146402,114356092,116592666,118856276,121147075,\
		123465212,125810837,128184101,130585152,133014137,135471203,137956497,140470162,143012344,145583185,\
		148182827,150811410,153469075,156155959,158872199,161617932,164393292,167198411,170033423,172898455,\
		175793639,178719100,181674964,184661355,187678396,190726207,193804907,196914613,200055441,203227503,\
		206430912,209665777,212932206,216230304,219560175,222921920,226315639,229741428,233199383,236689597,\
		240212160,243767160,247354683,250974813,254627629,258313212,262031636,265782976,269567302,273384683,\
		277235184,281118868,285035796,288986026,292969611,296986604,301037055,305121010,309238511,313389600,\
		317574313,321792687,326044751,330330535,334650063,339003359,343390441,347811325,352266024,356754548,\
		361276902,365833090,370423112,375046963,379704637,384396124,389121409,393880476,398673304,403499868,\
		408360142,413254093,418181688,423142887,428137650,433165931,438227680,443322845,448451370,453613195,\
		458808255,464036483,469297808,474592156,479919447,485279598,490672525,496098135,501556337,507047031,\
		512570116,518125487,523713034,529332644,534984200,540667581,546382662,552129315,557907405,563716797,\
		569557349,575428918,581331354,587264506,593228216,599222323,605246665,611301071,617385370,623499385,\
		629642936,635815838,642017903,648248939,654508749,660797133,667113886,673458801,679831665,686232262,\
		692660371,699115768,705598226,712107512,718643390,725205620,731793959,738408158,745047966,751713128,\
		758403383,765118468,771858117,778622057,785410015,792221711,799056862,805915183,812796384,819700169,\
		826626242,833574301,840544042,847535154,854547326,861580242,868633581,875707021,882800233,889912888,\
		897044652,904195186,911364150,918551198,925755983,932978153,940217352,947473223,954745403,962033528,\
		969337229,976656135,983989869,991338055,998700310,1006076251,1013465489,1020867634,1028282292,1035709066,\
		1043147557,1050597360,1058058071,1065529281,1073010578,1080501547,1088001773,1095510834,1103028308,1110553769,\
		1118086790,1125626940,1133173786,1140726892,1148285819,1155850127,1163419373,1170993112,1178570895,1186152272,\
		1193736791,1201323998,1208913435,1216504644,1224097164,1231690532,1239284282,1246877949,1254471062,1262063151,\
		1269653745,1277242367,1284828543,1292411795,1299991643,1307567607,1315139204,1322705950,1330267360,1337822947,\
		1345372223,1352914698,1360449883,1367977284,1375496410,1383006767,1390507858,1397999188,1405480261,1412950577,\
		1420409639,1427856947,1435292001,1442714299,1450123340,1457518623,1464899643,1472265899,1479616886,1486952101,\
		1494271040,1501573197,1508858068,1516125149,1523373934,1530603919,1537814598,1545005466,1552176019,1559325752,\
		1566454161,1573560741,1580644988,1587706400,1594744473,1601758704,1608748592,1615713636,1622653335,1629567189,\
		1636454698,1643315365,1650148692,1656954182,1663731340,1670479671,1677198683,1683887883,1690546779,1697174882,\
		1703771704,1710336758,1716869558,1723369619,1729836460,1736269599,1742668557,1749032856,1755362020,1761655576,\
		1767913050,1774133973,1780317876,1786464293,1792572759,1798642812,1804673993,1810665844,1816617909,1822529734,\
		1828400870,1834230867,1840019281,1845765667,1851469585,1857130597,1862748267,1868322163,1873851855,1879336916,\
		1884776921,1890171450,1895520084,1900822409,1906078011,1911286482,1916447416,1921560411,1926625067,1931640988,\
		1936607781,1941525058,1946392432,1951209521,1955975946,1960691333,1965355309,1969967507,1974527562,1979035114,\
		1983489807,1987891288,1992239207,1996533220,2000772986,2004958167,2009088431,2013163449,2017182896,2021146452,\
		2025053799,2028904626,2032698625,2036435492,2040114929,2043736639,2047300332,2050805723,2054252530,2057640476,\
		2060969288,2064238698,2067448443,2070598264,2073687908,2076717124,2079685669,2082593301,2085439787,2088224897,\
		2090948403,2093610087,2096209732,2098747127,2101222067,2103634352,2105983784,2108270174,2110493335,2112653086,\
		2114749253,2116781665,2118750155,2120654565,2122494738,2124270525,2125981781,2127628366,2129210146,2130726993,\
		2132178781,2133565394,2134886717,2136142643,2137333068,2138457897,2139517036,2140510399,2141437905,2142299478,\
		2143095048,2143824550,2144487923,2145085114,2145616073,2146080758,2146479130,2146811156,2147076810,2147276069,\
		2147408917,2147475344}      

#endif

