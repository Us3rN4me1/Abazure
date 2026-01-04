#include <stdio.h>
#include <string.h>

// Глобални променливи, константи и функции
	// Константи за отговор от потребител + функция проверяваща дали е въвел да или не
		#define POS_RESP "Yes"
		#define POS_RESP_LC "yes"
		#define NEG_RESP "No"
		#define NEG_RESP_LC "no"

		int asnw_check (char conf_arr[]) {
				while (strcmp(conf_arr, POS_RESP) != 0 &&
		       		   strcmp(conf_arr, POS_RESP_LC) != 0 &&
		           	   strcmp(conf_arr, NEG_RESP) != 0 &&
		               strcmp(conf_arr, NEG_RESP_LC) != 0) {
				    printf("\nPlease enter a valide answer from the question above!\n");
				    scanf("%99s", conf_arr);
				}

			return 0;
		}

	// Цикъл за изсчистване на stdin ако се въведът повече от 2 неща наведнъж
	// също попречва на появата на грешки, ако се въведе друго освен int, когато това се изисква
	int clear_rest (void) {
		int clear;

		while ((clear = getchar()) != '\n' && clear != EOF);

		return 0;
	}
	
	//Профил на анализиращ се ученик
	 typedef struct {
	 	// Лична информация
	 	char prof_name[101];
	 	char prof_l_name[101];
	 	int prof_class;
	 	int prof_repeat;
	 	int prof_age;
	 	int prof_term;

	 	//Информация за оценки по предмет
	 	float prof_eng;
	 	float prof_f_lang;
	 	float prof_math;
	 	float prof_phs;
	 	float prof_bio;
	 	float prof_chem;
	 	float prof_hist;
	 	float prof_geo;
	 	float prof_mus;
	 	float prof_pe;

	 	// Финален анализ
	 	char prof_term_ana[600];
	 	char prof_lowest_grade_ana[1000];
	 	char prof_highest_grade_ana[1000];
	 } Profile;

	//Създаваме нов ученик
	Profile a;

	// Декларираме pointer за файл
	FILE *fptr;

// За по-добра четимост на кода, другите етапи се декларират преди main(), а се изпълняват след него
// по последователен ред

	// Втори етап декларация - Създаване на профил на ученика
	int profile_creation (void);

	// Трети етап декларация - вземане на данни за срока
	// (по американски стил => оценките се пишат в % от 0 до 100)
	int term_info (void);

	// Четвърти етап - калкулация на срочна оценка и ананализ
	int final (void);

	// Пети етап - запазване на информацията
	int save (void);



// Първи етап - Начална страница на програмата
int main (void) {
	// Заглавие на програмата чрез ASCII art и мото
	printf("\n-----------------------------------------------------------\n"
		"\n    ___    ____  ___ _____   __  ______  ______\n"
			     "   /   |  / __ )/   /__  /  / / / / __ \\/ ____/\n"
			    "  / /| | / __  / /| | / /  / / / / /_/ / __/   \n"
			   " / ___ |/ /_/ / ___ |/ /__/ /_/ / _, _/ /___   \n"
			  "/_/  |_/_____/_/  |_/____/\\____/_/ |_/_____/  \n "
                                               "\n"
                                               "-----------------------------------------------------------\n");
	printf("\n\nAnalysis is the key to progress!\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// Записваме отговора на потребителя
	char confirm[10];

	// Описание на програмата към потребител	
	printf("\n\nHello and welcome to \"Abazure\" - a program for calculating and analysing primary, middle and\n"
		   "high school students\' performace during a term.\n");
	printf("\nYou will now be prompted to give information about the student whom you wish to analyse.\n");
	printf("\nWould you like to begin? [Yes/No]\n");
	scanf("%99s", confirm);
	clear_rest ();

	// Проверка дали отговора е приемлив чрез сравнение
	asnw_check (confirm);

	// Прекратяване на изпълнение при отказ за продължение или
	// продължение към втори етап
	if (strcmp(confirm, NEG_RESP) == 0 || strcmp(confirm, NEG_RESP_LC) == 0) {
		printf("\nThe program will now end. Have a nice day!\n");
	} else if (strcmp(confirm, POS_RESP) == 0 || strcmp(confirm, POS_RESP_LC) == 0) {
		profile_creation();
	}

	return 0;
}



//Втори етап изпълнение
int profile_creation (void) {
	// Създаваме arrays и променливи където да съхраним резултатите,
	// за да бъдат проверени и евнтуално редактирани, преди окончателно да се запишат в профила
	char fn[100];
	char ln[100];
	int class_num;
	int repeat;
	int age;
	int term;
	
	char confirm_rep[100];
	char confirm_end[100];

	// Начало на втори етап
	printf("\n\nCreating student profile...\n");
	printf("\nPlease provide the following data in order to create the student\'s profile:\n");
	
	// Вземаме първо име
	printf("\nFirst Name: ");
	scanf("%99s", fn);
	clear_rest ();
	strcpy(a.prof_name, fn);
	 

	// Вземаме второ име
	printf("Last Name: ");
	scanf("%99s", ln);
	clear_rest ();
	strcpy(a.prof_l_name, ln);


	// Вземане на номер на класа
	printf("Class: ");
	scanf("%d", &class_num);
	clear_rest ();

	// Проверка дали класът е валидно число
	while (class_num < 1 || class_num > 12) {
		printf("ERROR: Please enter a number between 1 and 12!\n");
		scanf("%d", &class_num);
		clear_rest ();
	}

	a.prof_class = class_num;

	
	// Проверка дали повтаря класа
	printf("Is this the student\'s first time in this class? [Yes/No]\n");
	scanf("%99s", confirm_rep);
	clear_rest ();

	// Проверка за допустими стойности за отговор
	asnw_check(confirm_rep);

	if (strcmp(confirm_rep, NEG_RESP) == 0 || strcmp(confirm_rep, NEG_RESP_LC) == 0) {
			printf("For what time does the student repeat the class? [Write the number of times]\n");
			scanf("%d", &repeat);
			clear_rest ();
			while (repeat > 2 || repeat < 1) {
				printf("ERROR: Value must be between 1 and 2!\n"); //Под 1 не повтаря, над 2 е изключен
				scanf("%d", &repeat);
				clear_rest ();
			}

			a.prof_repeat = repeat;
	} else if (strcmp(confirm_rep, POS_RESP) == 0 || strcmp(confirm_rep, POS_RESP_LC) == 0) {
			repeat = 0;
			a.prof_repeat = repeat;
		}

	// Вземане на години

	// Проверка дали ученикът може да е на зададените години, спрямо класа му и дали повтаря
	// Задаваме базови променливи
	int base_age = a.prof_class + 6;
	int expected_age = base_age + a.prof_repeat;
	int min_age = a.prof_class + 5;   // за тези, които са започнали по-рано
	int max_age = a.prof_class + 9;   // позволява за повтаряне до 2 + малък толерансе

	printf("Age: ");
	while (scanf("%d", &age) != 1) {
	    clear_rest();
	    printf("ERROR: Please enter a valid number for age!\n");
	}
	clear_rest();

	// примеа години в  [min_age, max_age] но предпочита години ±1 от expected_age
	while (age < min_age || age > max_age || (age < expected_age - 1) || (age > expected_age + 1)) {
	    printf("ERROR: The student can not be %d year/s old!\n", age);
	    scanf("%d", &age);
	    clear_rest();
	}

	a.prof_age = age;

	// Вземане на номер на срок от учебната година
	printf("Term number: ");
	scanf("%d", &term);
	clear_rest ();

	// Проверка дали е въведен правилно номера на срока
	while (term < 1 || term > 2) {
		printf("ERROR: Please enter the correct NUMBER of the term! (First or Second => 1 or 2)\n");
		scanf("%d", &term);
		clear_rest ();
	}

	a.prof_term = term;

	// Потвърждение за правилно въведена информация
	printf("\n\nYou are about to create a student profile with the following characteristics:\n");
	printf("\n\nName: %s %s, Class: %d, Age: %d, Term: %d, Class Repeats: %d.\n\n", a.prof_name, a.prof_l_name, 
		   a.prof_class,a.prof_age, a.prof_term, a.prof_repeat);
	printf("\nIs all of the above information correct? [Yes/No]\n");
	scanf("%99s", confirm_end);
	clear_rest ();

	// Проверка за допустими стойности за отговор
	asnw_check(confirm_end);


	// Ако потребител зададе, че е намерил грешка в дадената инфо, f() ще се повтори
	// При потрърждение на достоверността на данните, се преминава към трети етап
	if (strcmp(confirm_end, NEG_RESP) == 0 || strcmp(confirm_end, NEG_RESP_LC) == 0) {
			profile_creation();
		} else if (strcmp(confirm_end, POS_RESP) == 0 || strcmp(confirm_end, POS_RESP_LC) == 0) {
			printf("\n\n\nProfile has been succecfully created!\n");
			term_info();
		}

	return 0;
}



//Проверка дали са въведение правилно оценките в Трети етап
float percent_check (float subject) {
	while (subject < 0.0f || subject > 100.0f) {
		printf("ERROR: Grade must be a value between 0 and 100 percent!\n");
		scanf("%f", &subject);
		clear_rest();
	}
	return subject;
}

//Трети етап изпълнение 
int term_info (void) {
	// Създаваме променливи където да съхраним резултатите,
	// за да бъдат проверени и евнтуално редактирани, преди окончателно да се запишат в профила
		float eng;
	 	float lang;
	 	float math;
	 	float phs;
	 	float bio;
	 	float chem;
	 	float hist;
	 	float geo;
	 	float mus;
	 	float pe;

	 	char confirm[100];

	// Начало на 3ти етап
	printf("\n\n\nPlease provide the grades to the following classes during the selected "
		   "term in order for the analyzation to begin.\n");

	// Оценка от основен (английски) език
	printf("\nEnglish: ");
	scanf("%f", &eng);
	clear_rest();
	eng = percent_check(eng);

	a.prof_eng = eng;

	// Оценка по чужд език
	printf("Foreign Language: ");
	scanf("%f", &lang);
	clear_rest();
	lang = percent_check(lang);

	a.prof_f_lang = lang;

	// Оценка по Математика
	printf("Math: ");
	scanf("%f", &math);
	clear_rest();
	math = percent_check(math);

	a.prof_math = math;

	// Оценка по Физика
	printf("Physics: ");
	scanf("%f", &phs);
	clear_rest();
	phs = percent_check(phs);

	a.prof_phs = phs;

	// Оценка по Биология
	printf("Biology: ");
	scanf("%f", &bio);
	clear_rest();
	bio = percent_check(bio);

	a.prof_bio = bio;

	// Оценка Химия
	printf("Chemistry: ");
	scanf("%f", &chem);
	clear_rest();
	chem = percent_check(chem);

	a.prof_chem = chem;

	// Оценка по История
	printf("History: ");
	scanf("%f", &hist);
	clear_rest();
	hist = percent_check(hist);

	a.prof_hist = hist;

	// Оценка по География
	printf("Geography: ");
	scanf("%f", &geo);
	clear_rest();
	geo = percent_check(geo);

	a.prof_geo = geo;

	// Оценка по Музика
	printf("Music: ");
	scanf("%f", &mus);
	clear_rest();
	mus = percent_check(mus);

	a.prof_mus = mus;

	// Оценка ФВС
	printf("PE: ");
	scanf("%f", &pe);
	clear_rest();
	pe = percent_check(pe);

	a.prof_pe = pe;



	// Проверка за валидност на данните
	printf("\nYou are about to add to %s %s\'s profile the following grades:\n",a.prof_name, a.prof_l_name );

	printf("\nEnglish: %3.2f%%\nForeign language: %3.2f%%\nMath: %3.2f%%\nPhysics: %3.2f%%\nBiology: %3.2f%%\n"
		   "Chemistry: %3.2f%%\nHistory: %3.2f%%\nGeography: %3.2f%%\nMusic: %3.2f%%\nPE: %3.2f%%\n", a.prof_eng, a.prof_f_lang, 
		   a.prof_math,a.prof_phs, a.prof_bio, a.prof_chem, a.prof_hist, a.prof_geo, 
		   a.prof_mus, a.prof_pe);

	printf("\nIs all of the above information correct? [Yes/No]\n");
	scanf("%99s", confirm);
	clear_rest();
	asnw_check(confirm);

	if (strcmp(confirm, NEG_RESP) == 0 || strcmp(confirm, NEG_RESP_LC) == 0) {
			term_info();
		} else if (strcmp(confirm, POS_RESP) == 0 || strcmp(confirm, POS_RESP_LC) == 0) {
			printf("\n\nSuccecfully added the grades to the profile!\n");
			final();
		}

	return 0;
}



// Четвърти етап изпълнение
int final (void) {
	char confirm[100];

	// Изчисляваме средно аритметично
	float calc = (a.prof_eng + a.prof_f_lang + a.prof_math + a.prof_phs + a.prof_bio 
				  + a.prof_chem + a.prof_hist + a.prof_geo +  a.prof_mus + a.prof_pe)/10;

	// Създаваме два arrays, съхраняваме оценките и имената
	// за да можем да пресметнем най-малката/голямата оценка и да посочим на кой предмет принадлежи тя
	float grades[10] = {
        a.prof_eng, a.prof_f_lang, a.prof_math, a.prof_phs, a.prof_bio,
        a.prof_chem, a.prof_hist, a.prof_geo, a.prof_mus, a.prof_pe
    };

    const char names[10] [20]= {
        "English", "Foreign language", "Math", "Physics", "Biology",
        "Chemistry", "History", "Geography", "Music", "PE"
    };


	// Намираме най-малка и най-голяма стойност чрез цикъл, който обикаля и
	// срявнява всичко с всичко в grades[]
    int min_idx = 0; 
    int max_idx = 0;

    for (int i = 1; i < 10; ++i) {
        if (grades[i] < grades[min_idx]) min_idx = i;
        if (grades[i] > grades[max_idx]) max_idx = i;
    }



	printf("\n\n\n%s %s\'s analysis is ready!\n\n", a.prof_name, a.prof_l_name);

	// Анализ на срочна оценка
	if (calc<60.0f) {
		snprintf(a.prof_term_ana, sizeof a.prof_term_ana, 
			"\nTerm score: %3.2f%%\nTerm grade: F\n"
			"\n%s\'s performance is critically low. Focus on rebuilding confidence and reteaching fundamentals.\n"
			" Identify specific gaps from their term work, provide short, targeted mini-lessons,"
			" and use frequent\nlow-stakes quizzes to monitor progress. Pair the student with a supportive"
			" peer tutor or small group,\nset clear weekly goals, and celebrate small wins to sustain motivation."
			" In the meantime, they must immidetly\nschedule dates for remedial exams or they will have to "
			"repeat the term!\n", calc, a.prof_name);
		printf("%s", a.prof_term_ana);

	} else if (calc<70.0f) {
		snprintf(a.prof_term_ana, sizeof a.prof_term_ana, 
			"\nTerm score: %3.2f%%\n\nTerm grade: D\n"
			"\n%s\'s performance needs a lot of attention and work. Give focused practice on weak "
			"areas,\nwhile reinforcing strengths: assign scaffolded exercises that gradually\nincrease in difficulty "
			"and provide specific feedback. Use formative assessments to adjust instruction,\n"
			"offer one-on-one check-ins, and set achievable targets for the next term.\n", calc, a.prof_name);
		printf("%s", a.prof_term_ana);

	} else if (calc<80.0f) {
		snprintf(a.prof_term_ana, sizeof a.prof_term_ana, 
			"\nTerm score: %3.2f%%\n\nTerm grade: C\n"
			"\n%s\'s performance is could me improved upon. Strengthen consistency and bridge gaps by giving\n"
			"increasingly complex application tasks. Schedule brief retrieval practice\nfor key concepts and"
			"use mixed-problem sets in order to give relevant feedback.\nTeach them more effective study methods"
			" (spaced practice, self-testing, summarizing) and set clear,\nshort-term benchmarks"
			" during the next term to track the steady improvement.\n", calc, a.prof_name);
		printf("%s", a.prof_term_ana);

	} else if (calc<94.0f) {
		snprintf(a.prof_term_ana, sizeof a.prof_term_ana, 
			"\nTerm score: %3.2f%%\n\nTerm grade: B\n"
			"\n%s\'s performance is up to standart. Push for deeper understanding and consistency:"
			" assign extension tasksthat require reasoning\n and connections,include frequent"
			" analytical questions in class, and give feedback aimed at\nrefining skills."
			" Encourage the use of strategies like planning, monitoring and reflecting\n"
			"and try to convert near-misses into top-level work.\n", calc, a.prof_name);
		printf("%s", a.prof_term_ana);

	} else if (calc<=100.0f) {
		snprintf(a.prof_term_ana, sizeof a.prof_term_ana, 
			"\nTerm score: %3.2f%%\n\nTerm grade: A\n"
			"\n%s has a top-level performace. Challenge and sustain excellence with "
			"enrichment and leadership opportunities:\noffer open-ended projects, deeper research tasks,"
			" or chances to mentor peers. Your feedback\nshould be focused on sophistication and polish."
			"Maintain high expectations, encourage reflection on learning processes\nand plan"
			" stretch goals for the next term to keep growth upward.\n", calc, a.prof_name);
		printf("%s", a.prof_term_ana);
	}

	// Анализ на най-ниска оценка
	switch (min_idx) {
		case 0:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: English - %3.2f%%\n\n"
				"Diagnose whether issues are vocabulary, comprehension, writing mechanics, or oral expression\n"
				"and target the weakest skill with short practices. Pair the student with a peer reader or\n"
				"use guided one-on-one conferences to model strategies and track progress weekly.\n", grades[0]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 1:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Foreign Language - %3.2f%%\n\n"
				"Identify whether listening, speaking, reading, or grammar is weakest and create daily micro-tasks\n"
				"(vocabulary flashcards, 5-minute listening clips, short speaking prompts) to build automaticity.\n"
				"Incorporate culturally engaging media to boost interest and context retention.\n", grades[1]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 2:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Math - %3.2f%%\n\n"
				"Pinpoint conceptual gaps (number sense, algebra, geometry) and use short,\n"
				"practice sets focusing on one concept at a time with immediate feedback.\n"
				"Teach problem-solving frameworks (read, plan, solve, check).\n"
				"Provide targeted interventions and regular small wins to rebuild confidence.\n", grades[2]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 3:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Physics - %3.2f%%\n\n"
				"Focus on core misconceptions in concepts and mathematical application.\n"
				"use hands-on demonstrations and guided problem sets that connect equations to\n"
				"physical intuition. Break problems into steps and provide frequent low-stakes practice\n"
				"with timely corrections. Use peer instruction and lab work to make abstract ideas concrete.\n"
				, grades[3]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 4:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Biology - %3.2f%%\n\n"
				"Identify whether systems understanding or experimental reasoning is weak\n"
				"and use concept maps plus short retrieval practices to build links.\n"
				"Incorporate visuals, lab activities, and real-life examples to promote understanding.\n"
				"Offer guided review sessions focusing on the most error-prone issues.\n", grades[4]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 5:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Chemistry - %3.2f%%\n\n"
				"Target problems in chemical equations and conceptual model.\n"
				"Use worked examples, small-group problem-solving, and routine formative checks.\n"
				"Make sure to reinforce laboratory connections to theory.\nBreak complex calculations into small steps.\n"
				, grades[5]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 6:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: History - %3.2f%%\n\n"
				"Determine whether source analysis, chronology, or content recall is weakest and\n use timeline-building, "
				"primary-source close reading, and short essays to improve skills.\n Use retrieval practice for key dates and concepts. "
				"Add discussion-based activities\n to boost reasoning and retention.\n", grades[6]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 7:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Geography - %3.2f%%\n\n"
				"Address gaps in spatial thinking, map skills, or human-environment\n"
				"concepts with hands-on map exercises, spatial vocabulary practice\n and case-study analyses."
				"Use interactive tools and tasks linking local examples\n to global patterns."
				"Provide regular tasks that build map literacy and conceptual connections.\n", grades[7]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 8:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: Music - %3.2f%%\n\n"
				"Identify technical, theoretical, or performance anxieties and assign\n"
				"short technical drills and listening tasks. Pair practice goals with measurable milestones\n"
				"(tempo, accuracy, expression) or simple theory knowledge cheks.\n", grades[8]);
			printf("%s", a.prof_lowest_grade_ana);
		break;

		case 9:
			snprintf(a.prof_lowest_grade_ana, sizeof a.prof_lowest_grade_ana, 
				"\nLowest grade: PE - %3.2f%%\n\n"
				"Determine if motor skills, fitness, or motivation are limiting and create short,\n"
				"achievable daily practices targeting specific skills or conditioning\n (e.g., agility drills, cardiovascular intervals). "
				"Use positive reinforcement, track small measurable improvements\n and set realistic benchmarks to boost confidence.\n"
				, grades[9]);
			printf("%s", a.prof_lowest_grade_ana);
		break;
	}

	// Анализ на най-висока оценка
	switch (max_idx) {
		case 0:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: English - %3.2f%%\n\n"
				"Maintain strengths by assigning varied, higher-order tasks (analytical essays, creative projects)\n"
				"that deepen critical thinking and expression. Provide feedback on nuance and organization and encourage\n"
				"self-reflection on writing processe\n", grades[0]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 1:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Foreign Language - %3.2f%%\n\n"
				"Keep momentum by increasing authentic exposure (podcasts, news, novels) and adding communicative\n"
				"challenges like presentations or debates. Offer targeted feedback on fluency and accuracy.\n"
				, grades[1]);
			printf("%s", a.prof_highest_grade_ana);			
		break;
			
		case 2:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Math - %3.2f%%\n\n"
				"Extend mastery through complex, multi-step problems and real-world application and\n"
				"encourage mathematical reasoning tasks.\n", grades[2]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 3:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Physics - %3.2f%%\n\n"
				"Deepen expertise with open-ended experiments and modeling tasks that link theory to phenomena.\n"
				"Encourage independent projects to develop precision and insight.\n", grades[3]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 4:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Biology - %3.2f%%\n\n"
				"Maintain excellence by assigning inquiry-based projects, advanced readings, or lab investigations.\n"
				"Ask for feedback aimed at scientific reasoning.\n", grades[4]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 5:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Chemistry - %3.2f%%\n\n"
				"Promote deeper understanding through mechanism analysis\n"
				"Advanced lab techniques, and research-style problem sets. Offer extension tasks,\n"
				"or advanced courses to preserve engagement.\n", grades[5]
				);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 6:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: History - %3.2f%%\n\n"
				"Sustain achievement by assigning comparative analyses andindependent\n"
				"research projects that deepen interpretation skills.\n"
				"Encourage presentation of findings and peer teaching.\n", grades[6]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 7:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\nHighest grade: Geography - %3.2f%%\n\n"
				"Keep strength by offering thematic projects, data-analysis tasks, and fieldwork\n"
				"or virtual mapping assignments. Encourage synthesis across scales and critique of sources.\n"
				, grades[7]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 8:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: Music - %3.2f%%\n\n"
				"Nurture excellence with a more challenging repertoire or essay-style tasks\n"
				"regarding a topic of their interest in the musical sphere. "
				"Set higher standarts encourage masterclass participation.\n", grades[8]);
			printf("%s", a.prof_highest_grade_ana);			
		break;

		case 9:
			snprintf(a.prof_highest_grade_ana, sizeof a.prof_highest_grade_ana, 
				"\n\nHighest grade: PE - %3.2f%%\n\n"
				"Sustain top performance by varying training with sport-specific drills,\n"
				"periodized conditioning, and recovery strategies (nutrition, sleep, mobility).\n"
				"Offer leadership roles in team settings and introduce advanced techniques.\n", grades[9]);
			printf("%s", a.prof_highest_grade_ana);			
		break;
	}

	// Запитване за запазване на профил
	printf("\n\nWould you like to save %s\'s profile and their analysis? [Yes/No]\n", a.prof_name);
	scanf("%99s", confirm);
	clear_rest();
	asnw_check(confirm);

	if (strcmp(confirm, NEG_RESP) == 0 || strcmp(confirm, NEG_RESP_LC) == 0) {
		// Запитваме дали са сигурни в избора си
			char doub_confirm[100];

			printf("\nAre you sure? This profile and it\'s analysis will be PERMENETLY deleted! [Yes/No]\n");
			scanf("%99s", doub_confirm);
			clear_rest();
			asnw_check(doub_confirm);

			if (strcmp(doub_confirm, NEG_RESP) == 0 || strcmp(doub_confirm, NEG_RESP_LC) == 0) {	
				printf("\nProfile has been saved! Thank you for analysing with Abazure!\n");
				save();

			} else if (strcmp(doub_confirm, POS_RESP) == 0 || strcmp(doub_confirm, POS_RESP_LC) == 0) {
				printf("\nProfile has been deleted. Thank you for analysing with Abazure!\n");
			}

		} else if (strcmp(confirm, POS_RESP) == 0 || strcmp(confirm, POS_RESP_LC) == 0) {
			printf("\nProfile has been saved! Thank you for analysing with Abazure!\n");
			save();
		}
    
	return 0;
}



int save (void) {
	// Създаваме нов файл, така че към него да може да се добавят множество профили
    fptr = fopen("profiles_save.txt", "a");

    // Записваме информацията за създадения профил във файла
    fprintf(fptr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~\nPersonal data:\n\nName: %s\nLast name: %s\nClass: %d\nClass Repeats: %d\nAge: %d\nTerm: %d\n\n"
    	"\nTerm grades:\n\nEnglish: %3.2f%%\nForeign Language: %3.2f%%\nMath: %3.2f%%\nPhysics: %3.2f%%\nBiology: %3.2f%%\nChemistry: %3.2f%%\n"
    	"History: %3.2f%%\nGeography: %3.2f%%\nMusic: %3.2f%%\nPE: %3.2f%%\n"
    	"\nFinal analysis:\n%s\n%s\n%s\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n"
    	, a.prof_name, a.prof_l_name, a.prof_class, a.prof_repeat, a.prof_age, a.prof_term
    	, a.prof_eng, a.prof_f_lang, a.prof_math, a.prof_phs, a.prof_bio, a.prof_chem, a.prof_hist, a.prof_geo, a.prof_mus, a.prof_pe
    	, a.prof_term_ana, a.prof_lowest_grade_ana, a.prof_highest_grade_ana);

    // Затваряме файла
    fclose(fptr);

	return 0;
}