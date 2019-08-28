{"filter":false,"title":"crypt0.c","tooltip":"~/workspace/pset2/crypt0.c","undoManager":{"mark":34,"position":34,"stack":[[{"start":{"row":0,"column":0},"end":{"row":16,"column":1},"action":"insert","lines":["#include <stdio.h>","#include <time.h>","#include <unistd.h>","     ","int main(void)","{","\tchar salt[] = \"$1$abcdefgh\"; /* This should be random */","\tchar *password;","","\t/* Read in the user's password and encrypt it. */","\tpassword = crypt(getpass(\"Password:\"), salt);","","\t/* Print the results. */","\tputs(password);","","\treturn 0;","}"],"id":1}],[{"start":{"row":3,"column":0},"end":{"row":3,"column":5},"action":"remove","lines":["     "],"id":2}],[{"start":{"row":0,"column":18},"end":{"row":1,"column":0},"action":"insert","lines":["",""],"id":3},{"start":{"row":1,"column":0},"end":{"row":1,"column":1},"action":"insert","lines":["#"]},{"start":{"row":1,"column":1},"end":{"row":1,"column":2},"action":"insert","lines":["i"]},{"start":{"row":1,"column":2},"end":{"row":1,"column":3},"action":"insert","lines":["n"]}],[{"start":{"row":1,"column":3},"end":{"row":1,"column":4},"action":"insert","lines":["c"],"id":4},{"start":{"row":1,"column":4},"end":{"row":1,"column":5},"action":"insert","lines":["l"]},{"start":{"row":1,"column":5},"end":{"row":1,"column":6},"action":"insert","lines":["u"]},{"start":{"row":1,"column":6},"end":{"row":1,"column":7},"action":"insert","lines":["d"]},{"start":{"row":1,"column":7},"end":{"row":1,"column":8},"action":"insert","lines":["e"]}],[{"start":{"row":1,"column":8},"end":{"row":1,"column":9},"action":"insert","lines":[" "],"id":5},{"start":{"row":1,"column":9},"end":{"row":1,"column":10},"action":"insert","lines":["<"]},{"start":{"row":1,"column":10},"end":{"row":1,"column":11},"action":"insert","lines":["c"]},{"start":{"row":1,"column":11},"end":{"row":1,"column":12},"action":"insert","lines":["r"]}],[{"start":{"row":1,"column":12},"end":{"row":1,"column":13},"action":"insert","lines":["y"],"id":6},{"start":{"row":1,"column":13},"end":{"row":1,"column":14},"action":"insert","lines":["p"]},{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"insert","lines":["t"]},{"start":{"row":1,"column":15},"end":{"row":1,"column":16},"action":"insert","lines":["."]},{"start":{"row":1,"column":16},"end":{"row":1,"column":17},"action":"insert","lines":["h"]},{"start":{"row":1,"column":17},"end":{"row":1,"column":18},"action":"insert","lines":[">"]}],[{"start":{"row":0,"column":18},"end":{"row":1,"column":0},"action":"insert","lines":["",""],"id":7},{"start":{"row":1,"column":0},"end":{"row":1,"column":1},"action":"insert","lines":["#"]},{"start":{"row":1,"column":1},"end":{"row":1,"column":2},"action":"insert","lines":["i"]},{"start":{"row":1,"column":2},"end":{"row":1,"column":3},"action":"insert","lines":["n"]},{"start":{"row":1,"column":3},"end":{"row":1,"column":4},"action":"insert","lines":["c"]},{"start":{"row":1,"column":4},"end":{"row":1,"column":5},"action":"insert","lines":["l"]},{"start":{"row":1,"column":5},"end":{"row":1,"column":6},"action":"insert","lines":["u"]},{"start":{"row":1,"column":6},"end":{"row":1,"column":7},"action":"insert","lines":["d"]},{"start":{"row":1,"column":7},"end":{"row":1,"column":8},"action":"insert","lines":["e"]}],[{"start":{"row":1,"column":8},"end":{"row":1,"column":9},"action":"insert","lines":[" "],"id":8},{"start":{"row":1,"column":9},"end":{"row":1,"column":10},"action":"insert","lines":["<"]},{"start":{"row":1,"column":10},"end":{"row":1,"column":11},"action":"insert","lines":["c"]},{"start":{"row":1,"column":11},"end":{"row":1,"column":12},"action":"insert","lines":["s"]},{"start":{"row":1,"column":12},"end":{"row":1,"column":13},"action":"insert","lines":["5"]},{"start":{"row":1,"column":13},"end":{"row":1,"column":14},"action":"insert","lines":["0"]}],[{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"insert","lines":[">"],"id":9}],[{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"remove","lines":[">"],"id":10}],[{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"insert","lines":["h"],"id":11},{"start":{"row":1,"column":15},"end":{"row":1,"column":16},"action":"insert","lines":["."]}],[{"start":{"row":1,"column":15},"end":{"row":1,"column":16},"action":"remove","lines":["."],"id":12},{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"remove","lines":["h"]}],[{"start":{"row":1,"column":14},"end":{"row":1,"column":15},"action":"insert","lines":["."],"id":13},{"start":{"row":1,"column":15},"end":{"row":1,"column":16},"action":"insert","lines":["h"]},{"start":{"row":1,"column":16},"end":{"row":1,"column":17},"action":"insert","lines":["."]}],[{"start":{"row":1,"column":16},"end":{"row":1,"column":17},"action":"remove","lines":["."],"id":14}],[{"start":{"row":1,"column":16},"end":{"row":1,"column":17},"action":"insert","lines":[">"],"id":15}],[{"start":{"row":12,"column":21},"end":{"row":12,"column":25},"action":"remove","lines":["pass"],"id":16},{"start":{"row":12,"column":21},"end":{"row":12,"column":22},"action":"insert","lines":["_"]},{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"insert","lines":["s"]},{"start":{"row":12,"column":23},"end":{"row":12,"column":24},"action":"insert","lines":["t"]},{"start":{"row":12,"column":24},"end":{"row":12,"column":25},"action":"insert","lines":["r"]},{"start":{"row":12,"column":25},"end":{"row":12,"column":26},"action":"insert","lines":["i"]},{"start":{"row":12,"column":26},"end":{"row":12,"column":27},"action":"insert","lines":["n"]},{"start":{"row":12,"column":27},"end":{"row":12,"column":28},"action":"insert","lines":["g"]}],[{"start":{"row":8,"column":16},"end":{"row":8,"column":27},"action":"remove","lines":["$1$abcdefgh"],"id":17},{"start":{"row":8,"column":16},"end":{"row":8,"column":17},"action":"insert","lines":["a"]},{"start":{"row":8,"column":17},"end":{"row":8,"column":18},"action":"insert","lines":["b"]}],[{"start":{"row":8,"column":16},"end":{"row":8,"column":18},"action":"remove","lines":["ab"],"id":18},{"start":{"row":8,"column":16},"end":{"row":8,"column":17},"action":"insert","lines":["5"]},{"start":{"row":8,"column":17},"end":{"row":8,"column":18},"action":"insert","lines":["0"]}],[{"start":{"row":12,"column":1},"end":{"row":12,"column":2},"action":"insert","lines":["c"],"id":23},{"start":{"row":12,"column":2},"end":{"row":12,"column":3},"action":"insert","lines":["h"]},{"start":{"row":12,"column":3},"end":{"row":12,"column":4},"action":"insert","lines":["a"]},{"start":{"row":12,"column":4},"end":{"row":12,"column":5},"action":"insert","lines":["r"]}],[{"start":{"row":12,"column":5},"end":{"row":12,"column":6},"action":"insert","lines":[" "],"id":24},{"start":{"row":12,"column":6},"end":{"row":12,"column":7},"action":"insert","lines":["*"]}],[{"start":{"row":9,"column":1},"end":{"row":9,"column":16},"action":"remove","lines":["char *password;"],"id":25},{"start":{"row":9,"column":0},"end":{"row":9,"column":1},"action":"remove","lines":["\t"]},{"start":{"row":8,"column":48},"end":{"row":9,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":14,"column":4},"end":{"row":14,"column":5},"action":"remove","lines":["s"],"id":26},{"start":{"row":14,"column":3},"end":{"row":14,"column":4},"action":"remove","lines":["t"]},{"start":{"row":14,"column":2},"end":{"row":14,"column":3},"action":"remove","lines":["u"]}],[{"start":{"row":14,"column":2},"end":{"row":14,"column":3},"action":"insert","lines":["r"],"id":27},{"start":{"row":14,"column":3},"end":{"row":14,"column":4},"action":"insert","lines":["i"]},{"start":{"row":14,"column":4},"end":{"row":14,"column":5},"action":"insert","lines":["n"]},{"start":{"row":14,"column":5},"end":{"row":14,"column":6},"action":"insert","lines":["t"]},{"start":{"row":14,"column":6},"end":{"row":14,"column":7},"action":"insert","lines":["f"]}],[{"start":{"row":14,"column":8},"end":{"row":14,"column":9},"action":"insert","lines":["\""],"id":28}],[{"start":{"row":14,"column":17},"end":{"row":14,"column":18},"action":"insert","lines":["\""],"id":29}],[{"start":{"row":14,"column":17},"end":{"row":14,"column":18},"action":"insert","lines":["\\"],"id":30},{"start":{"row":14,"column":18},"end":{"row":14,"column":19},"action":"insert","lines":["n"]}],[{"start":{"row":14,"column":9},"end":{"row":14,"column":17},"action":"remove","lines":["password"],"id":31},{"start":{"row":14,"column":9},"end":{"row":14,"column":10},"action":"insert","lines":["%"]},{"start":{"row":14,"column":10},"end":{"row":14,"column":11},"action":"insert","lines":["c"]}],[{"start":{"row":14,"column":14},"end":{"row":14,"column":15},"action":"insert","lines":[","],"id":32}],[{"start":{"row":14,"column":15},"end":{"row":14,"column":16},"action":"insert","lines":[" "],"id":33},{"start":{"row":14,"column":16},"end":{"row":14,"column":17},"action":"insert","lines":["p"]},{"start":{"row":14,"column":17},"end":{"row":14,"column":18},"action":"insert","lines":["a"]},{"start":{"row":14,"column":18},"end":{"row":14,"column":19},"action":"insert","lines":["s"]},{"start":{"row":14,"column":19},"end":{"row":14,"column":20},"action":"insert","lines":["s"]},{"start":{"row":14,"column":20},"end":{"row":14,"column":21},"action":"insert","lines":["w"]},{"start":{"row":14,"column":21},"end":{"row":14,"column":22},"action":"insert","lines":["o"]},{"start":{"row":14,"column":22},"end":{"row":14,"column":23},"action":"insert","lines":["r"]},{"start":{"row":14,"column":23},"end":{"row":14,"column":24},"action":"insert","lines":["d"]}],[{"start":{"row":14,"column":10},"end":{"row":14,"column":11},"action":"remove","lines":["c"],"id":34}],[{"start":{"row":14,"column":10},"end":{"row":14,"column":11},"action":"insert","lines":["s"],"id":35}],[{"start":{"row":8,"column":1},"end":{"row":8,"column":5},"action":"remove","lines":["char"],"id":36},{"start":{"row":8,"column":1},"end":{"row":8,"column":2},"action":"insert","lines":["s"]},{"start":{"row":8,"column":2},"end":{"row":8,"column":3},"action":"insert","lines":["t"]},{"start":{"row":8,"column":3},"end":{"row":8,"column":4},"action":"insert","lines":["r"]},{"start":{"row":8,"column":4},"end":{"row":8,"column":5},"action":"insert","lines":["i"]},{"start":{"row":8,"column":5},"end":{"row":8,"column":6},"action":"insert","lines":["n"]},{"start":{"row":8,"column":6},"end":{"row":8,"column":7},"action":"insert","lines":["g"]}],[{"start":{"row":8,"column":1},"end":{"row":8,"column":7},"action":"remove","lines":["string"],"id":37},{"start":{"row":8,"column":1},"end":{"row":8,"column":2},"action":"insert","lines":["c"]},{"start":{"row":8,"column":2},"end":{"row":8,"column":3},"action":"insert","lines":["r"]},{"start":{"row":8,"column":3},"end":{"row":8,"column":4},"action":"insert","lines":["a"]}],[{"start":{"row":8,"column":3},"end":{"row":8,"column":4},"action":"remove","lines":["a"],"id":38},{"start":{"row":8,"column":2},"end":{"row":8,"column":3},"action":"remove","lines":["r"]}],[{"start":{"row":8,"column":2},"end":{"row":8,"column":3},"action":"insert","lines":["h"],"id":39},{"start":{"row":8,"column":3},"end":{"row":8,"column":4},"action":"insert","lines":["a"]},{"start":{"row":8,"column":4},"end":{"row":8,"column":5},"action":"insert","lines":["r"]}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":8,"column":5},"end":{"row":8,"column":5},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1540352435469,"hash":"7ad783292b7d45d1c56494bc35ef4bc78d0eaea4"}