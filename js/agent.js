function AgentProto() {
  this.sensedTemp = null
  this.decision = null
}

AgentProto.prototype.sense = function() {
  const envRef = Environment.getInstance()
  this.sensedTemp = envRef.temp
}

AgentProto.prototype.decide = function() {
  if (this.sensedTemp > MAX_TEMP) this.decision = 'turnACOn'
  else if (this.sensedTemp < MIN_TEMP) this.decision = 'turnACOff'
  else this.decision = null
}

AgentProto.prototype.act = function() {
  const envRef = Environment.getInstance()
  if (this.decision) {
    envRef[this.decision]()
  }
}

AgentProto.prototype.update = function() {
  this.sense()
  this.decide()
  this.act()
}

const Agent = (function() {
  let instance = null

  return {
    getInstance() {
      if (!instance) instance = new AgentProto()
      return instance
    }
  }
})()
