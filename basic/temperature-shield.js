
var Shield = {
  id: 6 /*must be a number*/,
  name: 'temperature-shield',
  delay: 5000,
  safelet: function (payload) {
    /*value == <number>*/
    return payload.d.states.temperature.value > 23;
  },

  entryCondition: function (payload) {
    return payload.d && payload.d.states && payload.d.states.temperature !== undefined;
  },

  preProcessing: undefined,

  message: function (payload) {
    return constructMessage(
      payload,
      Shield.id,
      'TemperatureHazard',
      'Its too hot!'
    );
  }
};

registerShield(
  Shield.id,
  Shield.name,
  Shield.entryCondition,
  Shield.preProcessing,
  Shield.safelet,
  Shield.message,
  Shield.delay
);
