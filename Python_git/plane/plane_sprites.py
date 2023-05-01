import pygame
import random

#定义常量
SCREEN_WIDTH = 480
SCREEN_HEIGHT = 700
CREATE_ENEMY_EVENT = pygame.USEREVENT
FIRE_EVENT = pygame.USEREVENT +1

class GameSprite(pygame.sprite.Sprite) :
    def __init__(self, image_path, speed = 1):
        super().__init__()
        self.image = pygame.image.load(image_path)
        self.rect = self.image.get_rect()
        self.speed = speed
        self.rect.x = random.randint(0, SCREEN_WIDTH - self.rect.width) #将x坐标设为随机值
    def update(self):
        self.rect.y += self.speed

class Background(GameSprite):
    def __init__(self, is_alt = False):
        super().__init__(".\images\\background.png")
        self.rect.x = 0
        if is_alt :
            self.rect.y = -SCREEN_HEIGHT
    def update(self):
        super().update()
        if self.rect.y >= SCREEN_HEIGHT:
            self.rect.y = -SCREEN_HEIGHT

class Hero(GameSprite):
    def __init__(self):
        super().__init__(".\images\me1.png")
        self.rect.x = 200
        self.rect.y = 500
        self.speed = 0
        self.bullet_group = pygame.sprite.Group()
    def update(self, is_alt = True):
        super().update()
        if is_alt :
            if self.rect.x > 0 :
                self.rect.x -= 3
        else :
            if self.rect.x < SCREEN_WIDTH - self.rect.width :
                self.rect.x += 3
    def fire(self):
        for i in(1,2,3) :
            bullet = Bullets()
            bullet.rect.bottom = self.rect.y - 20 * i
            bullet.rect.centerx = self.rect.centerx
            self.bullet_group.add(bullet)

class Enemy(GameSprite):
    def __init__(self):
        super(Enemy, self).__init__(".\images\enemy1.png")
        self.speed = random.randint(1, 3)
        self.smoke_group = pygame.sprite.Group()
    def update(self):
        super(Enemy, self).update()
        if self.rect.y >= SCREEN_HEIGHT :
            self.kill()

class Bullets(GameSprite):
    def __init__(self):
        super().__init__(".\images\\bullet1.png", -2)
    def update(self):
        super(Bullets, self).update()
        if self.rect.bottom <= 0:
            self.kill()

class Enemy_down(GameSprite):
    def __init__(self):
        super().__init__(".\images\enemy1_down1.png", 0)
