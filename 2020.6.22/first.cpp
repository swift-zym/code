//
// Created by swift on 2020/6/22.
//

#include<bits/stdc++.h>
using namespace std;
/*
 * {
	"pageTree": {
		"name": "洛谷",
		"template": "Excited",
		"route": "index",
		"children": [{
			"route": "theme.list",
			"template": "theme.list",
			"name": "主题商店",
			"children": [{
				"route": "theme.design",
				"template": "theme.designer",
				"name": "主题设计",
				"url": null
			}],
			"url": "\/theme\/list"
		}, {
			"route": "user.show",
			"template": "user.show",
			"name": "个人中心",
			"url": null
		}, {
			"route": "problem.list",
			"template": "problem.list",
			"name": "题目列表",
			"children": [{
				"route": "problem.show",
				"template": "problem.show",
				"name": "题目详情",
				"children": [{
					"route": "problem.edit",
					"template": "problem.edit",
					"name": "题目编辑",
					"url": null
				}, {
					"route": "problem.solution",
					"template": "problem.solution",
					"name": "查看题解",
					"url": null
				}],
				"url": null
			}],
			"url": "\/problem\/list"
		}, {
			"name": "比赛列表",
			"template": "contest.list",
			"route": "contest.list",
			"children": [{
				"name": "比赛详情",
				"route": "contest.show",
				"template": "contest.show",
				"url": null
			}, {
				"name": "编辑比赛",
				"template": "contest.edit",
				"route": "contest.edit",
				"url": null
			}],
			"url": "\/contest\/list"
		}, {
			"name": "评测记录",
			"template": "record.list",
			"route": "record.list",
			"children": [{
				"name": "评测详情",
				"template": "record.show",
				"route": "record.show",
				"url": null
			}],
			"url": "\/record\/list"
		}, {
			"name": "讨论列表",
			"template": "Excited",
			"route": "discuss.list",
			"children": [{
				"name": "讨论详情",
				"template": "Excited",
				"route": "discuss.show",
				"url": null
			}],
			"url": "\/discuss\/lists"
		}, {
			"name": "题单列表",
			"template": "training.list",
			"route": "training.list",
			"children": [{
				"name": "题单详情",
				"template": "training.show",
				"route": "training.show",
				"url": null
			}, {
				"name": "编辑题单",
				"template": "training.edit",
				"route": "training.edit",
				"url": null
			}],
			"url": "\/training\/list"
		}, {
			"name": "团队详情",
			"template": "team.show",
			"route": "team.show",
			"children": [{
				"name": "团队设置",
				"template": "team.setting",
				"route": "team.setting",
				"url": null
			}],
			"url": null
		}, {
			"name": "创建题单",
			"template": "team.create",
			"route": "team.create",
			"url": "\/team\/create"
		}, {
			"name": "图片上传",
			"template": "image.list",
			"route": "image.list",
			"url": "\/image"
		}, {
			"name": "云剪贴板",
			"template": "paste.list",
			"route": "paste.list",
			"url": "\/paste"
		}, {
			"name": "云剪贴板",
			"template": "paste.show",
			"route": "paste.show",
			"url": null
		}, {
			"name": "咕值排名",
			"template": "rank.list",
			"route": "ranking.list",
			"url": "\/ranking"
		}, {
			"name": "创建团队",
			"template": "Excited",
			"route": "team.apply"
		}],
		"url": "\/"
	},
	"ws": {
		"server": "wss:\/\/ws.luogu.com.cn\/ws"
	},
	"codeLanguages": {
		"1": {
			"aceMode": "pascal",
			"name": "Pascal",
			"fileExtensions": ".pas",
			"id": 1
		},
		"2": {
			"aceMode": "c_cpp",
			"name": "C",
			"fileExtensions": ".c",
			"id": 2
		},
		"3": {
			"aceMode": "c_cpp",
			"name": "C++",
			"fileExtensions": ".cpp, .cc, cxx",
			"id": 3
		},
		"4": {
			"aceMode": "c_cpp",
			"name": "C++11",
			"fileExtensions": ".cpp, .cc, .cxx",
			"id": 4
		},
		"11": {
			"aceMode": "c_cpp",
			"name": "C++14",
			"fileExtensions": ".cpp, .cc, cxx",
			"id": 11
		},
		"12": {
			"aceMode": "c_cpp",
			"name": "C++17",
			"fileExtensions": ".cpp, .cc, .cxx",
			"id": 12
		},
		"5": {
			"aceMode": "plain_text",
			"name": "提交答案",
			"fileExtensions": "",
			"id": 5
		},
		"6": {
			"aceMode": "python",
			"name": "Python 2",
			"fileExtensions": ".py",
			"id": 6
		},
		"7": {
			"aceMode": "python",
			"name": "Python 3",
			"fileExtensions": ".py",
			"id": 7
		},
		"8": {
			"aceMode": "java",
			"name": "Java 8",
			"fileExtensions": ".java",
			"id": 8
		},
		"9": {
			"aceMode": "javascript",
			"name": "Node v8.9",
			"fileExtensions": ".js",
			"id": 9
		},
		"13": {
			"aceMode": "ruby",
			"name": "Ruby",
			"fileExtensions": ".rb",
			"id": 13
		},
		"14": {
			"aceMode": "golang",
			"name": "Go",
			"fileExtensions": ".go",
			"id": 14
		},
		"15": {
			"aceMode": "rust",
			"name": "Rust",
			"fileExtensions": ".rs",
			"id": 15
		},
		"16": {
			"aceMode": "php",
			"name": "PHP 7",
			"fileExtensions": ".php",
			"id": 16
		},
		"17": {
			"aceMode": "csharp",
			"name": "C# Mono",
			"fileExtensions": ".cs",
			"id": 17
		},
		"18": {
			"aceMode": "vbscript",
			"name": "Visual Basic Mono",
			"fileExtensions": ".vb",
			"id": 18
		},
		"19": {
			"aceMode": "haskell",
			"name": "Haskell",
			"fileExtensions": ".hs",
			"id": 19
		},
		"20": {
			"aceMode": "kotlin",
			"name": "Kotlin\/Native",
			"fileExtensions": ".kt",
			"id": 20
		},
		"21": {
			"aceMode": "kotlin",
			"name": "Kotlin\/JVM",
			"fileExtensions": ".kt",
			"id": 21
		},
		"22": {
			"aceMode": "scala",
			"name": "Scala",
			"fileExtensions": ".scala",
			"id": 22
		},
		"23": {
			"aceMode": "perl",
			"name": "Perl",
			"fileExtensions": ".pl",
			"id": 23
		},
		"24": {
			"aceMode": "python",
			"name": "PyPy 2",
			"fileExtensions": ".py",
			"id": 24
		},
		"25": {
			"aceMode": "python",
			"name": "PyPy 3",
			"fileExtensions": ".py",
			"id": 25
		},
		"26": {
			"aceMode": "plain_text",
			"name": "文言",
			"fileExtensions": ".wenyan",
			"id": 26
		}
	},
	"contestRuleTypes": {
		"1": {
			"id": 1,
			"name": "OI",
			"color": "orange-3"
		},
		"2": {
			"id": 2,
			"name": "ACM",
			"color": "purple-3"
		},
		"3": {
			"id": 3,
			"name": "乐多",
			"color": "gold-3"
		},
		"4": {
			"id": 4,
			"name": "IOI",
			"color": "gold-3"
		},
		"5": {
			"id": 5,
			"name": "CodeForces (暂不可用)",
			"color": "gold-3"
		}
	},
	"recordStatus": {
		"-1": {
			"id": -1,
			"name": "Unshown",
			"shortName": "Unshown",
			"color": "grey-5",
			"filterable": false
		},
		"0": {
			"id": 0,
			"name": "Waiting",
			"shortName": "Waiting",
			"color": "blue-4",
			"filterable": false
		},
		"1": {
			"id": 1,
			"name": "Judging",
			"shortName": "Judging",
			"color": "blue-3",
			"filterable": false
		},
		"2": {
			"id": 2,
			"name": "Compile Error",
			"shortName": "CE",
			"color": "yellow-3",
			"filterable": true
		},
		"3": {
			"id": 3,
			"name": "Output Limit Exceeded",
			"shortName": "OLE",
			"color": "blue-5",
			"filterable": false
		},
		"4": {
			"id": 4,
			"name": "Memory Limit Exceeded",
			"shortName": "MLE",
			"color": "blue-5",
			"filterable": false
		},
		"5": {
			"id": 5,
			"name": "Time Limit Exceeded",
			"shortName": "TLE",
			"color": "blue-5",
			"filterable": false
		},
		"6": {
			"id": 6,
			"name": "Wrong Answer",
			"shortName": "WA",
			"color": "red-3",
			"filterable": false
		},
		"7": {
			"id": 7,
			"name": "Runtime Error",
			"shortName": "RE",
			"color": "purple-3",
			"filterable": false
		},
		"11": {
			"id": 11,
			"name": "Unknown Error",
			"shortName": "UKE",
			"color": "lapis-4",
			"filterable": false
		},
		"12": {
			"id": 12,
			"name": "Accepted",
			"shortName": "AC",
			"color": "green-3",
			"filterable": true
		},
		"14": {
			"id": 14,
			"name": "Unaccepted",
			"shortName": "Unaccepted",
			"color": "red-3",
			"filterable": true
		},
		"21": {
			"id": 21,
			"name": "Hack Success",
			"shortName": "Hack Success",
			"color": "green-3",
			"filterable": false
		},
		"22": {
			"id": 22,
			"name": "Hack Failure",
			"shortName": "Hack Failure",
			"color": "red-3",
			"filterable": false
		},
		"23": {
			"id": 23,
			"name": "Hack Skipped",
			"shortName": "Hack Skipped",
			"color": "blue-5",
			"filterable": false
		}
	},
	"tags": {
		"1": {
			"name": "模拟",
			"type": "Algorithm",
			"color": "red"
		},
		"2": {
			"name": "字符串",
			"type": "Algorithm",
			"color": "red"
		},
		"3": {
			"name": "动态规划,动规,dp",
			"type": "Algorithm",
			"color": "red"
		},
		"4": {
			"name": "搜索",
			"type": "Algorithm",
			"color": "red"
		},
		"5": {
			"name": "数论,数学",
			"type": "Algorithm",
			"color": "red"
		},
		"6": {
			"name": "图论",
			"type": "Algorithm",
			"color": "red"
		},
		"7": {
			"name": "贪心",
			"type": "Algorithm",
			"color": "red"
		},
		"8": {
			"name": "计算几何",
			"type": "Algorithm",
			"color": "red"
		},
		"9": {
			"name": "暴力数据结构",
			"type": "Algorithm",
			"color": "red"
		},
		"10": {
			"name": "高精",
			"type": "Algorithm",
			"color": "red"
		},
		"11": {
			"name": "树形结构",
			"type": "Algorithm",
			"color": "red"
		},
		"12": {
			"name": "递推",
			"type": "Algorithm",
			"color": "red"
		},
		"13": {
			"name": "博弈论",
			"type": "Algorithm",
			"color": "red"
		},
		"14": {
			"name": "1997",
			"type": "Time",
			"color": "blue"
		},
		"15": {
			"name": "1998",
			"type": "Time",
			"color": "blue"
		},
		"16": {
			"name": "1999",
			"type": "Time",
			"color": "blue"
		},
		"17": {
			"name": "2000",
			"type": "Time",
			"color": "blue"
		},
		"18": {
			"name": "2001(或之前)",
			"type": "Time",
			"color": "blue"
		},
		"19": {
			"name": "2002",
			"type": "Time",
			"color": "blue"
		},
		"20": {
			"name": "2003",
			"type": "Time",
			"color": "blue"
		},
		"21": {
			"name": "2004",
			"type": "Time",
			"color": "blue"
		},
		"22": {
			"name": "2005",
			"type": "Time",
			"color": "blue"
		},
		"23": {
			"name": "2006",
			"type": "Time",
			"color": "blue"
		},
		"24": {
			"name": "2007",
			"type": "Time",
			"color": "blue"
		},
		"25": {
			"name": "2008",
			"type": "Time",
			"color": "blue"
		},
		"26": {
			"name": "2009",
			"type": "Time",
			"color": "blue"
		},
		"27": {
			"name": "2010",
			"type": "Time",
			"color": "blue"
		},
		"28": {
			"name": "2011",
			"type": "Time",
			"color": "blue"
		},
		"29": {
			"name": "2012",
			"type": "Time",
			"color": "blue"
		},
		"30": {
			"name": "2013",
			"type": "Time",
			"color": "blue"
		},
		"31": {
			"name": "2014",
			"type": "Time",
			"color": "blue"
		},
		"32": {
			"name": "2015",
			"type": "Time",
			"color": "blue"
		},
		"33": {
			"name": "2016",
			"type": "Time",
			"color": "blue"
		},
		"34": {
			"name": "2017",
			"type": "Time",
			"color": "blue"
		},
		"35": {
			"name": "2018",
			"type": "Time",
			"color": "blue"
		},
		"36": {
			"name": "2019",
			"type": "Time",
			"color": "blue"
		},
		"37": {
			"name": "2020",
			"type": "Time",
			"color": "blue"
		},
		"38": {
			"name": "重庆",
			"type": "Region",
			"color": "green"
		},
		"39": {
			"name": "四川",
			"type": "Region",
			"color": "green"
		},
		"40": {
			"name": "河南",
			"type": "Region",
			"color": "green"
		},
		"41": {
			"name": "莫队",
			"type": "Algorithm",
			"color": "red"
		},
		"42": {
			"name": "线段树",
			"type": "Algorithm",
			"color": "red"
		},
		"43": {
			"name": "倍增",
			"type": "Algorithm",
			"color": "red"
		},
		"44": {
			"name": "线性结构",
			"type": "Algorithm",
			"color": "red"
		},
		"45": {
			"name": "二分答案",
			"type": "Algorithm",
			"color": "red"
		},
		"46": {
			"name": "USACO",
			"type": "Origin",
			"color": "blue"
		},
		"47": {
			"name": "并查集",
			"type": "Algorithm",
			"color": "red"
		},
		"48": {
			"name": "各省省选",
			"type": "Origin",
			"color": "blue"
		},
		"49": {
			"name": "点分治",
			"type": "Algorithm",
			"color": "red"
		},
		"50": {
			"name": "平衡树",
			"type": "Algorithm",
			"color": "red"
		},
		"51": {
			"name": "二叉堆",
			"type": "Algorithm",
			"color": "red"
		},
		"52": {
			"name": "WC\/CTSC\/集训队",
			"type": "Origin",
			"color": "blue"
		},
		"53": {
			"name": "树状数组",
			"type": "Algorithm",
			"color": "red"
		},
		"54": {
			"name": "递归",
			"type": "Algorithm",
			"color": "red"
		},
		"55": {
			"name": "最大匹配",
			"type": "Algorithm",
			"color": "red"
		},
		"56": {
			"name": "单调队列",
			"type": "Algorithm",
			"color": "red"
		},
		"57": {
			"name": "POI",
			"type": "Origin",
			"color": "blue"
		},
		"58": {
			"name": "2021",
			"type": "Time",
			"color": "blue"
		},
		"59": {
			"name": "2022",
			"type": "Time",
			"color": "blue"
		},
		"60": {
			"name": "2023",
			"type": "Time",
			"color": "blue"
		},
		"61": {
			"name": "2024",
			"type": "Time",
			"color": "blue"
		},
		"62": {
			"name": "2025",
			"type": "Time",
			"color": "blue"
		},
		"63": {
			"name": "NOI2007",
			"type": "Unknown",
			"color": "black"
		},
		"64": {
			"name": "NOI2008",
			"type": "Unknown",
			"color": "black"
		},
		"65": {
			"name": "NOI2009",
			"type": "Unknown",
			"color": "black"
		},
		"66": {
			"name": "NOI2010",
			"type": "Unknown",
			"color": "black"
		},
		"67": {
			"name": "NOI2011",
			"type": "Unknown",
			"color": "black"
		},
		"68": {
			"name": "NOI2012",
			"type": "Unknown",
			"color": "black"
		},
		"69": {
			"name": "NOI2013",
			"type": "Unknown",
			"color": "black"
		},
		"70": {
			"name": "福建省历届夏令营",
			"type": "Origin",
			"color": "blue"
		},
		"71": {
			"name": "矩阵运算",
			"type": "Algorithm",
			"color": "red"
		},
		"72": {
			"name": "整数研究",
			"type": "Algorithm",
			"color": "red"
		},
		"73": {
			"name": "算法",
			"type": "Unknown",
			"color": "black"
		},
		"74": {
			"name": "数据结构",
			"type": "Unknown",
			"color": "black"
		},
		"75": {
			"name": "来源",
			"type": "Unknown",
			"color": "black"
		},
		"76": {
			"name": "时间",
			"type": "Unknown",
			"color": "black"
		},
		"77": {
			"name": "NOI系列",
			"type": "Origin",
			"color": "blue"
		},
		"78": {
			"name": "离散化",
			"type": "Algorithm",
			"color": "red"
		},
		"79": {
			"name": "网络流",
			"type": "Algorithm",
			"color": "red"
		},
		"80": {
			"name": "高级数据结构",
			"type": "Unknown",
			"color": "black"
		},
		"81": {
			"name": "洛谷原创",
			"type": "Origin",
			"color": "blue"
		},
		"82": {
			"name": "NOIp普及组",
			"type": "Origin",
			"color": "blue"
		},
		"83": {
			"name": "NOIp提高组",
			"type": "Origin",
			"color": "blue"
		},
		"84": {
			"name": "NOIp初赛",
			"type": "Origin",
			"color": "blue"
		},
		"85": {
			"name": "APIO",
			"type": "Origin",
			"color": "blue"
		},
		"86": {
			"name": "垃圾",
			"type": "Unknown",
			"color": "black"
		},
		"87": {
			"name": "地区",
			"type": "Unknown",
			"color": "black"
		},
		"88": {
			"name": "浙江",
			"type": "Region",
			"color": "green"
		},
		"89": {
			"name": "上海",
			"type": "Region",
			"color": "green"
		},
		"90": {
			"name": "福建",
			"type": "Region",
			"color": "green"
		},
		"91": {
			"name": "江苏",
			"type": "Region",
			"color": "green"
		},
		"92": {
			"name": "安徽",
			"type": "Region",
			"color": "green"
		},
		"93": {
			"name": "湖南",
			"type": "Region",
			"color": "green"
		},
		"94": {
			"name": "北京",
			"type": "Region",
			"color": "green"
		},
		"95": {
			"name": "河北",
			"type": "Region",
			"color": "green"
		},
		"96": {
			"name": "广东",
			"type": "Region",
			"color": "green"
		},
		"97": {
			"name": "山东",
			"type": "Region",
			"color": "green"
		},
		"98": {
			"name": "吉林",
			"type": "Region",
			"color": "green"
		},
		"99": {
			"name": "NOI导刊",
			"type": "Origin",
			"color": "blue"
		},
		"100": {
			"name": "cdq分治",
			"type": "Algorithm",
			"color": "red"
		},
		"101": {
			"name": "后缀自动机,SAM",
			"type": "Algorithm",
			"color": "red"
		},
		"102": {
			"name": "IOI",
			"type": "Origin",
			"color": "blue"
		},
		"103": {
			"name": "交互题",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"104": {
			"name": "提交答案",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"105": {
			"name": "特殊题目",
			"type": "Unknown",
			"color": "black"
		},
		"106": {
			"name": "初赛",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"107": {
			"name": "Special Judge",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"108": {
			"name": "O2优化",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"109": {
			"name": "新云端",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"110": {
			"name": "﻿基础算法",
			"type": "Algorithm",
			"color": "red"
		},
		"111": {
			"name": "枚举,暴力",
			"type": "Algorithm",
			"color": "red"
		},
		"112": {
			"name": "分治",
			"type": "Algorithm",
			"color": "red"
		},
		"113": {
			"name": "排序",
			"type": "Algorithm",
			"color": "red"
		},
		"114": {
			"name": "冒泡排序",
			"type": "Algorithm",
			"color": "red"
		},
		"115": {
			"name": "选择排序",
			"type": "Algorithm",
			"color": "red"
		},
		"116": {
			"name": "桶排",
			"type": "Algorithm",
			"color": "red"
		},
		"117": {
			"name": "插入排序",
			"type": "Algorithm",
			"color": "red"
		},
		"118": {
			"name": "归并排序",
			"type": "Algorithm",
			"color": "red"
		},
		"119": {
			"name": "快速排序,快排",
			"type": "Algorithm",
			"color": "red"
		},
		"120": {
			"name": "堆排序",
			"type": "Algorithm",
			"color": "red"
		},
		"121": {
			"name": "希尔排序",
			"type": "Algorithm",
			"color": "red"
		},
		"122": {
			"name": "外部排序",
			"type": "Algorithm",
			"color": "red"
		},
		"123": {
			"name": "查找算法",
			"type": "Algorithm",
			"color": "red"
		},
		"124": {
			"name": "顺序查找",
			"type": "Algorithm",
			"color": "red"
		},
		"125": {
			"name": "二分查找",
			"type": "Algorithm",
			"color": "red"
		},
		"126": {
			"name": "广度优先搜索,BFS",
			"type": "Algorithm",
			"color": "red"
		},
		"127": {
			"name": "深度优先搜索,DFS",
			"type": "Algorithm",
			"color": "red"
		},
		"128": {
			"name": "剪枝",
			"type": "Algorithm",
			"color": "red"
		},
		"129": {
			"name": "记忆化搜索",
			"type": "Algorithm",
			"color": "red"
		},
		"130": {
			"name": "启发式搜索",
			"type": "Algorithm",
			"color": "red"
		},
		"131": {
			"name": "迭代加深",
			"type": "Algorithm",
			"color": "red"
		},
		"132": {
			"name": "启发式迭代加深,IDA*",
			"type": "Algorithm",
			"color": "red"
		},
		"133": {
			"name": "Dancing Links",
			"type": "Algorithm",
			"color": "red"
		},
		"134": {
			"name": "爬山法",
			"type": "Algorithm",
			"color": "red"
		},
		"135": {
			"name": "模拟退火",
			"type": "Algorithm",
			"color": "red"
		},
		"136": {
			"name": "随机调整",
			"type": "Algorithm",
			"color": "red"
		},
		"137": {
			"name": "遗传",
			"type": "Algorithm",
			"color": "red"
		},
		"138": {
			"name": "动态规划初步",
			"type": "Algorithm",
			"color": "red"
		},
		"139": {
			"name": "背包",
			"type": "Algorithm",
			"color": "red"
		},
		"140": {
			"name": "环型动规,环型dp",
			"type": "Algorithm",
			"color": "red"
		},
		"141": {
			"name": "数位动规,数位dp",
			"type": "Algorithm",
			"color": "red"
		},
		"142": {
			"name": "序列型动规,序列型dp",
			"type": "Unknown",
			"color": "black"
		},
		"143": {
			"name": "多维状态",
			"type": "Algorithm",
			"color": "red"
		},
		"144": {
			"name": "区间动规,区间dp",
			"type": "Algorithm",
			"color": "red"
		},
		"145": {
			"name": "子母树",
			"type": "Algorithm",
			"color": "red"
		},
		"146": {
			"name": "动态规划优化",
			"type": "Algorithm",
			"color": "red"
		},
		"147": {
			"name": "降低维度,降维",
			"type": "Algorithm",
			"color": "red"
		},
		"148": {
			"name": "优先队列",
			"type": "Algorithm",
			"color": "red"
		},
		"149": {
			"name": "矩阵加速,矩阵优化",
			"type": "Algorithm",
			"color": "red"
		},
		"150": {
			"name": "斜率优化",
			"type": "Algorithm",
			"color": "red"
		},
		"151": {
			"name": "状态压缩,状压",
			"type": "Algorithm",
			"color": "red"
		},
		"152": {
			"name": "树形动规",
			"type": "Algorithm",
			"color": "red"
		},
		"153": {
			"name": "凸完全单调性,凸单调",
			"type": "Algorithm",
			"color": "red"
		},
		"154": {
			"name": "四边形不等式",
			"type": "Algorithm",
			"color": "red"
		},
		"155": {
			"name": "图的建立,建图",
			"type": "Algorithm",
			"color": "red"
		},
		"156": {
			"name": "邻接矩阵",
			"type": "Algorithm",
			"color": "red"
		},
		"157": {
			"name": "邻接表",
			"type": "Algorithm",
			"color": "red"
		},
		"158": {
			"name": "图遍历",
			"type": "Algorithm",
			"color": "red"
		},
		"159": {
			"name": "拓扑排序",
			"type": "Algorithm",
			"color": "red"
		},
		"160": {
			"name": "最短路",
			"type": "Algorithm",
			"color": "red"
		},
		"161": {
			"name": "Floyd",
			"type": "Algorithm",
			"color": "red"
		},
		"162": {
			"name": "Dijkstra",
			"type": "Algorithm",
			"color": "red"
		},
		"163": {
			"name": "Bellman-Ford",
			"type": "Algorithm",
			"color": "red"
		},
		"164": {
			"name": "SPFA",
			"type": "Algorithm",
			"color": "red"
		},
		"165": {
			"name": "K短路",
			"type": "Algorithm",
			"color": "red"
		},
		"166": {
			"name": "生成树",
			"type": "Algorithm",
			"color": "red"
		},
		"167": {
			"name": "Prim",
			"type": "Algorithm",
			"color": "red"
		},
		"168": {
			"name": "Kruskal",
			"type": "Algorithm",
			"color": "red"
		},
		"169": {
			"name": "生成树的另类算法",
			"type": "Algorithm",
			"color": "red"
		},
		"170": {
			"name": "次小生成树",
			"type": "Algorithm",
			"color": "red"
		},
		"171": {
			"name": "特殊生成树",
			"type": "Algorithm",
			"color": "red"
		},
		"172": {
			"name": "圈和块",
			"type": "Algorithm",
			"color": "red"
		},
		"173": {
			"name": "最小环",
			"type": "Algorithm",
			"color": "red"
		},
		"174": {
			"name": "负权环",
			"type": "Algorithm",
			"color": "red"
		},
		"175": {
			"name": "连通块",
			"type": "Algorithm",
			"color": "red"
		},
		"176": {
			"name": "2-SAT",
			"type": "Algorithm",
			"color": "red"
		},
		"177": {
			"name": "欧拉公式",
			"type": "Algorithm",
			"color": "red"
		},
		"178": {
			"name": "四色定理",
			"type": "Algorithm",
			"color": "red"
		},
		"179": {
			"name": "强连通分量,缩点",
			"type": "Algorithm",
			"color": "red"
		},
		"180": {
			"name": "Tarjan",
			"type": "Algorithm",
			"color": "red"
		},
		"181": {
			"name": "割点",
			"type": "Algorithm",
			"color": "red"
		},
		"182": {
			"name": "欧拉回路",
			"type": "Algorithm",
			"color": "red"
		},
		"183": {
			"name": "AOV",
			"type": "Algorithm",
			"color": "red"
		},
		"184": {
			"name": "AOE",
			"type": "Algorithm",
			"color": "red"
		},
		"185": {
			"name": "差分约束",
			"type": "Algorithm",
			"color": "red"
		},
		"186": {
			"name": "仙人掌",
			"type": "Algorithm",
			"color": "red"
		},
		"187": {
			"name": "二分图",
			"type": "Algorithm",
			"color": "red"
		},
		"188": {
			"name": "匈牙利算法",
			"type": "Algorithm",
			"color": "red"
		},
		"189": {
			"name": "一般图的最大匹配",
			"type": "Algorithm",
			"color": "red"
		},
		"190": {
			"name": "Konig定理",
			"type": "Algorithm",
			"color": "red"
		},
		"191": {
			"name": "带权二分图匹配",
			"type": "Algorithm",
			"color": "red"
		},
		"192": {
			"name": "KM算法",
			"type": "Algorithm",
			"color": "red"
		},
		"193": {
			"name": "稳定婚姻系统",
			"type": "Algorithm",
			"color": "red"
		},
		"194": {
			"name": "最大流",
			"type": "Algorithm",
			"color": "red"
		},
		"195": {
			"name": "Dinic",
			"type": "Algorithm",
			"color": "red"
		},
		"196": {
			"name": "Sap",
			"type": "Algorithm",
			"color": "red"
		},
		"197": {
			"name": "有上下界的最大流",
			"type": "Algorithm",
			"color": "red"
		},
		"198": {
			"name": "最小割",
			"type": "Algorithm",
			"color": "red"
		},
		"199": {
			"name": "闭合图",
			"type": "Algorithm",
			"color": "red"
		},
		"200": {
			"name": "最小点权覆盖集",
			"type": "Algorithm",
			"color": "red"
		},
		"201": {
			"name": "最大点权独立集",
			"type": "Algorithm",
			"color": "red"
		},
		"202": {
			"name": "分数规划",
			"type": "Algorithm",
			"color": "red"
		},
		"203": {
			"name": "最大密度子图",
			"type": "Algorithm",
			"color": "red"
		},
		"204": {
			"name": "费用流",
			"type": "Algorithm",
			"color": "red"
		},
		"205": {
			"name": "最短路增广费用流",
			"type": "Algorithm",
			"color": "red"
		},
		"206": {
			"name": "zkw费用流",
			"type": "Algorithm",
			"color": "red"
		},
		"207": {
			"name": "最小费用可行流",
			"type": "Algorithm",
			"color": "red"
		},
		"208": {
			"name": "树的遍历",
			"type": "Algorithm",
			"color": "red"
		},
		"209": {
			"name": "树上距离",
			"type": "Algorithm",
			"color": "red"
		},
		"210": {
			"name": "节点到根的距离",
			"type": "Algorithm",
			"color": "red"
		},
		"211": {
			"name": "最近公共祖先,LCA",
			"type": "Algorithm",
			"color": "red"
		},
		"212": {
			"name": "节点间的距离",
			"type": "Algorithm",
			"color": "red"
		},
		"213": {
			"name": "树的直径",
			"type": "Algorithm",
			"color": "red"
		},
		"214": {
			"name": "哈夫曼树",
			"type": "Algorithm",
			"color": "red"
		},
		"215": {
			"name": "左偏树",
			"type": "Algorithm",
			"color": "red"
		},
		"216": {
			"name": "斜堆",
			"type": "Algorithm",
			"color": "red"
		},
		"217": {
			"name": "二项堆",
			"type": "Algorithm",
			"color": "red"
		},
		"218": {
			"name": "AVL",
			"type": "Algorithm",
			"color": "red"
		},
		"219": {
			"name": "Treap",
			"type": "Algorithm",
			"color": "red"
		},
		"220": {
			"name": "SBT",
			"type": "Algorithm",
			"color": "red"
		},
		"221": {
			"name": "Splay",
			"type": "Algorithm",
			"color": "red"
		},
		"222": {
			"name": "静态排序树",
			"type": "Algorithm",
			"color": "red"
		},
		"223": {
			"name": "替罪羊树",
			"type": "Algorithm",
			"color": "red"
		},
		"224": {
			"name": "二维线段树",
			"type": "Algorithm",
			"color": "red"
		},
		"225": {
			"name": "矩形树",
			"type": "Algorithm",
			"color": "red"
		},
		"226": {
			"name": "zkw线段树",
			"type": "Algorithm",
			"color": "red"
		},
		"227": {
			"name": "动态树",
			"type": "Algorithm",
			"color": "red"
		},
		"228": {
			"name": "树链剖分,树剖",
			"type": "Algorithm",
			"color": "red"
		},
		"229": {
			"name": "Link-Cut Tree,LCT",
			"type": "Algorithm",
			"color": "red"
		},
		"230": {
			"name": "树的应用",
			"type": "Algorithm",
			"color": "red"
		},
		"231": {
			"name": "RMQ",
			"type": "Algorithm",
			"color": "red"
		},
		"232": {
			"name": "树套树",
			"type": "Algorithm",
			"color": "red"
		},
		"233": {
			"name": "主席树",
			"type": "Algorithm",
			"color": "red"
		},
		"234": {
			"name": "可持久化",
			"type": "Algorithm",
			"color": "red"
		},
		"235": {
			"name": "哈希,HASH",
			"type": "Algorithm",
			"color": "red"
		},
		"236": {
			"name": "ELFhash",
			"type": "Algorithm",
			"color": "red"
		},
		"237": {
			"name": "SDBM",
			"type": "Algorithm",
			"color": "red"
		},
		"238": {
			"name": "BKDR",
			"type": "Algorithm",
			"color": "red"
		},
		"239": {
			"name": "素数判断,质数,筛法",
			"type": "Algorithm",
			"color": "red"
		},
		"240": {
			"name": "众数",
			"type": "Algorithm",
			"color": "red"
		},
		"241": {
			"name": "最大公约数,gcd",
			"type": "Algorithm",
			"color": "red"
		},
		"242": {
			"name": "扩展欧几里德,扩欧",
			"type": "Algorithm",
			"color": "red"
		},
		"243": {
			"name": "不定方程",
			"type": "Algorithm",
			"color": "red"
		},
		"244": {
			"name": "进制",
			"type": "Algorithm",
			"color": "red"
		},
		"245": {
			"name": "集合论",
			"type": "Algorithm",
			"color": "red"
		},
		"246": {
			"name": "群论",
			"type": "Algorithm",
			"color": "red"
		},
		"247": {
			"name": "置换",
			"type": "Algorithm",
			"color": "red"
		},
		"248": {
			"name": "Polya原理",
			"type": "Algorithm",
			"color": "red"
		},
		"249": {
			"name": "虚树",
			"type": "Algorithm",
			"color": "red"
		},
		"250": {
			"name": "同余,中国剩余定理",
			"type": "Algorithm",
			"color": "red"
		},
		"251": {
			"name": "莫比乌斯反演",
			"type": "Algorithm",
			"color": "red"
		},
		"252": {
			"name": "组合数学",
			"type": "Algorithm",
			"color": "red"
		},
		"253": {
			"name": "排列组合",
			"type": "Algorithm",
			"color": "red"
		},
		"254": {
			"name": "前缀和",
			"type": "Algorithm",
			"color": "red"
		},
		"255": {
			"name": "二项式定理",
			"type": "Algorithm",
			"color": "red"
		},
		"256": {
			"name": "康托展开",
			"type": "Algorithm",
			"color": "red"
		},
		"257": {
			"name": "袋与球问题",
			"type": "Algorithm",
			"color": "red"
		},
		"258": {
			"name": "鸽笼",
			"type": "Algorithm",
			"color": "red"
		},
		"259": {
			"name": "容斥",
			"type": "Algorithm",
			"color": "red"
		},
		"260": {
			"name": "斐波那契,Fibonacci",
			"type": "Algorithm",
			"color": "red"
		},
		"261": {
			"name": "卡特兰,Catalan",
			"type": "Algorithm",
			"color": "red"
		},
		"262": {
			"name": "Stirling",
			"type": "Algorithm",
			"color": "red"
		},
		"263": {
			"name": "A*算法",
			"type": "Algorithm",
			"color": "red"
		},
		"264": {
			"name": "生成函数",
			"type": "Algorithm",
			"color": "red"
		},
		"265": {
			"name": "线性规划",
			"type": "Algorithm",
			"color": "red"
		},
		"266": {
			"name": "概率论,统计",
			"type": "Algorithm",
			"color": "red"
		},
		"267": {
			"name": "简单概率",
			"type": "Algorithm",
			"color": "red"
		},
		"268": {
			"name": "条件概率",
			"type": "Algorithm",
			"color": "red"
		},
		"269": {
			"name": "Bayes",
			"type": "Algorithm",
			"color": "red"
		},
		"270": {
			"name": "期望",
			"type": "Algorithm",
			"color": "red"
		},
		"271": {
			"name": "线性代数",
			"type": "Algorithm",
			"color": "red"
		},
		"272": {
			"name": "矩阵乘法",
			"type": "Algorithm",
			"color": "red"
		},
		"273": {
			"name": "线性递推,递推式",
			"type": "Algorithm",
			"color": "red"
		},
		"274": {
			"name": "高斯消元",
			"type": "Algorithm",
			"color": "red"
		},
		"275": {
			"name": "异或方程组",
			"type": "Algorithm",
			"color": "red"
		},
		"276": {
			"name": "逆元",
			"type": "Algorithm",
			"color": "red"
		},
		"277": {
			"name": "线性基",
			"type": "Algorithm",
			"color": "red"
		},
		"278": {
			"name": "微积分初步",
			"type": "Algorithm",
			"color": "red"
		},
		"279": {
			"name": "极限",
			"type": "Algorithm",
			"color": "red"
		},
		"280": {
			"name": "导数",
			"type": "Algorithm",
			"color": "red"
		},
		"281": {
			"name": "积分",
			"type": "Algorithm",
			"color": "red"
		},
		"282": {
			"name": "定积分",
			"type": "Algorithm",
			"color": "red"
		},
		"283": {
			"name": "立体解析几何",
			"type": "Algorithm",
			"color": "red"
		},
		"284": {
			"name": "级数",
			"type": "Algorithm",
			"color": "red"
		},
		"285": {
			"name": "基本数组",
			"type": "Algorithm",
			"color": "red"
		},
		"286": {
			"name": "向量",
			"type": "Algorithm",
			"color": "red"
		},
		"287": {
			"name": "栈",
			"type": "Algorithm",
			"color": "red"
		},
		"288": {
			"name": "队列",
			"type": "Algorithm",
			"color": "red"
		},
		"289": {
			"name": "块状链表,块状数组,分块",
			"type": "Algorithm",
			"color": "red"
		},
		"290": {
			"name": "st表,稀疏表",
			"type": "Algorithm",
			"color": "red"
		},
		"291": {
			"name": "凸包",
			"type": "Algorithm",
			"color": "red"
		},
		"292": {
			"name": "叉积",
			"type": "Algorithm",
			"color": "red"
		},
		"293": {
			"name": "线段相交",
			"type": "Algorithm",
			"color": "red"
		},
		"294": {
			"name": "点积",
			"type": "Algorithm",
			"color": "red"
		},
		"295": {
			"name": "半平面相交,半平面交",
			"type": "Algorithm",
			"color": "red"
		},
		"296": {
			"name": "最近点对",
			"type": "Algorithm",
			"color": "red"
		},
		"297": {
			"name": "凸多边形的交",
			"type": "Algorithm",
			"color": "red"
		},
		"298": {
			"name": "离散化扫描",
			"type": "Algorithm",
			"color": "red"
		},
		"299": {
			"name": "旋转卡壳",
			"type": "Algorithm",
			"color": "red"
		},
		"300": {
			"name": "字典树,Trie树",
			"type": "Algorithm",
			"color": "red"
		},
		"301": {
			"name": "AC自动机",
			"type": "Algorithm",
			"color": "red"
		},
		"302": {
			"name": "KMP",
			"type": "Algorithm",
			"color": "red"
		},
		"303": {
			"name": "后缀数组,SA",
			"type": "Algorithm",
			"color": "red"
		},
		"304": {
			"name": "后缀树",
			"type": "Algorithm",
			"color": "red"
		},
		"305": {
			"name": "有限状态自动机",
			"type": "Algorithm",
			"color": "red"
		},
		"306": {
			"name": "哈夫曼,Huffman",
			"type": "Algorithm",
			"color": "red"
		},
		"307": {
			"name": "简单密码学",
			"type": "Algorithm",
			"color": "red"
		},
		"308": {
			"name": "其它技巧",
			"type": "Algorithm",
			"color": "red"
		},
		"309": {
			"name": "随机贪心,随机化",
			"type": "Algorithm",
			"color": "red"
		},
		"310": {
			"name": "Nim游戏",
			"type": "Algorithm",
			"color": "red"
		},
		"311": {
			"name": "博弈树",
			"type": "Algorithm",
			"color": "red"
		},
		"312": {
			"name": "Shannon开关游戏",
			"type": "Algorithm",
			"color": "red"
		},
		"313": {
			"name": "快速傅里叶变换,DFT,FFT",
			"type": "Algorithm",
			"color": "red"
		},
		"314": {
			"name": "位运算,按位",
			"type": "Algorithm",
			"color": "red"
		},
		"315": {
			"name": "骗分",
			"type": "Algorithm",
			"color": "red"
		},
		"316": {
			"name": "整体二分",
			"type": "Algorithm",
			"color": "red"
		},
		"317": {
			"name": "NP问题",
			"type": "Algorithm",
			"color": "red"
		},
		"318": {
			"name": "构造",
			"type": "Algorithm",
			"color": "red"
		},
		"319": {
			"name": "高性能",
			"type": "SpecialProblem",
			"color": "orange"
		},
		"320": {
			"name": "环套树",
			"type": "Algorithm",
			"color": "red"
		},
		"321": {
			"name": "K-D Tree",
			"type": "Algorithm",
			"color": "red"
		},
		"322": {
			"name": "Lucas",
			"type": "Algorithm",
			"color": "red"
		},
		"323": {
			"name": "插头dp",
			"type": "Algorithm",
			"color": "red"
		},
		"324": {
			"name": "快速数论变换NTT",
			"type": "Algorithm",
			"color": "red"
		},
		"325": {
			"name": "回文自动机PAM",
			"type": "Algorithm",
			"color": "red"
		},
		"326": {
			"name": "快速沃尔什变换FWT",
			"type": "Algorithm",
			"color": "red"
		},
		"327": {
			"name": "快速沃尔什变换FWT",
			"type": "Algorithm",
			"color": "red"
		},
		"328": {
			"name": "天津",
			"type": "Region",
			"color": "green"
		},
		"329": {
			"name": "Manacher算法",
			"type": "Algorithm",
			"color": "red"
		},
		"330": {
			"name": "差分",
			"type": "Algorithm",
			"color": "red"
		},
		"331": {
			"name": "清华集训",
			"type": "Origin",
			"color": "blue"
		},
		"332": {
			"name": "网络流24题",
			"type": "Origin",
			"color": "blue"
		},
		"333": {
			"name": "COCI",
			"type": "Origin",
			"color": "blue"
		},
		"334": {
			"name": "BalticOI",
			"type": "Origin",
			"color": "blue"
		},
		"335": {
			"name": "ACM_ICPC",
			"type": "Origin",
			"color": "blue"
		},
		"336": {
			"name": "JOI",
			"type": "Origin",
			"color": "blue"
		}
	},
	"recordSortTypes": [{
		"id": 0,
		"name": "最新提交"
	}, {
		"id": 1,
		"name": "最优解"
	}],
	"messageStatusTypes": [{
		"id": 0,
		"name": "Deleted"
	}, {
		"id": 1,
		"name": "Unread"
	}, {
		"id": 2,
		"name": "Read"
	}],
	"translation": {
		"authenticate": {
			"logged_in": "您已经登录",
			"wrong_password": "密码不正确",
			"uid_mismatch": "UID不匹配",
			"incorrect_password_or_code": "输入的密码或者两步验证码错误",
			"unlocked": "用户已经解锁"
		},
		"ban": {
			"ip_ban": "该IP地址被禁止访问洛谷。有疑问请发送邮件至 shensu283@luogu.com.cn 联系管理员，并提供用户名、学校名字和IP地址。",
			"user_ban": "该账号被停用，请登出。有疑问请发送邮件至 shensu283@luogu.com.cn 联系管理员，并提供用户名、学校名字。管理员将在30日内处理。"
		},
		"contest": {
			"not_found": "比赛未找到",
			"permission_denied": "您无权查看该比赛",
			"already_signed": "您已经报名该比赛了",
			"invalid_join_code": "邀请码有误",
			"invitation_code_used": "邀请码已被使用",
			"not_ongoing": "比赛并未进行",
			"edit": {
				"no_edit_access": "您没有权限编辑该比赛",
				"need_pid": "需要选择题目",
				"can_not_add": "这道题目无法被添加至该比赛",
				"need_score": "需要指定分数",
				"need_visibility_type": "需要指定比赛类型",
				"not_qualified_for_public_contest": "您未达到提交公开赛的要求，不能提交比赛审核。公开赛要求请查看 https:\/\/www.luogu.com.cn\/discuss\/show\/174936",
				"can_not_change_public": "无法直接设置为已经审核的状态或者更改大类",
				"need_hoster": "需要指定举办者",
				"no_access_hoster": "您无权指定举办者为这个团队或者用户",
				"hoster_not_found": "举办者未找到",
				"invalid_time": "开始时间大于结束时间",
				"need_description": "需要指定描述",
				"need_name": "需要指定比赛标题",
				"need_method": "需要指定赛制",
				"need_startTime": "需要指定开始时间",
				"need_endTime": "需要指定结束时间",
				"had_added": "该题目已经加入比赛，如果需要调整顺序，请删除题目后重新添加",
				"had_not_added": "该题目并未加入比赛"
			}
		},
		"discuss": {
			"invalid_order_by": "不合法的排序参数"
		},
		"framework": {
			"request": {
				"not_json_request": "提交的请求不是合法的JSON数据",
				"query_invalid": "请求参数非法"
			},
			"serializer": {
				"unexpected_force_type": "错误的ForceType",
				"not_found": "Serializer未找到",
				"unexpected_criteria": "序列化规则不合法"
			}
		},
		"generic": {
			"frequency_limit": "请求频繁，请稍候再试",
			"session_expired": "操作超时，请重试",
			"invalid_referer": "不合法的来源，请重试",
			"invalid_oauth_scope": "非法的OAuth作用域",
			"access_denied": "拒绝访问",
			"not_found": "该页面未找到",
			"bad_request": "无效请求"
		},
		"identity_certify": {
			"invalid_national_id": "身份证号不合法",
			"user_exists": "已经有其他账号使用该身份证进行认证"
		},
		"message": {
			"permission_denied": "您无权操作该信息",
			"ban": "您已经被禁止使用私信功能。",
			"need_user": "需要指定用户",
			"need_id": "需要指定消息id",
			"not_found": "不存在该消息或者已被删除",
			"can_not_send_to_self": "不能给自己发送私信",
			"too_long": "发送的消息太长",
			"receiver_banned": "根据对方的设置，您不能向TA发送私信"
		},
		"oierdb": {
			"school_not_found": "未找到学校信息，请联系管理员进行认证",
			"no_prize_found": "未找到您的获奖记录，请确定姓名、学校是否填写正确。",
			"cannot_match": "根据您提供的信息，我们暂时无法为您认证奖项。请您在您的常用地重试，或拍照或扫描您的证书，发送至 shensu238@luogu.com.cn ，我们将人工为您处理。"
		},
		"paste": {
			"not_found": "剪贴板内容未找到",
			"permission_denied": "您无权查看该剪贴板"
		},
		"problem": {
			"not_found": "题目未找到",
			"permission_denied": "您无权查看该题目",
			"invalid_order": "不合法的排序方式",
			"invalid_order_by": "不合法的排序关键字",
			"invalid_type": "不合法的题目类型",
			"invalid_page": "不合法的页码",
			"uncreateable_type": "您无法创建这类题目",
			"solution_disabled": "该题目未启用题解功能",
			"edit": {
				"test_case_updaing": "测试点正在更新",
				"can_not_edit": "您没有编辑此题目的权限",
				"no_test_data": "请先上传测试数据",
				"unexpected_strategy": "不合法的积分策略",
				"need_scoring_script": "自定义计分需要计分脚本",
				"same_type": "无法迁移到相同的类型",
				"need_team_id": "需要提供团队ID",
				"unexpected_samples": "不合法的样例",
				"unexpected_file_type": "不合法的文件类型",
				"need_type": "需要指定创建的题目类型",
				"need_provider": "需要提供团队Id",
				"time_limit": "单个点时间限制不可大于5s，如有需要请联系管理员",
				"unexpected_time_limit": "不合法的时间限制",
				"memory_limit": "单个点空间不可大于512MB，如有需要请联系管理员",
				"unexpected_memory_limit": "不合法的空间限制",
				"unexpected_full_score": "不合法的单点分数",
				"too_many_subtask": "子任务数不可大于10个，如有需要请联系管理员",
				"total_time_limit": "总时限不可大于120s，如有需要请联系管理员"
			},
			"attachment": {
				"not_found": "附件未找到",
				"no_space_left": "题目附件已经没有剩余空间"
			},
			"task_list": {
				"problem_not_found": "该题目尚未收藏",
				"too_long": "您已收藏了过多的题目",
				"already_collected": "该题目已经被收藏"
			},
			"submit": {
				"can_not_submit": "您不能提交该题目",
				"frequency_limit_for_unverified_user": "提交过于频繁，请过10分钟再尝试，您可进行实名认证以提高提交限制次数",
				"frequency_limit": "提交过于频繁，请过3分钟再尝试",
				"long_time_problem_limit": "提交长时限题目超过您当日最大限制",
				"code_too_short": "这么短没问题？",
				"code_too_long": "代码过长"
			},
			"resolve": {
				"too_many_pids": "给定的PID太多"
			}
		},
		"rating": {
			"invalid_order_by": "错误的排序参数"
		},
		"record": {
			"not_found": "记录未找到",
			"need_problem": "需要指定题目",
			"need_problem_or_user": "需要制定题目或用户",
			"permission_denied": "您不能查看本条评测记录",
			"ongoing_contest_only": "仅允许查看正在进行或结束的比赛记录",
			"invalid_status": "不合法的记录状态",
			"invalid_language": "不合法的语言类型",
			"download": {
				"exceed_limit": "您已超出本日可下载数据最大次数"
			}
		},
		"team": {
			"not_found": "团队未找到",
			"no_admin_permission": "没有团队管理权限",
			"cannot_remove_master": "团队主不能够退出团队",
			"not_joined": "该用户未加入该团队",
			"exceeds_limit": "您已经创建、加入了过多团队",
			"name": {
				"duplicate_name": "有重名团队已经存在"
			},
			"join": {
				"length": "团队名长度应介于4到30字符",
				"needs_apply_message": "请填写验证信息",
				"already_joined": "您已加入该团队",
				"pending_review": "您已经申请过加入该团队，正在等待审核",
				"join_disallowed": "该团队不允许用户加入，请与团队管理员联系"
			}
		},
		"upload_image": {
			"not_found": "图片未找到",
			"permission_denied": "您无权编辑该图片，或者没有管理权限",
			"ban": "您尚未进行实名认证或者已经被禁止使用图床",
			"no_space_left": "您剩余储存空间不够上传该图片或者已经被禁止使用图床",
			"image_only": "仅可以上传图片",
			"frequency_limit": "24h内最多上传50张图片",
			"not_oss_callback": "非法的OSS回调请求",
			"need_id": "需要提供图片id",
			"need_user": "需要提供用户",
			"need_watermarkType": "需要提供水印类型",
			"need_size": "需要提供图片大小",
			"need_filename": "需要提供文件名",
			"invalid_type": "不合法的类型",
			"need_introduction": "个人简介不能为空"
		},
		"user": {
			"please_re_login": "请登出，并重新登录您的洛谷账号",
			"not_found": "用户未找到",
			"not_logged_in": "用户尚未登录",
			"not_verified": "您未通过实名认证",
			"not_admin": "您不是管理员",
			"special_account": "您的账号暂时无法登录",
			"cannot_follow": "根据对方用户的设置，您暂时无法关注此用户",
			"not_identity_certified": "用户尚未绑定身份证号",
			"same_status": "新的用户关系与原来相同",
			"need_setting": "需要提供用户设置",
			"slogan_too_long": "签名长度不能超过127字符",
			"open_source_limit": "由于在此加入代码公开计划未满30天，不能退出",
			"username": {
				"length": "用户名长度应介于4到20字节",
				"character": "用户名仅能使用英文字母、数字、下划线或中文",
				"numeric": "用户名不能为纯数字",
				"username_taken": "该用户名已被使用"
			},
			"password": {
				"length": "密码长度应介于6到20字节",
				"charset": "密码需要包含至少一个数字和一个字母"
			},
			"register": {
				"email_taken": "该邮箱已被使用",
				"phone_taken": "该手机已被使用"
			},
			"openid": {
				"already_exists": "您已绑定该平台账号"
			},
			"contact": {
				"already_bind": "您已经绑定了这种联系方式"
			}
		},
		"verify": {
			"invalid_captcha": "验证码错误",
			"wrong_verify_code": "邮箱或手机验证码不正确",
			"endpoint_format": "邮箱或手机格式不正确",
			"3minute_frequency_limit": "发送过于频繁，请稍候再试",
			"ip_frequency_limit": "当前IP超出当日发送限制，请明日再试",
			"endpoint_frequency_limit": "当前手机号超出当日发送限制，请明日再试",
			"user_already_exist": "使用该邮箱或手机的用户已存在",
			"user_not_exist": "使用该邮箱或手机的用户不存在",
			"2fa": {
				"had_set": "您已经设置了两步验证码",
				"unset": "您还未设置两部验证码",
				"incorrect_2fa_code": "错误的两步验证码"
			}
		},
		"vjudge": {
			"invalid_oj": "不合法的OJ",
			"email_name": "请使用您在OJ的用户名登录，不支持使用邮箱绑定账号",
			"login_fail": "登录失败（用户名或密码错误？）",
			"network_error": "与对方OJ通讯不畅，请稍后再试",
			"logout_and_retry": "请重新登陆后再次尝试",
			"unbind": "您尚未绑定该OJ账户"
		},
		"training": {
			"unexpected_type": "无权创建该类型的题单",
			"can_not_clone": "此题单无法再被转存",
			"can_not_view_scoreboard": "该题单无法查看积分榜",
			"has_joined": "已经收藏过题单",
			"not_joined": "尚未加入训练",
			"setting": {
				"title_too_long": "训练标题太长",
				"empty_title": "标题不可为空"
			}
		}
	},
	"recordLanguageTypes": {
		"1": {
			"id": 1,
			"name": "Pascal",
			"aceMode": "pascal"
		},
		"2": {
			"id": 2,
			"name": "C",
			"aceMode": "c_cpp"
		},
		"3": {
			"id": 3,
			"name": "C++",
			"aceMode": "c_cpp"
		},
		"4": {
			"id": 4,
			"name": "C++11",
			"aceMode": "c_cpp"
		},
		"11": {
			"id": 11,
			"name": "C++14",
			"aceMode": "c_cpp"
		},
		"12": {
			"id": 12,
			"name": "C++17",
			"aceMode": "c_cpp"
		},
		"5": {
			"id": 5,
			"name": "提交答案",
			"aceMode": "plain_text"
		},
		"6": {
			"id": 6,
			"name": "Python 2",
			"aceMode": "python"
		},
		"7": {
			"id": 7,
			"name": "Python 3",
			"aceMode": "python"
		},
		"8": {
			"id": 8,
			"name": "Java 8",
			"aceMode": "java"
		},
		"9": {
			"id": 9,
			"name": "Node v8.9",
			"aceMode": "javascript"
		},
		"10": {
			"id": 10,
			"name": "Shell",
			"aceMode": "sh"
		},
		"13": {
			"id": 13,
			"name": "Ruby",
			"aceMode": "ruby"
		},
		"14": {
			"id": 14,
			"name": "Go",
			"aceMode": "golang"
		},
		"15": {
			"id": 15,
			"name": "Rust",
			"aceMode": "rust"
		},
		"16": {
			"id": 16,
			"name": "PHP 7",
			"aceMode": "php"
		},
		"17": {
			"id": 17,
			"name": "C# Mono",
			"aceMode": "csharp"
		},
		"18": {
			"id": 18,
			"name": "Visual Basic Mono",
			"aceMode": "vbscript"
		},
		"19": {
			"id": 19,
			"name": "Haskell",
			"aceMode": "haskell"
		},
		"20": {
			"id": 20,
			"name": "Kotlin\/Native",
			"aceMode": "kotlin"
		},
		"21": {
			"id": 21,
			"name": "Kotlin\/JVM",
			"aceMode": "kotlin"
		},
		"22": {
			"id": 22,
			"name": "Scala",
			"aceMode": "scala"
		},
		"23": {
			"id": 23,
			"name": "Perl",
			"aceMode": "perl"
		},
		"24": {
			"id": 24,
			"name": "PyPy 2",
			"aceMode": "python"
		},
		"25": {
			"id": 25,
			"name": "PyPy 3",
			"aceMode": "python"
		},
		"26": {
			"id": 26,
			"name": "文言",
			"aceMode": "plain_text"
		}
	},
	"problemDifficulty": [{
		"id": 0,
		"name": "暂无评定",
		"color": "grey-3"
	}, {
		"id": 1,
		"name": "入门",
		"color": "pink-3"
	}, {
		"id": 2,
		"name": "普及-",
		"color": "orange-3"
	}, {
		"id": 3,
		"name": "普及\/提高-",
		"color": "gold-3"
	}, {
		"id": 4,
		"name": "普及+\/提高",
		"color": "green-3"
	}, {
		"id": 5,
		"name": "提高+\/省选-",
		"color": "blue-3"
	}, {
		"id": 6,
		"name": "省选\/NOI-",
		"color": "purple-3"
	}, {
		"id": 7,
		"name": "NOI\/NOI+\/CTSC",
		"color": "lapis-4"
	}],
	"senderEndpointTypes": {
		"1": {
			"id": 1,
			"type": "Email"
		},
		"2": {
			"id": 2,
			"type": "SMS"
		}
	},
	"contestAccessLevel": [{
		"id": 0,
		"name": "ViewDisallowed"
	}, {
		"id": 1,
		"name": "View"
	}, {
		"id": 2,
		"name": "Join"
	}, {
		"id": 3,
		"name": "ViewProblem"
	}, {
		"id": 4,
		"name": "ViewScoreBoard"
	}, {
		"id": 5,
		"name": "Management"
	}],
	"rankingSortTypes": [{
		"id": 0,
		"valueName": "rating",
		"name": "总分"
	}, {
		"id": 1,
		"valueName": "basicRating",
		"name": "基础"
	}, {
		"id": 2,
		"valueName": "socialRating",
		"name": "社区"
	}, {
		"id": 3,
		"valueName": "contestRating",
		"name": "比赛"
	}, {
		"id": 4,
		"valueName": "practiceRating",
		"name": "练习"
	}, {
		"id": 5,
		"valueName": "prizeRating",
		"name": "成就"
	}],
	"openIdPlatformTypes": {
		"1": "微信",
		"2": "GitHub"
	},
	"contestVisibilityTypes": [{
		"id": 0,
		"name": "封禁比赛",
		"color": "grey-5",
		"userCreatable": false,
		"scope": "disabled"
	}, {
		"id": 1,
		"name": "官方比赛",
		"color": "red-3",
		"userCreatable": false,
		"scope": "global"
	}, {
		"id": 2,
		"name": "团队公开赛",
		"color": "green-4",
		"userCreatable": false,
		"scope": "team"
	}, {
		"id": 3,
		"name": "团队内部赛",
		"color": "blue-3",
		"userCreatable": true,
		"scope": "team"
	}, {
		"id": 4,
		"name": "个人公开赛",
		"color": "blue-3",
		"userCreatable": false,
		"scope": "personal"
	}, {
		"id": 5,
		"name": "个人邀请赛",
		"color": "lapis-3",
		"userCreatable": true,
		"scope": "personal"
	}, {
		"id": 6,
		"name": "团队邀请赛",
		"color": "lapis-3",
		"userCreatable": true,
		"scope": "team"
	}, {
		"id": 7,
		"name": "团队公开赛 (待审核)",
		"color": "green-4",
		"userCreatable": true,
		"scope": "team"
	}, {
		"id": 8,
		"name": "个人公开赛 (待审核)",
		"color": "blue-3",
		"userCreatable": true,
		"scope": "personal"
	}],
	"problemTags": [{
		"group": "来源",
		"tags": [46, 48, 52, 57, 70, 77, 81, 82, 83, 84, 85, 99, 102, 331, 332, 333, 334, 335, 336]
	}, {
		"group": "时间",
		"tags": [14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 58, 59, 60, 61, 62]
	}, {
		"group": "地区",
		"tags": [38, 39, 40, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 328]
	}, {
		"group": "特殊题目",
		"tags": [103, 104, 106, 107, 108, 109, 319]
	}],
	"routes": {
		"blog_admin.article.list": "\/blogAdmin\/article\/list",
		"blog_admin.article.edit": "\/blogAdmin\/article\/edit\/{blogID}",
		"blog_admin.article.new": "\/blogAdmin\/article\/new",
		"blog_admin.article.comments": "\/blogAdmin\/article\/comments\/{blogID}",
		"blog_admin.article.post_edit": "\/blogAdmin\/article\/post_edit\/{blogID}",
		"blog_admin.article.post_new": "\/blogAdmin\/article\/post_new",
		"blog_admin.article.delete_comment": "\/blogAdmin\/article\/deleteComment\/{blogID}",
		"lfe_all_config": "\/_lfe\/config",
		"contest.list": "\/contest\/list",
		"contest.show": "\/contest\/{id}",
		"contest.edit": "\/contest\/edit\/{id}",
		"contest.new": "\/contest\/new",
		"paste.list": "\/paste",
		"paste.new": "\/paste\/new",
		"paste.edit": "\/paste\/edit\/{id}",
		"paste.delete": "\/paste\/delete\/{id}",
		"paste.show": "\/paste\/{id}",
		"user.show": "\/user\/{uid}",
		"user.notification": "\/user\/notification",
		"user.setting": "\/user\/setting",
		"user.bind_contact_endpoint": "\/user\/bindContactEndpoint",
		"user.two_factor_setup": "\/user\/twoFactorSetup",
		"problem.list": "\/problem\/list",
		"problem.show": "\/problem\/{pid}",
		"problem.edit": "\/problem\/edit\/{pid}",
		"problem.new": "\/problem\/new",
		"problem.solution": "\/problem\/solution\/{pid}",
		"theme.list": "\/theme\/list",
		"theme.setTheme": "\/theme\/setTheme\/{id}",
		"theme.design": "\/theme\/design\/{id}",
		"theme.edit": "\/theme\/edit\/{id}",
		"theme.delete": "\/theme\/delete\/{id}",
		"image.list": "\/image",
		"ranking.list": "\/ranking",
		"auth.login": "\/auth\/login",
		"auth.unlock": "\/auth\/unlock",
		"auth.forget_password": "\/auth\/forgetPassword",
		"auth.register": "\/auth\/register",
		"auth.openid_landing": "\/auth\/openidLanding",
		"app.ide": "\/ide",
		"training.list": "\/training\/list",
		"training.show": "\/training\/{id}",
		"training.edit": "\/training\/edit\/{id}",
		"training.new": "\/training\/new",
		"record.list": "\/record\/list",
		"record.show": "\/record\/{id}",
		"team.show": "\/team\/{id}",
		"team.setting": "\/team\/setting\/{id}",
		"team.create": "\/team\/create",
		"blog.jump_to_post": "\/blog\/_post\/{id}",
		"blog.list": "\/blog\/{identifier}\/",
		"blog.sitemap": "\/blog\/{identifier}\/_sitemap",
		"blog.show": "\/blog\/{identifier}\/{postIdentifier}",
		"chat.list": "\/chat",
		"api.contest.join": "\/fe\/api\/contest\/join\/{id}",
		"api.contest.scoreboard": "\/fe\/api\/contest\/scoreboard\/{id}",
		"api.contest.verify_problem": "\/fe\/api\/contest\/verifyProblem\/{id}",
		"api.contest.edit_problem": "\/fe\/api\/contest\/editProblem\/{id}",
		"api.contest.edit": "\/fe\/api\/contest\/edit\/{id}",
		"api.contest.freeze_scoreboard": "\/fe\/api\/contest\/freezeScoreboard\/{id}",
		"api.contest.new": "\/fe\/api\/contest\/new",
		"api.contest.delete": "\/fe\/api\/contest\/delete\/{id}",
		"api.contest.invitation_code": "\/fe\/api\/contest\/invitationCodeList\/{id}",
		"api.contest.generate_invitation_code": "\/fe\/api\/contest\/generateInvitationCode\/{id}",
		"api.user.clear_unread_notification": "\/fe\/api\/user\/clearUnreadNotification",
		"api.user.bind_contact_endpoint": "\/fe\/api\/user\/bindContactEndpoint",
		"api.user.two_factor_setup": "\/fe\/api\/user\/twoFactorSetup",
		"api.user.start_identity_certify": "\/fe\/api\/user\/startIdentityCertify",
		"api.user.finish_identity_certify": "\/fe\/api\/user\/finishIdentityCertify",
		"api.user.set_user_prize_show_level": "\/fe\/api\/user\/setUserPrizeShowLevel\/{id}",
		"api.user.set_ccf_level_show_level": "\/fe\/api\/user\/setCCFLevelShowLevel",
		"api.user.update_relation_ship": "\/fe\/api\/user\/updateRelationShip",
		"api.user.search": "\/fe\/api\/user\/search",
		"api.user.followings": "\/fe\/api\/user\/followings",
		"api.user.followers": "\/fe\/api\/user\/followers",
		"api.user.update_slogan": "\/fe\/api\/user\/updateSlogan",
		"api.user.joined_contest": "\/fe\/api\/user\/joinedContests",
		"api.user.created_posts": "\/fe\/api\/user\/createdPosts",
		"api.user.created_problems": "\/fe\/api\/user\/createdProblems",
		"api.user.created_contests": "\/fe\/api\/user\/createdContests",
		"api.user.marked_trainings": "\/fe\/api\/user\/markedTrainings",
		"api.user.created_trainings": "\/fe\/api\/user\/createdTrainings",
		"api.user.update_header_image": "\/fe\/api\/user\/updateHeaderImage",
		"api.user.update_setting": "\/fe\/api\/user\/updateSetting",
		"api.user.update_username": "\/fe\/api\/user\/updateUsername",
		"api.user.bind_vjudge_account": "\/fe\/api\/user\/bindVjudgeAccount",
		"api.user.unbind_vjudge_account": "\/fe\/api\/user\/unbindVjudgeAccount",
		"api.user.update_introduction": "\/fe\/api\/user\/updateIntroduction",
		"api.user.unbind_openid": "\/fe\/api\/user\/unbindOpenId\/{platform}",
		"api.openid.connect": "\/api\/openid\/connect\/{platform}",
		"api.problem.tasklist_add": "\/fe\/api\/problem\/tasklistAdd",
		"api.problem.tasklist_remove": "\/fe\/api\/problem\/tasklistRemove",
		"api.problem.submit": "\/fe\/api\/problem\/submit\/{pid}",
		"api.problem.resolve_pid": "\/fe\/api\/problem\/resolvePID",
		"api.problem.generate_attachment_upload_link": "\/fe\/api\/problem\/generateAttachmentUploadLink\/{pid}",
		"api.problem.download_attachment": "\/fe\/api\/problem\/downloadAttachment\/{id}",
		"api.problem.delete_attachment": "\/fe\/api\/problem\/deleteAttachment\/{id}",
		"api.problem.generate_data_upload_link": "\/fe\/api\/problem\/generateDataUploadLink\/{pid}",
		"api.problem.new": "\/fe\/api\/problem\/new",
		"api.problem.edit": "\/fe\/api\/problem\/edit\/{pid}",
		"api.problem.delete": "\/fe\/api\/problem\/delete\/{pid}",
		"api.problem.edit_test_case": "\/fe\/api\/problem\/editTestCase\/{pid}",
		"api.problem.transfer": "\/fe\/api\/problem\/transfer\/{pid}",
		"api.problem.clear_test_data_upload_status": "\/fe\/api\/problem\/clearTestDataUploadStatus\/{pid}",
		"api.image.detail": "\/api\/image\/detail\/{id}",
		"api.image.delete": "\/api\/image\/delete",
		"api.image.generate_upload_link": "\/api\/image\/generateUploadLink",
		"api.verify.captcha": "\/api\/verify\/captcha",
		"api.verify.send_verification_code": "\/api\/verify\/sendVerificationCode",
		"api.verify.send_two_factor_code": "\/api\/verify\/sendTwoFactorCode",
		"Luogu\\Controller\\API\\Report.submit": "\/api\/report\/{type}",
		"api.feed.list": "\/api\/feed\/list",
		"api.auth.user_pass_login": "\/api\/auth\/userPassLogin",
		"api.auth.sync_login": "\/api\/auth\/syncLogin",
		"api.auth.logout": "\/api\/auth\/logout",
		"api.auth.register": "\/api\/auth\/register",
		"api.auth.forget_password": "\/api\/auth\/forgetPassword",
		"api.auth.update_password": "\/api\/auth\/updatePassword",
		"api.auth.lock": "\/api\/auth\/lock",
		"api.auth.unlock": "\/api\/auth\/unlock",
		"api.training.mark": "\/api\/training\/mark\/{id}",
		"api.training.unmark": "\/api\/training\/unmark\/{id}",
		"api.training.scoreboard": "\/api\/training\/scoreboard",
		"api.training.edit": "\/api\/training\/edit\/{id}",
		"api.training.new": "\/api\/training\/new",
		"api.training.clone": "\/api\/training\/clone\/{id}",
		"api.training.transfer": "\/api\/training\/transfer\/{id}",
		"api.training.delete": "\/api\/training\/delete\/{id}",
		"api.training.problems": "\/api\/training\/problems\/{id}",
		"api.training.edit_problems": "\/api\/training\/editProblems\/{id}",
		"api.record.query_downloadable_testcase": "\/fe\/api\/record\/queryDownloadableTestcase\/{id}",
		"api.record.perform_download_testcase": "\/fe\/api\/record\/downloadTestcase\/{id}",
		"api.team.join": "\/api\/team\/join\/{id}",
		"api.team.create": "\/api\/team\/create",
		"api.team.delete": "\/api\/team\/delete\/{id}",
		"api.team.exit": "\/api\/team\/exit\/{id}",
		"api.team.kick": "\/api\/team\/kick\/{id}",
		"api.team.review": "\/api\/team\/review\/{id}",
		"api.team.edit_member": "\/api\/team\/editMember\/{id}",
		"api.team.set_master": "\/api\/team\/setMaster\/{id}",
		"api.team.members": "\/api\/team\/members\/{id}",
		"api.team.contests": "\/api\/team\/contests\/{id}",
		"api.team.trainings": "\/api\/team\/trainings\/{id}",
		"api.team.problems": "\/api\/team\/problems\/{id}",
		"api.team.edit": "\/api\/team\/edit\/{id}",
		"api.team.edit_notice": "\/api\/team\/editNotice\/{id}",
		"api.team.ban_user": "\/api\/team\/banUser\/{id}",
		"api.team.cancel_ban": "\/api\/team\/cancelBan\/{id}",
		"api.blog.list": "\/api\/blog\/lists",
		"api.blog.detail": "\/api\/blog\/detail\/{blogId}",
		"api.blog.vote": "\/api\/blog\/vote\/{blogId}",
		"api.blog.reply": "\/api\/blog\/reply\/{blogId}",
		"api.blog.replies": "\/api\/blog\/replies\/{blogId}",
		"api.blog.delete": "\/api\/blog\/delete\/{blogId}",
		"api.blog.user_blogs": "\/api\/blog\/userBlogs",
		"api.chat.new": "\/api\/chat\/new",
		"api.chat.delete": "\/api\/chat\/delete",
		"api.chat.record": "\/api\/chat\/record",
		"api.chat.clear_unread": "\/api\/chat\/clearUnread",
		"api.oierdb.cities": "\/api\/oierdb\/cities",
		"api.oierdb.schools": "\/api\/oierdb\/schools",
		"api.oierdb.match_prize": "\/api\/oierdb\/matchPrize",
		"backend.oss_callback.image_hosting": "\/backend\/oss\/image_hosting",
		"backend.oss_callback.problem_attachment": "\/backend\/ossproblem_attachment",
		"backend.oss_callback.problem_test_data": "\/backend\/oss\/problemTestData"
	},
	"userRelationshipTypes": [{
		"id": 0,
		"type": "Unrelated"
	}, {
		"id": 1,
		"type": "Following"
	}, {
		"id": 2,
		"type": "Blacklisted"
	}],
	"scoringStrategyTypes": {
		"0": {
			"id": 0,
			"type": "Sum",
			"name": "加和"
		},
		"1": {
			"id": 1,
			"type": "Min",
			"name": "最小值"
		},
		"2": {
			"id": 2,
			"type": "Max",
			"name": "最大值"
		},
		"100": {
			"id": 100,
			"type": "Custom",
			"name": "自定义"
		}
	},
	"problemTypes": {
		"P": {
			"id": "P",
			"type": "Public",
			"name": "主题库",
			"vjudge": false,
			"userCreatable": false,
			"searchable": true
		},
		"T": {
			"id": "T",
			"type": "Team",
			"name": "团队题库",
			"vjudge": false,
			"userCreatable": true,
			"searchable": false
		},
		"U": {
			"id": "U",
			"type": "User",
			"name": "个人题库",
			"vjudge": false,
			"userCreatable": true,
			"searchable": false
		},
		"CF": {
			"id": "CF",
			"type": "CodeForces",
			"name": "CodeForces",
			"vjudge": true,
			"userCreatable": false,
			"searchable": true
		},
		"SP": {
			"id": "SP",
			"type": "SPOJ",
			"name": "SPOJ",
			"vjudge": true,
			"userCreatable": false,
			"searchable": true
		},
		"AT": {
			"id": "AT",
			"type": "AtCoder",
			"name": "AtCoder",
			"vjudge": true,
			"userCreatable": false,
			"searchable": true
		},
		"UVA": {
			"id": "UVA",
			"type": "UVA",
			"name": "UVA",
			"vjudge": true,
			"userCreatable": false,
			"searchable": true
		}
	},
	"messageModeTypes": [{
		"id": 0,
		"type": "Admin",
		"name": "仅限管理员"
	}, {
		"id": 1,
		"type": "Following",
		"name": "关注的人与管理员"
	}, {
		"id": 2,
		"type": "Anyone",
		"name": "所有人(拉黑的用户除外)"
	}],
	"problemFlagTypes": {
		"0": {
			"id": 0,
			"type": "Hidden",
			"name": "隐藏"
		},
		"2": {
			"id": 2,
			"type": "TeamAccessEnabled",
			"name": "仅团队可见"
		},
		"5": {
			"id": 5,
			"type": "PublicAccessEnabled",
			"name": "公众可见"
		},
		"6": {
			"id": 6,
			"type": "ContestMode",
			"name": "比赛赛题"
		}
	},
	"contestInvitationCodeType": {
		"1": {
			"id": 1,
			"type": "FixedInvitationCode",
			"name": "固定邀请码"
		},
		"2": {
			"id": 2,
			"type": "GeneratedInvitationCode",
			"name": "生成验证码"
		}
	},
	"trainingTypes": {
		"0": {
			"id": 0,
			"type": "Hidden",
			"name": "隐藏题单",
			"public": false,
			"select": false,
			"scope": "hidden",
			"userCreatable": false,
			"color": "grey-5"
		},
		"1": {
			"id": 1,
			"type": "Official",
			"name": "官方题单",
			"public": true,
			"select": true,
			"scope": "global",
			"userCreatable": false,
			"color": "red-3"
		},
		"2": {
			"id": 2,
			"type": "TeamPrivate",
			"name": "团队私有",
			"public": false,
			"select": false,
			"scope": "team",
			"userCreatable": false,
			"color": "green-4"
		},
		"7": {
			"id": 7,
			"type": "TeamPublic",
			"name": "团队公开",
			"public": true,
			"select": false,
			"scope": "team",
			"userCreatable": true,
			"color": "green-4"
		},
		"3": {
			"id": 3,
			"type": "TeamSelect",
			"name": "团队精选",
			"public": true,
			"select": true,
			"scope": "team",
			"userCreatable": false,
			"color": "green-4"
		},
		"4": {
			"id": 4,
			"type": "TeamHomework",
			"name": "团队作业",
			"public": false,
			"select": false,
			"scope": "team",
			"userCreatable": false,
			"color": "green-4"
		},
		"5": {
			"id": 5,
			"type": "UserPrivate",
			"name": "个人私有",
			"public": false,
			"select": false,
			"scope": "user",
			"userCreatable": true,
			"color": "lapis-3"
		},
		"8": {
			"id": 8,
			"type": "UserPublic",
			"name": "个人公开",
			"public": true,
			"select": false,
			"scope": "user",
			"userCreatable": true,
			"color": "lapis-3"
		},
		"6": {
			"id": 6,
			"type": "UserSelect",
			"name": "个人精选",
			"public": true,
			"select": true,
			"scope": "user",
			"userCreatable": false,
			"color": "lapis-3"
		}
	},
	"teamTypes": [{
		"id": 0,
		"displayName": "已删除"
	}, {
		"id": 1,
		"displayName": "高级"
	}, {
		"id": 2,
		"displayName": "普通"
	}, {
		"id": 3,
		"displayName": "官方"
	}],
	"notificationTypes": {
		"1": {
			"id": 1,
			"type": "At",
			"name": "@我的"
		},
		"2": {
			"id": 2,
			"type": "Reply",
			"name": "回复"
		},
		"3": {
			"id": 3,
			"type": "Others",
			"name": "系统通知"
		}
	},
	"imageHostingWatermarkTypes": [{
		"id": 0,
		"name": "无水印"
	}, {
		"id": 1,
		"name": "Logo"
	}, {
		"id": 2,
		"name": "Logo@昵称"
	}],
	"teamMemberPermissionTypes": {
		"-1": {
			"id": -1,
			"type": "Banned",
			"name": "黑名单"
		},
		"-233": {
			"id": -233,
			"type": "NotJoined",
			"name": "未加入"
		},
		"0": {
			"id": 0,
			"type": "ReviewPending",
			"name": "审核中"
		},
		"1": {
			"id": 1,
			"type": "Member",
			"name": "成员"
		},
		"2": {
			"id": 2,
			"type": "Administrator",
			"name": "管理员"
		},
		"3": {
			"id": 3,
			"type": "Master",
			"name": "所有者"
		}
	},
	"teamJoinPermissionTypes": [{
		"id": 0,
		"type": "NoReview",
		"name": "加入无需审核"
	}, {
		"id": 1,
		"type": "RequireReview",
		"name": "加入需要审核"
	}, {
		"id": 2,
		"type": "Disallow",
		"name": "不允许加入"
	}],
	"userPrizeShowLevelType": [{
		"id": 0,
		"type": "Hidden",
		"name": "隐藏"
	}, {
		"id": 1,
		"type": "WithoutYearAndScore",
		"name": "不含年份和分数"
	}, {
		"id": 2,
		"type": "WithoutScore",
		"name": "不含分数"
	}, {
		"id": 3,
		"type": "ShowAll",
		"name": "展示"
	}]
}
 */
int main(){

    return 0;
}