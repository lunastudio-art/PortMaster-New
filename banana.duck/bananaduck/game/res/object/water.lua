local object = object:extend()
object.tag = "danger"

function object:create(ldtkEntity)
    self.position = vector(ldtkEntity.x, ldtkEntity.y)
    self.sprite = sprite("objects/water1.png", "objects/water2.png", 0.4)
    self.length = ldtkEntity.width / 8
    if ldtkEntity.height > 8 then
        self.body = sprite("objects/water3.png")
        self.body:setScale(self.length, math.round((ldtkEntity.height - 8) / 8))
    end

    game.world:add(self, self.position.x, self.position.y + 2 , ldtkEntity.width, 6)
end

function object:update(dt)
    if game.paused then
        return
    end
    self.sprite:update(dt)
end

function object:draw()
    if game.subpixel then
        for i = 0, self.length - 1, 1 do
            self.sprite:draw(self.position.x + i * 8, self.position.y)
        end
        if self.body then
            self.body:draw(self.position.x, self.position.y + 8)
        end
    else
        for i = 0, self.length - 1, 1 do
            self.sprite:draw(math.round(self.position.x + i * 8), math.round(self.position.y))
        end
        if self.body then
            self.body:draw(math.round(self.position.x), math.round(self.position.y + 8))
        end
    end
end

function object:remove()
    game.world:remove(self)
end

return object