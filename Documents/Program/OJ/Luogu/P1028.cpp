/***
 * @Author: Zi_Gao
 * @Date: 2022-02-18 21:39:58
 * @LastEditTime: 2022-02-18 22:22:16
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include<cstdio>
int N;
unsigned long long cnt=0;
void dfs(int plus);
int main(){
    // printf("a[1001]={0");
    // for(int i=1;i<=1000;i++){
    //     N=i;
    //     dfs(i);
    //     printf(",%llu",cnt+1);
    //     cnt=0;
    // }
    // printf("}");
    int a[1001]={0,1,2,2,4,4,6,6,10,10,14,14,20,20,26,26,36,36,46,46,60,60,74,74,94,94,114,114,140,140,166,166,202,202,238,238,284,284,330,330,390,390,450,450,524,524,598,598,692,692,786,786,900,900,1014,1014,1154,1154,1294,1294,1460,1460,1626,1626,1828,1828,2030,2030,2268,2268,2506,2506,2790,2790,3074,3074,3404,3404,3734,3734,4124,4124,4514,4514,4964,4964,5414,5414,5938,5938,6462,6462,7060,7060,7658,7658,8350,8350,9042,9042,9828,9828,10614,10614,11514,11514,12414,12414,13428,13428,14442,14442,15596,15596,16750,16750,18044,18044,19338,19338,20798,20798,22258,22258,23884,23884,25510,25510,27338,27338,29166,29166,31196,31196,33226,33226,35494,35494,37762,37762,40268,40268,42774,42774,45564,45564,48354,48354,51428,51428,54502,54502,57906,57906,61310,61310,65044,65044,68778,68778,72902,72902,77026,77026,81540,81540,86054,86054,91018,91018,95982,95982,101396,101396,106810,106810,112748,112748,118686,118686,125148,125148,131610,131610,138670,138670,145730,145730,153388,153388,161046,161046,169396,169396,177746,177746,186788,186788,195830,195830,205658,205658,215486,215486,226100,226100,236714,236714,248228,248228,259742,259742,272156,272156,284570,284570,297998,297998,311426,311426,325868,325868,340310,340310,355906,355906,371502,371502,388252,388252,405002,405002,423046,423046,441090,441090,460428,460428,479766,479766,500564,500564,521362,521362,543620,543620,565878,565878,589762,589762,613646,613646,639156,639156,664666,664666,692004,692004,719342,719342,748508,748508,777674,777674,808870,808870,840066,840066,873292,873292,906518,906518,942012,942012,977506,977506,1015268,1015268,1053030,1053030,1093298,1093298,1133566,1133566,1176340,1176340,1219114,1219114,1264678,1264678,1310242,1310242,1358596,1358596,1406950,1406950,1458378,1458378,1509806,1509806,1564308,1564308,1618810,1618810,1676716,1676716,1734622,1734622,1795932,1795932,1857242,1857242,1922286,1922286,1987330,1987330,2056108,2056108,2124886,2124886,2197788,2197788,2270690,2270690,2347716,2347716,2424742,2424742,2506282,2506282,2587822,2587822,2673876,2673876,2759930,2759930,2850948,2850948,2941966,2941966,3037948,3037948,3133930,3133930,3235326,3235326,3336722,3336722,3443532,3443532,3550342,3550342,3663090,3663090,3775838,3775838,3894524,3894524,4013210,4013210,4138358,4138358,4263506,4263506,4395116,4395116,4526726,4526726,4665396,4665396,4804066,4804066,4949796,4949796,5095526,5095526,5248914,5248914
,5402302,5402302,5563348,5563348,5724394,5724394,5893790,5893790,6063186,6063186,6240932,6240932,6418678,6418678,6605466,6605466,6792254,6792254,6988084,6988084,7183914,7183914,7389572,7389572,7595230,7595230,7810716,7810716,8026202,8026202,8252302,8252302,8478402,8478402,8715116,8715116,8951830,8951830,9200058,9200058,9448286,9448286,9708028,9708028,9967770,9967770,10239926,10239926,10512082,10512082,10796652,10796652,11081222,11081222,11379220,11379220,11677218,11677218,11988644,11988644,12300070,12300070,12625938,12625938,12951806,12951806,13292116,13292116,13632426,13632426,13988332,13988332,14344238,14344238,14715740,14715740,15087242,15087242,15475494
,15475494,15863746,15863746,16268748,16268748,16673750,16673750,17096796,17096796,17519842,17519842,17960932,17960932,18402022,18402022,18862450,18862450,19322878,19322878,19802644,19802644,20282410,20282410,20782974,20782974,21283538,21283538,21804900,21804900,22326262,22326262,22869882,22869882,23413502,23413502,23979380,23979380,24545258,24545258,25135020,25135020,25724782,25724782,26338428,26338428,26952074,26952074,27591230,27591230,28230386,28230386,28895052,28895052,29559718,29559718,30251722,30251722,30943726,30943726,31663068,31663068,32382410,32382410,33130918,33130918,33879426,33879426,34657100,34657100,35434774,35434774,36243644,36243644,37052514,37052514,37892580,37892580,38732646,38732646,39605938,39605938,40479230,40479230,41385748,41385748,42292266,42292266,43234278,43234278,44176290,44176290,45153796,45153796,46131302,46131302,47146570,47146570,48161838,48161838,49214868,49214868,50267898,50267898,51361196,51361196,52454494,52454494,53588060,53588060,54721626,54721626,55897966,55897966,57074306,57074306,58293420,58293420,59512534,59512534,60777212,60777212,62041890,62041890,63352132,63352132,64662374,64662374,66020970,66020970,67379566,67379566,68786516,68786516
,70193466,70193466,71651844,71651844,73110222,73110222,74620028,74620028,76129834,76129834,77694142,77694142,79258450,79258450,80877260,80877260,82496070,82496070,84172786,84172786,85849502,85849502,87584124,87584124,89318746,89318746,91114678,91114678,92910610,92910610,94767852,94767852,96625094,96625094,98547380,98547380,100469666,100469666,102456996,102456996,104444326,104444326,106500434,106500434,108556542,108556542,110681428,110681428,112806314,112806314,115004102,115004102,117201890,117201890,119472580,119472580,121743270,121743270,124090986,124090986,126438702,126438702,128863444,128863444,131288186,131288186,133794468,133794468,136300750,136300750,138888572,138888572,141476394,141476394,144150270,144150270,146824146,146824146,149584076,149584076,152344006,152344006,155194954,155194954,158045902,158045902,160987868,160987868,163929834,163929834,166967782,166967782,170005730,170005730,173139660,173139660,176273590,176273590,179508916,179508916,182744242,182744242,186080964,186080964,189417686,189417686,192861218,192861218,196304750,196304750
,199855092,199855092,203405434,203405434,207068524,207068524,210731614,210731614,214507452,214507452,218283290,218283290,222177814,222177814,226072338,226072338,230085548,230085548,234098758,234098758,238237116,238237116,242375474,242375474,246638980,246638980,250902486,250902486,255297602,255297602,259692718,259692718,264219444,264219444,268746170,268746170,273411566,273411566,278076962,278076962,282881028,282881028,287685094,287685094,292634890,292634890,297584686,297584686,302680212,302680212,307775738,307775738,313024652,313024652,318273566,318273566,323675868,323675868,329078170,329078170,334641518,334641518,340204866,340204866,345929260,345929260,351653654,351653654,357547444,357547444,363441234,363441234,369504420,369504420,375567606,375567606,381808538,381808538,388049470,388049470,394468148,394468148,400886826,400886826,407492292,407492292,414097758,414097758,420890012,420890012,427682266,427682266,434670350,434670350,441658434,441658434,448842348,448842348,456026262,456026262,463415834,463415834,470805406,470805406,478400636,478400636,485995866,485995866,493806582,493806582,501617298,501617298,509643500,509643500,517669702,517669702,525922004,525922004,534174306,534174306,542652708,542652708,551131110,551131110,559846226,559846226,568561342,568561342,577513172,577513172,586465002,586465002,595665060
,595665060,604865118,604865118,614313404,614313404,623761690,623761690,633469718,633469718,643177746,643177746,653145516,653145516,663113286,663113286,673353212,673353212,683593138,683593138,694105220,694105220,704617302,704617302,715413954,715413954,726210606,726210606,737291828,737291828,748373050,748373050,759752270,759752270,771131490,771131490,782808708,782808708,794485926,794485926,806474570,806474570,818463214,818463214,830763284,830763284,843063354,843063354,855689292,855689292,868315230,868315230,881267036,881267036,894218842,894218842,907510958,907510958,920803074,920803074,934435500,934435500,948067926,948067926,962056258,962056258,976044590,976044590,990388828,990388828,1004733066,1004733066,1019448806,1019448806,1034164546,1034164546,1049251788,1049251788,1064339030,1064339030,1079814524,1079814524,1095290018,1095290018,1111153764,1111153764,1127017510,1127017510,1143286258,1143286258,1159555006,1159555006,1176228756,1176228756,1192902506,1192902506,1209999302,1209999302,1227096098,1227096098,1244615940,1244615940,1262135782,1262135782
,1280096714,1280096714,1298057646,1298057646,1316459668,1316459668,1334861690,1334861690,1353724140,1353724140,1372586590,1372586590,1391909468,1391909468,1411232346,1411232346,1431034990,1431034990,1450837634,1450837634,1471120044,1471120044,1491402454,1491402454,1512185428,1512185428,1532968402,1532968402,1554251940,1554251940,1575535478,1575535478,1597340378,1597340378,1619145278,1619145278,1641471540,1641471540,1663797802,1663797802,1686667684,1686667684,1709537566,1709537566,1732951068,1732951068,1756364570,1756364570,1780343950,1780343950,1804323330,1804323330,1828868588,1828868588,1853413846,1853413846,1878548866,1878548866,1903683886,1903683886,1929408668,1929408668,1955133450,1955133450,1981471878};
    int n;
    scanf("%d",&n);
    printf("%d",a[n]);
}
void dfs(int plus){
    if(plus==1){
        return;
    }
    for(int i=1;i<=plus/2&&i<=N;i++){
        cnt++;
        dfs(i);
    }
    return;
}