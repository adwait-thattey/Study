def solution(x):
    # Your code here
    start_char = 'a'
    end_char = 'z'
    ord_sum = ord(start_char) + ord(end_char)
    solved_list = [chr(ord_sum - ord(i)) for i in x if start_char <= i <= end_char]
    return "".join(solved_list)
