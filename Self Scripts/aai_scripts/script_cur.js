document.getElementsByClassName('btn-circle btn-blue')[0].click()
all_questions = {"88": {"number": 88, "title": "-------------------- includes: Identifying and analyzing one's emotions, and how they affect others.", "module": 4, "marks": 1.5, "difficulty": 2, "options": ["Self-awareness", "Self-management", "Other-awareness", "Other-management"], "correctOption": 1}, "89": {"number": 89, "title": "Four different aspects to ------------------- are \u2013 Self-awareness, Self-management, Other-awareness, Other-management.", "module": 4, "marks": 1.5, "difficulty": 2, "options": ["Online Leadership", "Self Leadership", "Team Leadership", "Mentoring"], "correctOption": 2}, "90": {"number": 90, "title": "-------------------- involves enhancing the relationships among organizational members in a context in which work is mediated by technology.", "module": 4, "marks": 1.5, "difficulty": 1, "options": ["Online Leadership", "Self Leadership", "Team Leadership", "Mentoring"], "correctOption": 1}, "91": {"number": 91, "title": "At the ------------------- stage of the Team Development, team members will feel more comfortable ask for help and offer constructive feedback. They'll share a stronger commitment to the team's goals, and they would make good progress toward it.", "module": 4, "marks": 1.5, "difficulty": 2, "options": ["Forming, ", "Storming, ", "Norming, ", "Performing"], "correctOption": 3}, "92": {"number": 92, "title": "------------------ is an example of authoritarian leadership style.", "module": 4, "marks": 1.5, "difficulty": 2, "options": ["Ratan Tata ", "Mark Zuckerberg ", "Dhirubhai Ambani ", "Donald Trump"], "correctOption": 4}, "93": {"number": 93, "title": "Characteristics of creative leaders are ----------------------.", "module": 4, "marks": 1.5, "difficulty": 3, "options": ["Autocratic, Democratic, Free Reign", "Continuity, Flexibility, Originality", "Imagination, Observation, Creation ", "Explorative, Independent, Contrarian thinking"], "correctOption": 4}, "94": {"number": 94, "title": "Outcome from a -------------- agreement is specific and measurable, showing signs of improvement or positive change in the desired performance area.", "module": 4, "marks": 1.5, "difficulty": 3, "options": ["mentoring", "coaching", "resource provider", "motivating"], "correctOption": 2}, "95": {"number": 95, "title": "At the ------------------- stage of the Team Development , individuals are unsure of the team's purpose, how they fit in, and whether they'll work well with one another. ", "module": 4, "marks": 1.5, "difficulty": 1, "options": ["Forming ", "Storming", "Norming", "Performing"], "correctOption": 1}, "96": {"number": 96, "title": "------------------------ is the final stage of the creative process. ", "module": 4, "marks": 1.5, "difficulty": 1, "options": ["Incubation stage", "Illumination stage", "Evaluation stage", "Verification stage"], "correctOption": 4}, "97": {"number": 97, "title": "-------------------- involves two processes: thinking, then producing.", "module": 4, "marks": 1.5, "difficulty": 3, "options": ["Planning", "Leadership", "Brainstorming", "Creativity"], "correctOption": 4}, "98": {"number": 98, "title": "--------------------- is a leader who has made his mark in technology.", "module": 4, "marks": 1.5, "difficulty": 1, "options": ["Ratan Tata ", "Mark Zuckerberg ", "Dhirubhai Ambani ", "Donald Trump"], "correctOption": 2}, "99": {"number": 99, "title": "-------------------- skills means recognising, responding, and managing changes to your vision and plans.", "module": 4, "marks": 1.5, "difficulty": 1, "options": ["change management ", "people management ", "strategic management ", "communication management"], "correctOption": 1}, "100": {"number": 100, "title": "Key skills of creativity are ------------------------.", "module": 4, "marks": 1.5, "difficulty": 3, "options": ["Autocratic, Democratic, Free Reign", "Continuity, Flexibility, Originality", "Imagination, Observation, Creation ", "Explorative, Independent, Contrarian thinking"], "correctOption": 3}}
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
form.submit()