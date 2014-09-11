(function(window, document, navigator){

  if (document.getElementById('sawpf')) return;

  // ---------------------------------------------------------------------------------------------------

  var browserVersion = function() {
      var version = (userAgent.match(/.+(?:firefox|ie)[\/: ]([\d.]+)/) || [0, 0])[1];
      if(version===0) {
          //Para internet explorer 11 e superiores:
          version = (userAgent.match(/.+rv:([\d.]+)/) || 0)[1];
      }
      return parseFloat(version);
  };
  
  // based on jquery's browser detection
  var userAgent = navigator.userAgent.toLowerCase();
  var BrowserDetect = {
    version: browserVersion(),
    msie: ((/msie/).test(userAgent)||(/trident/).test(userAgent)) && !(/opera/).test(userAgent),
    firefox: (/firefox/).test(userAgent)||((/mozilla/).test(userAgent) && !(/(compatible|webkit)/).test(userAgent))
  };
  var isFirefox = (BrowserDetect.firefox);
  var isIE = (BrowserDetect.msie);

  // http://blog.orite.com.au/web_development/2009-06-30/jquery-ie-detection-issue-workaround/
  if (isIE && BrowserDetect.version == 6 && (/msie 8/.test(userAgent))) BrowserDetect.version = 8;

  // http://stackoverflow.com/questions/1328963/detect-ie8-compatibility-mode
  // http://social.msdn.microsoft.com/Forums/en-US/netfxjscript/thread/ae715fd2-1ddd-46f7-8c26-9aed6b2103f1/
  if (isIE && BrowserDetect.version < 9 && document.documentMode < 9) {
      var trident = parseInt((userAgent.match(/.+trident\/(\d+)\..*/) || [0,0])[1], 10);
      BrowserDetect.version = trident < 5 ? 8 : 9;
  }
  
  // ---------------------------------------------------------------------------------------------------

  if (!(isFirefox || isIE)) return;
  if (isFirefox && BrowserDetect.version >= 26) return;
  if (isIE && BrowserDetect.version >= 9) return;
  // ---------------------------------------------------------------------------------------------------

  // Cookie control
  var Cookie = {
    set: function(name, value, msecs){
      var cookie = [];
      cookie.push(name + "=" + value);
      cookie.push('path=/');
      // TODO: cookie.push('domain=.' + this._getDomain());
      if (msecs) cookie.push('expires=' + this._getExpire(msecs));
      document.cookie = cookie.join("; ");
    },

    // TODO: refactore to not loop through values
    get: function(name){
      var kvPairs = document.cookie.split(';');
      var nameEQ  = name + "=";

      for(var i = 0; i < kvPairs.length; i++) {
        var kvPair = kvPairs[i]; // key=value pair        
        while (kvPair.charAt(0) == ' ') kvPair = kvPair.substring(1, kvPair.length);
        if (kvPair.indexOf(nameEQ) == 0) return kvPair.substring(nameEQ.length, kvPair.length);
      }
      return null;
    },

    unset: function(name) {
      Cookie.set(name, '', -1000);
    },

    _getExpire: function(msecs){
      var d = new Date();
      d.setTime(d.getTime() + msecs);
      return d.toGMTString();
    }
  };
  
  // ---------------------------------------------------------------------------------------------------
  
  // verifica se o usuário fechou a barrinha, dando-lhe 7 dias de folga da barrinha no site em que fechou
  if (Cookie.get('__sawpf_') == '1') return;

  // ---------------------------------------------------------------------------------------------------

  // emile.js (c) 2009 Thomas Fuchs
  // Licensed under the terms of the MIT license.
  (function(emile, container){
    var parseEl = document.createElement('div'),
        props = ['height']; // removidas as outras propriedades do script original

    function interpolate(source,target,pos){
      return (source+(target-source)*pos).toFixed(3);
    };

    function parse(prop){
      return { v: parseFloat(prop), f: interpolate, u: prop.replace(/^[\-\d\.]+/,'') };
    };

    function normalize(style){
      var css, rules = {}, i = props.length, v;
      parseEl.innerHTML = '<div style="'+style+'"></div>';
      css = parseEl.childNodes[0].style;
      while(i--) {
        v = css[props[i]];
        if(v) rules[props[i]] = parse(v);
      };
      return rules;
    };

    container[emile] = function(el, style, opts, after){
      el = typeof el == 'string' ? document.getElementById(el) : el;
      opts = opts || {};
      var target = normalize(style), comp = el.currentStyle ? el.currentStyle : getComputedStyle(el, null),
        prop, current = {}, start = +new Date, dur = opts.duration||200, finish = start+dur, interval,
        easing = opts.easing || function(pos){ return (-Math.cos(pos*Math.PI)/2) + 0.5; };
      for(prop in target) current[prop] = parse(comp[prop]);
      interval = setInterval(function(){
        var time = +new Date, pos = time>finish ? 1 : (time-start)/dur;
        for(prop in target)
          el.style[prop] = target[prop].f(current[prop].v,target[prop].v,easing(pos)) + target[prop].u;
        if(time>finish) { clearInterval(interval); opts.after && opts.after(); after && setTimeout(after,1); }
      },10);
    };
  })('emile', this);

  // ---------------------------------------------------------------------------------------------------

  //var SPRITE_URL = (window['base_url'] || 'http://sawpf.com') + '/imgs/1.0.gif';background: url(/sis_layout/img/bg_body.png) 0 -139px

  var css = '#sawpf * {margin: 0; padding: 0; text-shadow: 1px 1px 0px #FFF;}' +
    '#sawpf {text-align: center; height: 0; overflow: hidden; background-color: #edeff4; border-bottom: 1px solid #99CCFF; font-family: arial; position: relative; width: 100%}' +
    '#sawpf div {margin: 0 auto; width: 800px; padding: 9px 0;}' +
    '#sawpf strong {color: #003366; font-size: 12px; line-height: 18px;}' +
	'#sawpf strong u {color: #FF3300}' +
    '#sawpf p {color: #666; float: left; font-size: 11px; line-height: 12px; margin: -3px 20px 0 0; text-align: left}' +
    '#sawpf ul {list-style: none; float:right;}' +
    '#sawpf li {display: block; float: left; margin-right: 5px}' +
    '#sawpf a, #sawpf a span {background-image: url(/sis_imagens/navegadores.gif); text-indent: -99em; display: block; cursor: pointer}' +
    '#sawpf a {outline: none; overflow: hidden}' +
    '#sawpf ul a, #sawpf ul a span {height: 40px; width: 150px}' +
    '#sawpf ul a:hover {background-position: 0 -40px}' +
    '#sawpf ul a:active {background-position:0 -80px}' +
    '#sawpf ul a:active span {margin-top: 1px}' +
    '#sawpf .sawpf-ie span {background-position: 0 -198px}' +
    '#sawpf .sawpf-ff span {background-position: 0 -120px}' +
    '#sawpf .sawpf-gc span {background-position: 0 -158px}' +
	'#sawpf #sawpf-close {background-image: url(/Novos/Sistemas/DiarioEletronico/Css/img/add-fecharM.gif); width: 11px; height: 11px; position: absolute; right:5px; top: 5px;opacity:0.5; filter:alpha(opacity=50); -ms-filter:"progid:DXImageTransform.Microsoft.Alpha(Opacity=50);";}' +
	'#sawpf #sawpf-close:hover {opacity:1; filter:alpha(opacity=100); -ms-filter:"progid:DXImageTransform.Microsoft.Alpha(Opacity=100);";}';

  var styleTag = document.createElement('style');
  styleTag.type = 'text/css';
  if(!window['ActiveXObject']) {
    styleTag.innerHTML = css;
  } else {
    styleTag.styleSheet.cssText = css;
  }
  document.getElementsByTagName('head')[0].appendChild(styleTag);
  document.getElementsByTagName('body')[0].style.backgroundPosition = '0 60px';
 

  var IE_BUTTON = '<a href="http://windows.microsoft.com/pt-BR/internet-explorer/downloads/ie" class="sawpf-ie" title="Internet Explorer"><span>Internet Explorer</span></a>';
  
  var FIREFOX_BUTTON = '<a href="http://br.mozdev.org/download/" class="sawpf-ff" title="Firefox"><span>Firefox</span></a>';
  
  var CHROME_BUTTON = '<a href="http://www.google.com/chrome?hl=pt-BR" class="sawpf-gc" title="Google Chrome"><span>Google Chrome</span></a>';

  var Navegador_Utilizado = "";
  if (isIE) {
	Navegador_Utilizado = "Internet Explorer";
  } else {
	Navegador_Utilizado = "Mozilla Firefox";
  }
  
  var html = '<div><p><strong>Seu navegador <u>' + Navegador_Utilizado +'</u> est&aacute; desatualizado.</strong><br/>' +
    'Para uma melhor visualiza&ccedil;&atilde;o do autoatendimento,<br>realize uma atualiza&ccedil;&atilde;o ou escolha outro navegador.</p>' +
    '<ul><li>' + CHROME_BUTTON + '</li><li>' + FIREFOX_BUTTON + '</li><li>' + IE_BUTTON + '</li></ul>' +
    '<a href="#" id="sawpf-close" title="Fechar">fechar</a>' +
    '</div>';

  var container = document.createElement('div');
  container.id = 'sawpf';
  container.innerHTML = html;

  document.body.insertBefore(container, document.body.firstChild);

  document.getElementById('sawpf-close').onclick = function() {
    Cookie.set('__sawpf_', '1', 172800000); // Alterado para 2 dias (antes estava em 7 dias [7 * 24 * 60 * 60 * 1000] ) 
    emile(container, 'height: 0', {
      duration: 300,
      after: function(){container.style.display = 'none';}
    });
    return false;
  };
  emile(container, 'height: 58px', {duration: 1000});
})(this, document, navigator);

