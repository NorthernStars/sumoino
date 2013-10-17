/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
var opts = {
  lines: 20, // The number of lines to draw
  length: 15, // The length of each line
  width: 15, // The line thickness
  radius: 30, // The radius of the inner circle
  corners: 1, // Corner roundness (0..1)
  rotate: 0, // The rotation offset
  direction: 1, // 1: clockwise, -1: counterclockwise
  color: '#000', // #rgb or #rrggbb
  speed: 1, // Rounds per second
  trail: 60, // Afterglow percentage
  shadow: false, // Whether to render a shadow
  hwaccel: false, // Whether to use hardware acceleration
  className: 'spinner', // The CSS class to assign to the spinner
  zIndex: 2e9, // The z-index (defaults to 2000000000)
  top: '75%', // Top position relative to parent in px
  left: '75%' // Left position relative to parent in px
};

var app = {
  // Application Constructor
  initialize: function() {
    this.bindEvents();
  },
  // Bind Event Listeners
  //
  // Bind any events that are required on startup. Common events are:
  // 'load', 'deviceready', 'offline', and 'online'.
  bindEvents: function() {
    document.addEventListener('deviceready', this.onDeviceReady, false);
  },
  // deviceready Event Handler
  //
  // The scope of 'this' is the event. In order to call the 'receivedEvent'
  // function, we must explicity call 'app.receivedEvent(...);'
  onDeviceReady: function() {
    app.receivedEvent('deviceready');
  },
  // Update DOM on a Received Event
  receivedEvent: function(id) {
    var parentElement = document.getElementById(id);
    var listeningElement = parentElement.querySelector('.listening');
    var receivedElement = parentElement.querySelector('.received');

    listeningElement.setAttribute('style', 'display:none;');
    receivedElement.setAttribute('style', 'display:block;');
    console.log('Received Event: ' + id);
  }
};

function onLoad() {
  // hack, remove border from blocklySvg
  var div = document.getElementById('blocklyDiv');
  var elems = div.getElementsByTagName('*');
  elems[0].style.border = 'none';
  // initialize loading spinner
  var spinner = new Spinner(opts);
}

function exitFromApp() {
  navigator.app.exitApp();
}

function showLoading(loading) {
  document.getElementById('send').disabled = loading;
  if (loading)
    spinner.spin( document.getElementById('loading') );
  else
    spinner.stop();
}

function sendCode() {
    showLoading(true);
    setInterval( function() { execSendCode(); }, 10 );
}

function execSendCode() {
  cordova.exec(
    // on success
    function(winParam) {
      //alert('success');
      showLoading(false);
    },
    // on error
    function(error) { 
      //alert('error: '+error);
      showLoading(false);
    },
    // plugin, action, arguments
    'CompilerPlugin', 'compile', [Blockly.Generator.workspaceToCode('JavaScript')]
  );
}

function showCode() {
  var code = Blockly.Generator.workspaceToCode('JavaScript');
  alert(code);
}
