import random


def text_append(name, msg):

    file_path = "E:\\cppWork\\Assignments\\assignment3\\files\\"  # 新创建的txt文件的存放路径
    full_path = file_path + name + '.txt'  # 也可以创建一个.doc的word文档
    file = open(full_path, 'a')
    file.write(msg)
    file.close()


def gen_random(filename, length):
    msg = ""
    for i in range(length):
        if i % 10000 == 0:
            text_append(filename, msg + "\n")
            msg = ""
            print(i)
        down = 0
        up = 1
        random_num = random.uniform(down,up)
        min = 0
        max = 10000
        random_int = random.randint(min,max)
        random_num = random_num * random_int
        random_num = round(random_num,4)
        msg = msg + str(random_num) + " "
    return msg


size = 300 * 1000 * 1000

gen_random("v1", size)
gen_random("v2", size)
