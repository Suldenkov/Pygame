import random
import pygame
from pygame.locals import *

head = [331, 331]
body = [[331, 331], [320, 331], [309, 331]]
count_iterable_speed = 0
fps = 3
control = 'RIGHT'
flag_game = True
flag_start_game = True
flag_food = True
flag_obgect = True
flag_append = True
obggect = []
flag_text_1 = True
flag_text_2 = True
flag_text_3 = True
flag_records = False
flag_level = False
c = [0] * 4356
food_position_x = 0
food_position_y = 0
food_position = []
score = 0
z = []
k = []
c[2140] = 2
c[2070] = 2
c[2010] = 2
c[1950] = 2
c[1890] = 2
c[1830] = 2
c[1770] = 2
c[1710] = 2
pause_flag = True
speed = 11
flag = True
name = ''
flag_final = False


def safe():
    global z
    z = []
    p = []
    m = []
    z.append(name + ' : ' + str(score))
    with open('records.txt', 'r', encoding='utf-8') as file:
        file.seek(0)
        if len(file.read()) > 0:
            file.seek(0)
            for x in file.readlines():
                z.append(x[:-1])
        file.close()
    z.sort()
    with open('records.txt', 'w', encoding='utf-8') as file:
        file.seek(0)
        if len(z) > 6:
            for x in range(6):
                # if i + ' : ' + str(m[x]) in z:
                file.write(z[x] + '\n')

        else:
            for i in z:
                # if i + ' : ' + str(x) in z:
                file.write(i + '\n')

        file.close()
    z = []


def final():
    global flag_game, flag, flag_start_game, flag_final, c, obggect, score, head, body
    global control, fps, flag_append
    flag_restart = True
    flag_menu = True
    while flag_final:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                flag = False
                flag_game = False
                flag_start_game = False
                flag_final = False
            if event.type == pygame.MOUSEMOTION:
                if 260 < event.pos[0] < 368 and 490 < event.pos[1] < 515:
                    flag_restart = False
                else:
                    flag_restart = True
                if 275 < event.pos[0] < 356 and 540 < event.pos[1] < 563:
                    flag_menu = False
                else:
                    flag_menu = True
            if event.type == pygame.MOUSEBUTTONDOWN:
                if 260 < event.pos[0] < 368 and 490 < event.pos[1] < 515:
                    safe()
                    obggect = []
                    c = [0] * 4356
                    score = 0
                    head = [331, 331]
                    body = [[331, 331], [320, 331], [309, 331]]
                    control = 'RIGHT'
                    fps = 3
                    flag_game = True
                    flag_final = False
                    flag_append = True
                    flag = True
                    obgect()
                if 275 < event.pos[0] < 356 and 540 < event.pos[1] < 563:
                    flag_game = False
                    flag_final = False
            if event.type == QUIT:
                flag_start_game = False
                flag_game = False
                flag = False
        screen.fill((0, 0, 0))
        lose = pygame.image.load('gg.png').convert()
        lose = pygame.transform.scale(lose, (662, 600))
        screen.blit(lose, (0, -80))
        font = pygame.font.Font(None, 45)
        if flag_restart:
            text_1 = font.render('Restart', 1, (255, 0, 0))
        else:
            text_1 = font.render('Restart', 1, (139, 0, 0))
        if flag_menu:
            text_2 = font.render('Menu', 1, (255, 0, 0))
        else:
            text_2 = font.render('Menu', 1, (139, 0, 0))
        screen.blit(text_1, (260, 490))
        screen.blit(text_2, (275, 540))
        pygame.display.flip()
    if flag_game:
        input_name()


def record():
    global flag_records, z, flag_start_game
    z = []
    with open('records.txt', 'r', encoding='utf-8') as file:
        file.seek(0)
        if len(file.read()) > 0:
            file.seek(0)
            for x in file.readlines():
                z.append(x[:-1])
        file.close()
    while flag_records:
        screen.fill((0, 0, 0))
        font = pygame.font.Font(None, 50)
        text = font.render("Records", 1, (100, 255, 100))
        name_game_x = width // 2 - text.get_width() // 2
        name_game_y = 100
        screen.blit(text, (name_game_x, name_game_y))
        screen.blit(back_image, (20, 20))
        font = pygame.font.Font(None, 25)
        for x in range(len(z)):
            text = font.render(z[x], 1, (255, 0, 0))
            text_x = 50
            text_y = 170 + 50 * x
            screen.blit(text, (text_x, text_y))
        for event in pygame.event.get():
            if event.type == QUIT:
                flag_records = False
                flag_start_game = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if 20 < event.pos[0] < 40 and 20 < event.pos[1] < 40:
                    flag_records = False
        pygame.display.flip()


def food():
    global flag_food, food_position_x, food_position_y, food_position
    while flag_food:
        food_position_x = random.randint(1, 59)
        food_position_y = random.randint(1, 59)
        food_position_x = food_position_x * 11 + 2
        food_position_y = food_position_y * 11 + 2
        food_position = [food_position_x - 1, food_position_y - 1]
        if food_position not in body and food_position not in k:
            flag_food = False
    pygame.draw.rect(screen, pygame.Color('red'), pygame.Rect(food_position_x, food_position_y, 10, 10))


def eat():
    global flag_food, score

    if head == food_position:
        body.append(food_position)
        flag_food = True
        score += 25


def draw():
    global flag_append, k
    x = 2
    y = 2
    for z in c:
        if z == 1:
            k.append([x, y])
            pygame.draw.rect(screen, pygame.Color('gray'), pygame.Rect(x, y, 10, 10))
            if flag_append:
                obggect.append([x - 1, y - 1])
        y += 11
        if y == 662:
            y = 2
            x += 11
    flag_append = False
    pygame.draw.line(screen, pygame.Color('white'), [1, 661], [662, 661])


def input_name():
    global name, flag, flag_game, flag_start_game
    size = 662, 683
    screen = pygame.display.set_mode(size)
    font = pygame.font.Font(None, 45)
    clock = pygame.time.Clock()
    box = pygame.Rect(200, 250, 200, 32)
    color = (141, 182, 205)
    active = False
    text = ''
    while flag:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                flag = False
                flag_game = False
                flag_start_game = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                if box.collidepoint(event.pos):
                    active = True
                else:
                    active = False
                if active:
                    color = (15, 82, 186)
                else:
                    color = (141, 182, 205)
            if event.type == pygame.KEYDOWN:
                if active:
                    if event.key == pygame.K_RETURN:
                        flag = False
                    elif event.key == pygame.K_BACKSPACE:
                        text = text[:-1]
                    else:
                        text += event.unicode
        name = text
        screen.fill((0, 0, 0))
        text_1 = font.render('Input nik name:)', 1, (15, 82, 186))
        screen.blit(text_1, (220, 190))
        txt_surface = font.render(text, True, color)
        input_box_width = max(300, txt_surface.get_width() + 10)
        screen.blit(txt_surface, (205, 253))
        pygame.draw.rect(screen, color, pygame.Rect(200, 250, input_box_width, 32), 2)
        pygame.display.flip()
        clock.tick(30)


class snake:
    def game_control(self):
        global flag_game, control, fps, pause_flag, flag_start_game
        for event in pygame.event.get():
            if event.type == QUIT:
                flag_game = False
                flag_start_game = False
            elif event.type == KEYDOWN:
                if event.key == K_RIGHT and control != 'LEFT':
                    control = 'RIGHT'
                if event.key == K_LEFT and control != 'RIGHT':
                    control = 'LEFT'
                if event.key == K_UP and control != 'DOWN':
                    control = 'UP'
                if event.key == K_DOWN and control != 'UP':
                    control = 'DOWN'
                if event.key == K_s and fps < 30:
                    fps += 5
                elif event.key == K_s and fps == 30:
                    fps = 5
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if 0 <= event.pos[0] < 20 and 661 < event.pos[1] < 681:
                    if pause_flag:
                        pause_flag = False
                    else:
                        pause_flag = True
                if 150 < event.pos[0] < 170 and 662 < event.pos[1] < 682:
                    flag_game = False

    def run(self):
        global flag_game, speed, flag_final
        if control == 'RIGHT':
            if head[0] == 650:
                head[0] = 1
            else:
                head[0] += speed
        elif control == 'LEFT':
            if head[0] == 1:
                head[0] = 650
            else:
                head[0] -= speed
        elif control == 'UP':
            if head[1] == 1:
                head[1] = 650
            else:
                head[1] -= speed
        elif control == 'DOWN':
            if head[1] == 650:
                head[1] = 1
            else:
                head[1] += speed
        body.insert(0, list(head))
        body.pop()
        if head in obggect:
            flag_final = True
            flag_game = False
            final()
        if head in body[1::]:
            flag_final = True
            flag_game = False
            final()

    def draw_snake(self):
        for x in body:
            pygame.draw.rect(screen, pygame.Color('blue'), pygame.Rect(x[0] + 1, x[1] + 1, 10, 10))


def obgect():
    global flag_obgect
    p = []
    v = []
    while len(p) != 20:
        position_obgect_x = random.randint(10, 40)
        position_obgect_y = random.randint(10, 40)
        for x in range(10):
            p.append(position_obgect_x + position_obgect_y * 60 + x)
            p.append(position_obgect_x + position_obgect_y * 60 + x * 60)
        for x in p:
            if c[x] != 0:
                p = []
                break
    for x in p:
        c[x] = 1
    while len(v) != 20:
        position_obgect_x = random.randint(10, 40)
        position_obgect_y = random.randint(10, 40)
        for x in range(10):
            v.append(position_obgect_x + position_obgect_y * 60 - x)
            v.append(position_obgect_x + position_obgect_y * 60 - x * 60)
        for x in v:
            if c[x] != 0:
                v = []
                break
    for x in v:
        c[x] = 1


def game():
    global c, obggect, score, head, body, control, speed, fps
    obgect()
    input_name()
    s = snake()
    while flag_game:
        s.game_control()
        screen.fill(pygame.Color('black'))
        draw()
        food()
        eat()
        s.draw_snake()
        font = pygame.font.Font(None, 25)
        text = font.render('Score:', 1, (139, 0, 0))
        screen.blit(text, (51, 662))
        text = font.render(str(score), 1, (139, 0, 0))
        screen.blit(text, (111, 663))
        screen.blit(back_image, (150, 662))
        if pause_flag:
            screen.blit(stop_image, (0, 662))
            s.run()
        else:
            screen.blit(play_image, (0, 662))
        clock.tick(fps)
        pygame.display.flip()
    safe()
    obggect = []
    c = [0] * 4356
    score = 0
    head = [331, 331]
    body = [[331, 331], [320, 331], [309, 331]]
    control = 'RIGHT'
    fps = 3


def start_game():
    global flag_start_game, flag_game, flag_text_1, flag_text_2, flag_text_3
    global flag_records, flag_level, flag, flag_append
    while flag_start_game:
        screen.fill((30, 30, 30))
        screen.blit(start_image, (0, 0))
        font = pygame.font.Font(None, 50)
        p = ['·Start game', '·Records'] #'·Level']
        for x in range(2):
            if x == 0 and flag_text_1 is False:
                text = font.render(p[0], 1, (71, 71, 71))
                screen.blit(text, (237, 330))
            elif x == 1 and flag_text_2 is False:
                text = font.render(p[1], 1, (71, 71, 71))
                screen.blit(text, (257, 400))
            elif x == 2 and flag_text_3 is False:
                text = font.render(p[2], 1, (71, 71, 71))
                screen.blit(text, (282, 470))
            else:
                text = font.render(p[x], 1, (0, 0, 0))
                text_x = width // 2 - text.get_width() // 2
                text_y = 330 + 70 * x
                screen.blit(text, (text_x, text_y))
        for event in pygame.event.get():
            if event.type == pygame.MOUSEBUTTONDOWN:
                if 237 < event.pos[0] < 425 and 330 < event.pos[1] < 358:
                    flag_game = True
                    flag = True
                    flag_append = True
                    game()
                if 257 < event.pos[0] < 404 and 400 < event.pos[1] < 428:
                    flag_records = True
                    record()
                #if 282 < event.pos[0] < 377 and 470 < event.pos[1] < 498:
                    # flag_start_game = False
                    #flag_level = True
            if event.type == QUIT:
                flag_start_game = False
                flag_game = False
                flag = False
            if event.type == pygame.MOUSEMOTION:
                if 237 < event.pos[0] < 425 and 330 < event.pos[1] < 358:
                    flag_text_1 = False
                else:
                    flag_text_1 = True
                if 257 < event.pos[0] < 404 and 400 < event.pos[1] < 428:
                    flag_text_2 = False
                else:
                    flag_text_2 = True
               # if 282 < event.pos[0] < 377 and 470 < event.pos[1] < 498:
               #     flag_text_3 = False
                #else:
                #    flag_text_3 = True
        pygame.display.flip()


pygame.init()
pygame.display.set_caption("Змейка")
size = width, height = 662, 683
screen = pygame.display.set_mode(size)
start_image = pygame.image.load('start.png').convert()
start_image = pygame.transform.scale(start_image, (662, 683))
clock = pygame.time.Clock()
back_image = pygame.image.load('back.png').convert()
back_image = pygame.transform.scale(back_image, (20, 20))
stop_image = pygame.image.load('stop.png').convert()
stop_image = pygame.transform.scale(stop_image, (20, 20))
play_image = pygame.image.load('play.png').convert()
play_image = pygame.transform.scale(play_image, (20, 20))
start_game()
pygame.quit()
