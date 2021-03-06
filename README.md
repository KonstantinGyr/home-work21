# home-work21
Задание 1. Реализация ведомости учёта

Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет обобщить и дополнить использованием структур.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи в формате ДД.ММ.ГГГГ., затем — сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть перевод строки.
Структура данных записи должна соответствовать указанному формату.
При старте программы пользователь указывает команду, которую следует осуществить: list или add. Команда read осуществляет чтение из файла ведомости как и прежде, только уже в структуры данных и отображает их на экране.
Команда add добавляет новую запись в конец ведомости.

Советы и рекомендации
Чтобы определить конец файла, используйте функцию file.eof() как и прежде. Из-за завершающего переноса строки, также стоит проверить и имя. Если оно было считает пустым, то можно считать, что файл закончился.

Задание 2. Модель данных для посёлка

Что нужно сделать
С помощью структур данных создайте подробную модель посёлка.
В посёлке есть множество участков. Каждый из них имеет свой уникальный номер. На каждом из участков должен быть расположен как минимум один жилой дом, но возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня. Для каждого здания предусмотрена информация о площади, которую он занимает на участке.
В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты. Каждая комната при этом может быть разных типов: спальня, кухня, ванная, детская, гостиная. Для каждой комнаты предусмотрены данные о её площади. Для каждого этажа также есть данные о высоте потолка. В жилом доме и бане может быть печь с трубой, информация об этом также должна быть предусмотрена в данных.
Для всех упомянутых сущностей надо объявить соответствующие структуры данных.
Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает детализировать каждый из участков.
Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи, комнаты на этажах.
По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой постройками, к общей площади всего посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.

Советы и рекомендации
Используйте все имеющиеся у вас знания о типах данных в C++. Можно  использовать уже изученные перечисления и массивы, создавать структуры внутри структур и так далее.

Задание 3. Реализация математического вектора

Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе координаты вектора (x и y) должны быть вещественными числами.
Вначале программы пользователь вводит команду, которая соответствует требуемой операции. Далее, в зависимости от операции, пользователь вводит её аргументы. Это могут быть как вектора, так и обычные, скалярные значения. В результате в стандартный вывод помещается результат. Это тоже может быть или вектор, или скаляр.

Реализуйте следующие операции в виде отдельных функций:
    • Сложение двух векторов — команда add.
    • Вычитание двух векторов — команда subtract.
    • Умножение вектора на скаляр — команда scale.
    • Нахождение длины вектора — команда length.
    • Нормализация вектора — команда normalize.

Задание 4. Реализация ролевой пошаговой игры

Что нужно сделать
Реализуйте сильно упрощённую версию ролевой пошаговой игры:
Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги и персонаж игрока.
После каждого хода игрока карта показывается вновь со всеми врагами на ней. Игрок помечается буквой P. Враги буквой E. Пустые места — точкой.
Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня, урон.
Вначале игры создаются 5 случайных врагов в случайных клетках карты. Имена врагам задаются в формате “Enemy #N”, где N — это порядковый номер врага. Уровень жизней врагам задаётся случайно, от 50 до 150. Уровень брони варьируется от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.
Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя.
Все персонажи появляются в случайных местах карты.
Игрок осуществляет ход с помощью команд: left, right, top, bottom. В зависимости от команды и выбирается направление перемещения персонажа: влево, вправо, вверх, вниз.
Враги перемещаются в случайном направлении.
Если персонаж (враг или игрок) перемещается в сторону, где уже находится какой-то персонаж, то он бьёт этого персонажа с помощью своего урона. Враги при этом никогда не бьют врагов, а просто пропускают ход и остаются на своём месте. За пределы карты (40 на 40 клеток) ходить нельзя никому. Если кто-то выбрал направление за гранью дозволенного, ход пропускается.
Формула для расчёта урона совпадает с той, что была в самом уроке. Жизни уменьшаются на оставшийся после брони урон. При этом сама броня тоже сокращается на приведённый урон.
Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока. В первом случае на экран выводится сообщение о поражении, во втором — победа.
Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра либо делает сохранение своего состояния в файл, либо загружает это состояние из файла соответственно.

Советы и рекомендации
Для определения команды персонажа можно завести специальный флаг внутри структуры данных персонажа.
Для отображения координат персонажей можете использовать структуру вектора из другой задачи, но заменить типы координат.

