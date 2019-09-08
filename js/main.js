// describe the values assumed by the rectangle
// translated vertically from its original position to 0 and then back slightly to hide more content
const translate = [
  {
    value: 'translate(0 20)'
  },
  {
    value: 'translate(0 0)'
  },
  {
    value: 'translate(0 7)'
  }
]

const initialTranslation = [
  {
    value: 'translate(0 20)'
  },
  {
    value: 'translate(0 10)'
  }
]

anime({
  targets: document.querySelector('svg #clip rect'),
  transform: initialTranslation,
  duration: START_UP_DURATION,
  easing: 'easeOutQuad'
})

$(function() {
  var rangePercent = $('#temp-range-input').val()
  $('#temp-range-input').on('change input', function() {
    rangePercent = $('#temp-range-input').val()

    // Change Environment
    Environment.getInstance().setACStrength(rangePercent)

    $('#temp-range-percentage').text('AC Strength: ' + rangePercent + '%')
    $('#temp-range-input').css('filter', 'hue-rotate(-' + rangePercent + 'deg)')
  })

  $('#thermo-ac-checker').on('click', function() {
    Environment.getInstance().toggleAC()
  })
})

let prevY = 10
setTimeout(() => {
  setInterval(() => {
    Environment.getInstance().update()
    Agent.getInstance().update()
  }, 1000 / 10)
  setInterval(() => {
    const newY = 20 * (1 - (Environment.getInstance().temp - MIN_TEMP) / (MAX_TEMP - MIN_TEMP))
    if (newY <= -10) return
    const translation = [{ value: `translate(0 ${prevY})` }, { value: `translate(0 ${newY})` }]
    prevY = newY

    anime({
      targets: document.querySelector('svg #clip rect'),
      transform: translation,
      duration: 300,
      easing: 'easeInOutSine'
    })
  }, 300)
}, START_UP_DURATION)
