function EnvironmentProto() {
  this.temp = DEFAULT_TEMP
  this.time = performance.now()
  this.prevY = 10 // thermostat

  this.acStrength = 50 // percent
  this.acOn = false
}

EnvironmentProto.prototype.updateDOM = function(timeElapsed) {
  const ele = document.getElementById('thermo-temp')
  ele.innerHTML = this.temp.toFixed(2) + '&#8451;'
}

EnvironmentProto.prototype.setACStrength = function(strength) {
  this.acStrength = strength
}

EnvironmentProto.prototype.turnACOn = function() {
  this.acOn = true
  $('#thermo-ac-checker').prop('checked', true)
}

EnvironmentProto.prototype.turnACOff = function() {
  this.acOn = false
  $('#thermo-ac-checker').prop('checked', false)
}

EnvironmentProto.prototype.toggleAC = function() {
  this.acOn = !this.acOn
}

EnvironmentProto.prototype.update = function() {
  const newTime = performance.now()
  const timeElapsed = newTime - this.time
  this.time = newTime

  const delta =
    this.acOn && this.acStrength != 0
      ? (((-1 * this.acStrength) / 50) * timeElapsed) / 500
      : timeElapsed / 500

  this.temp += delta
  this.updateDOM(timeElapsed)
}

const Environment = (function() {
  let instance = null

  return {
    getInstance() {
      if (!instance) instance = new EnvironmentProto()
      return instance
    }
  }
})()
