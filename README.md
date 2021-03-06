# Проект, разрабатываемый в рамках курса "Проектный практикум" от УрФУ

- **Название проекта**: Растопи лёд
- **Название команды**: Команда №3002
- **Trello:** 
  - Ссылка: https://trello.com/b/R2G94CGp
  - QR-код
  
  ![изображение](https://user-images.githubusercontent.com/73441333/143671084-e66ddb39-0e30-47a1-b35a-601c575299f1.png)

- **Формат системы**: автономное устройство.

- **Цель**: Изготовить прототип или готовое устройство, способное в зимний период осушить лёд на бетонной плите, затратив минимальное количество электроэнергии. 

- **Описание**

  Требования к продукту:
  
  - Решение проблемы заказчика (уменьшение затрат э/э);
  - Минимальное потребление э/э;
  - Минимальная стоимость изготовления;
  - Минимальная стоимость эксплуатации;
  - Простота настройки;
  - Простота эксплуатации.

- **Целевая аудитория**: Владельцы аппаратов налива воды, в том числе организация «Водоробот» 

- **Основное преимущество**:  Устройство позволяет сэкономить средства, затрачиваемые на оплату электроэнергии, которая тратится на обогрев плиты.

- **Стек технологий**: 

  Платформа Arduino UNO; Среда разработки Arduino IDE; Ультразвуковой дальномер HC-SR04; Светодиоды: красный, желтый, зеленый; Кнопочный переключатель; Резисторы.

- **Работа пользователя с системой**: 

    - Сенсор устройства устанавливается над отслеживаемой поверхностью;
    - Устройство включается (при этом происходит автоматическая калибровка, о чем сигнализирует мигающий зеленый светодиод);
    - Если калибровка прошла успешно, устройство переходит в штатный рабочий режим;
    - Если горит желтый светодиод – необходимо провести калибровку вручную, нажав на кнопку;
    - В штатном рабочем режиме происходит контроль состояния отслеживаемой поверхности.
