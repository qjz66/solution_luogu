import pygame
from plane_sprites import *

#创建主游戏类
class MainGame(object):
    def __init__(self):
        #创建窗口
        self.screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        #创建时钟
        self.clock = pygame.time.Clock()
        pygame.time.set_timer(CREATE_ENEMY_EVENT, 1000)
        pygame.time.set_timer(FIRE_EVENT, 500)
    #创建精灵对象
    def __create_sprites(self):
        background_1 = Background()
        background_2 = Background(True)
        #enemy_1 = Enemy()
        self.hero = Hero()
        self.sprites_group = pygame.sprite.Group(background_1, background_2)
        self.enemy_group = pygame.sprite.Group()
        self.hero_group = pygame.sprite.Group(self.hero)
    #创建事件监听
    def __event_get(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                MainGame.__game_over()
            elif event.type == CREATE_ENEMY_EVENT:
                enemy = Enemy()
                self.enemy_group.add(enemy)
            elif event.type == FIRE_EVENT :
                self.hero.fire()
        keys_pressed = pygame.key.get_pressed()
        if keys_pressed[pygame.K_RIGHT] :
            self.hero_group.update(False)
        elif keys_pressed[pygame.K_LEFT] :
            self.hero_group.update(True)
        else :
            pass
    #创建碰撞检测
    def __punch_judge(self):
        pygame.sprite.groupcollide(self.hero.bullet_group, self.enemy_group, True, True)
        enemies = pygame.sprite.spritecollide(self.hero, self.enemy_group, True)
        if len(enemies) > 0 :
            self.hero.kill()
            print("GAME OVER!")
            MainGame.__game_over()
    #创建刷新帧率
    def __frame_update(self):
        self.clock.tick(60)
    #更新绘制精灵组
    def __locate_draw(self):
        self.sprites_group.update()
        self.sprites_group.draw(self.screen)
        self.enemy_group.update()
        self.enemy_group.draw(self.screen)
        self.hero_group.draw(self.screen)
        self.hero.bullet_group.update()
        self.hero.bullet_group.draw(self.screen)
    #创建更新显示
    def __update_all(self):
        pygame.display.update()
    #游戏启动装置
    def start_game(self):
        print("Ready?Go!")
        pygame.init()
        self.__create_sprites()
        while True:
            self.__frame_update()
            self.__event_get()
            self.__punch_judge()
            self.__locate_draw()
            self.__update_all()
    @staticmethod
    def __game_over():
        pygame.quit()
        exit()

if __name__ == '__main__':
    game = MainGame()
    game.start_game()