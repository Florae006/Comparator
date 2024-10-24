import os
import random
import numpy as np

def generate_sample_data(num_samples, input_range, data_dir):
    if not os.path.exists(data_dir):
        os.makedirs(data_dir)

    for i in range(1, num_samples + 1):
        input_filename = os.path.join(data_dir, f"{i}.in")
        output_filename = os.path.join(data_dir, f"{i}.out")

        input_data = ""
        output_data = ""

        if i < 10:
            n = random.randint(1, 20)
            m = random.randint(1, 20)
        elif i < 30:
            n = random.randint(1, 100)
            m = random.randint(1, 100)
        else:
            n = random.randint(*input_range)
            m = random.randint(*input_range)
        
        input_data += f"{n} {m}\n"

        cntk = 0
        cntd = 0
        for x in range(n):
            for y in range(m):
                r = random.randint(0, 3)
                if r == 0:
                    input_data += '#'
                elif r == 1:
                    input_data += 'K'
                    cntk += 1
                else :
                    input_data += 'D'
                    cntd += 1
            input_data += '\n'
        
        if cntk == cntd:
            output_data = "Draw"
        elif cntk > cntd:
            output_data = "Kokomi"
        else:
            output_data = "Dodola"

        # 写入输入文件
        with open(input_filename, 'w') as infile:
            infile.write(f"{input_data}")
        
        # 写入输出文件
        with open(output_filename, 'w') as outfile:
            outfile.write(f"{output_data}")

if __name__ == "__main__":
    generate_sample_data(num_samples=50, input_range=(1, 1000), data_dir="data")