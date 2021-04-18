let cq = 14

let form = document.forms[1]
let field_marks = form.elements["marks"]
let field_title = form.elements["question"]
let field_opt1 = form.elements["options[opt1]"]
let field_opt2 = form.elements["options[opt2]"]
let field_opt3 = form.elements["options[opt3]"]
let field_opt4 = form.elements["options[opt4]"]
let field_optionRadios = form.elements["input-choice"]
// field_difficultyRadios = form.elements["question_mode"]
let field_difficulty = {
    1: document.getElementById("easy"),
    2: document.getElementById("moderate"),
    3: document.getElementById("difficult"),
}

let field_moduleSelect = form.elements["module"]

let cur_question = all_questions[cq]

field_marks.value = cur_question.marks
field_title.value = cur_question.title
field_opt1.value = cur_question.options[0]
field_opt2.value = cur_question.options[1]
field_opt3.value = cur_question.options[2]
field_opt4.value = cur_question.options[3]
field_optionRadios[cur_question.correctOption - 1].checked = true
field_difficulty[cur_question.difficulty].checked = true
field_moduleSelect[cur_question.module - 1].selected = true



b = document.getElementsByClassName('btn-circle btn-blue')


