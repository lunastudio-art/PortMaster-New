local object = object:extend()
object.layer = 2
object.tag = "pickable"

local HOVER_DELAY = 0.5

function object:create(ldtkEntity)
    self.position = vector(ldtkEntity.x, ldtkEntity.y)
    self.sprite = sprite("objects/banana.png")

    self.offset = false
    self.offsetValue = 0
    self.hoverTimer = 0
    
    self.target = ldtkEntity.props.target
    if not self.target then
        self.target = ldtk:getCurrentName()
    end
    self.slowed = false

    self.picked = false
    
    game.world:add(self, self.position.x, self.position.y, 8, 8)
    game.shadows:add(self)
end

function object:update(dt)
    if game.paused then
        return
    end

    if self.slowed then
        game.timeScale = math.lerp(game.timeScale, 1, 9 * dt)
        if game.timeScale > 0.95 then
            game.timeScale = 1
            self.slowed = false
        end
    end

    if self.hoverTimer > 0 then
        self.hoverTimer = self.hoverTimer - dt
    else
        self.offset = not self.offset
        self.hoverTimer = HOVER_DELAY
    end

    self.sprite:update(dt)

    self.offsetValue = math.lerp(self.offsetValue, self.offset and 1 or 0, 1 * dt)
end

function object:draw()
    if game.subpixel then
        self.sprite:draw(self.position.x, self.position.y + self.offsetValue)
    else
        self.sprite:draw(math.round(self.position.x), math.round(self.position.y + self.offsetValue))
    end

    if DEBUG then
        color.reset(0.5)
        graphics.rectangle("fill", game.world:getRect(self))
    end
end

function object:playerEnter(player, number)
    if not self.picked then
        -- Pick sound
        game.playSound("banana.wav")
        self.picked = true
        game.won = true
        if self.target then
            game.checkpoint = nil
            objects.splash_in(self.position.x + 4, self.position.y + 4, self.target)
        end

        self.slowed = true
        game.timeScale = 0.25
    end
    
end

function object:remove()
    game.world:remove(self)
    game.shadows:remove(self)
end

return object