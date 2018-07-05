var __extends = this.__extends || function(d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() {
        this.constructor = d;
    }
    __.prototype = b.prototype;
    d.prototype = new __();
};

"function" != typeof Object.assign && !function() {
    Object.assign = function(n) {
        "use strict";
        if (void 0 === n || null === n) throw new TypeError("Cannot convert undefined or null to object");
        for (var t = Object(n), r = 1; r < arguments.length; r++) {
            var e = arguments[r];
            if (void 0 !== e && null !== e) for (var o in e) e.hasOwnProperty(o) && (t[o] = e[o]);
        }
        return t;
    };
}();

window.$ = window.jQuery || function(e, t, l) {
    try {
        var n = {
            "#": "getElementById",
            ".": "getElementsByClassName",
            "@": "getElementsByName",
            "=": "getElementsByTagName",
            "*": "querySelectorAll"
        }[e[0]], m = (t === l ? document : t)[n](e.slice(1));
        !m.length ? m[0] = m : null;
        return !m.length ? m : m.length < 2 ? m[0] : [].slice.call(m);
    } catch (er) {
        return document.querySelectorAll(e);
    }
};

if ("document" in self) {
    if (!("classList" in document.createElement("_")) || document.createElementNS && !("classList" in document.createElementNS("http://www.w3.org/2000/svg", "g"))) {
        (function(t) {
            "use strict";
            if (!("Element" in t)) return;
            var e = "classList", i = "prototype", n = t.Element[i], s = Object, r = String[i].trim || function() {
                return this.replace(/^\s+|\s+$/g, "");
            }, a = Array[i].indexOf || function(t) {
                var e = 0, i = this.length;
                for (;e < i; e++) {
                    if (e in this && this[e] === t) {
                        return e;
                    }
                }
                return -1;
            }, o = function(t, e) {
                this.name = t;
                this.code = DOMException[t];
                this.message = e;
            }, l = function(t, e) {
                if (e === "") {
                    throw new o("SYNTAX_ERR", "An invalid or illegal string was specified");
                }
                if (/\s/.test(e)) {
                    throw new o("INVALID_CHARACTER_ERR", "String contains an invalid character");
                }
                return a.call(t, e);
            }, c = function(t) {
                var e = r.call(t.getAttribute("class") || ""), i = e ? e.split(/\s+/) : [], n = 0, s = i.length;
                for (;n < s; n++) {
                    this.push(i[n]);
                }
                this._updateClassName = function() {
                    t.setAttribute("class", this.toString());
                };
            }, u = c[i] = [], f = function() {
                return new c(this);
            };
            o[i] = Error[i];
            u.item = function(t) {
                return this[t] || null;
            };
            u.contains = function(t) {
                t += "";
                return l(this, t) !== -1;
            };
            u.add = function() {
                var t = arguments, e = 0, i = t.length, n, s = false;
                do {
                    n = t[e] + "";
                    if (l(this, n) === -1) {
                        this.push(n);
                        s = true;
                    }
                } while (++e < i);
                if (s) {
                    this._updateClassName();
                }
            };
            u.remove = function() {
                var t = arguments, e = 0, i = t.length, n, s = false, r;
                do {
                    n = t[e] + "";
                    r = l(this, n);
                    while (r !== -1) {
                        this.splice(r, 1);
                        s = true;
                        r = l(this, n);
                    }
                } while (++e < i);
                if (s) {
                    this._updateClassName();
                }
            };
            u.toggle = function(t, e) {
                t += "";
                var i = this.contains(t), n = i ? e !== true && "remove" : e !== false && "add";
                if (n) {
                    this[n](t);
                }
                if (e === true || e === false) {
                    return e;
                } else {
                    return !i;
                }
            };
            u.toString = function() {
                return this.join(" ");
            };
            if (s.defineProperty) {
                var h = {
                    get: f,
                    enumerable: true,
                    configurable: true
                };
                try {
                    s.defineProperty(n, e, h);
                } catch (d) {
                    if (d.number === -2146823252) {
                        h.enumerable = false;
                        s.defineProperty(n, e, h);
                    }
                }
            } else if (s[i].__defineGetter__) {
                n.__defineGetter__(e, f);
            }
        })(self);
    } else {
        (function() {
            "use strict";
            var t = document.createElement("_");
            t.classList.add("c1", "c2");
            if (!t.classList.contains("c2")) {
                var e = function(t) {
                    var e = DOMTokenList.prototype[t];
                    DOMTokenList.prototype[t] = function(t) {
                        var i, n = arguments.length;
                        for (i = 0; i < n; i++) {
                            t = arguments[i];
                            e.call(this, t);
                        }
                    };
                };
                e("add");
                e("remove");
            }
            t.classList.toggle("c3", false);
            if (t.classList.contains("c3")) {
                var i = DOMTokenList.prototype.toggle;
                DOMTokenList.prototype.toggle = function(t, e) {
                    if (1 in arguments && !this.contains(t) === !e) {
                        return e;
                    } else {
                        return i.call(this, t);
                    }
                };
            }
            t = null;
        })();
    }
}

Element.prototype.hide = function() {
    this.classList.add("hide");
};

Element.prototype.show = function() {
    this.classList.remove("hide");
};

Element.prototype.addEvent = function(event, callback) {
    this.addEventListener(event, callback.bind(temple.banner));
};

Element.prototype.find = function(selector) {
    return $(selector, this);
};

NodeList.prototype.each = Array.prototype.forEach;

Object.defineProperty(Array.prototype, "shuffle", {
    enumerable: false,
    value: function() {
        var i = this.length;
        while (i) {
            var j = Math.floor(Math.random() * i);
            var t = this[--i];
            this[i] = this[j];
            this[j] = t;
        }
        return this;
    }
});

String.prototype.timeFormat = function() {
    var sn = parseInt(this, 10);
    var h = Math.floor(sn / 3600);
    var m = Math.floor((sn - h * 3600) / 60);
    var s = sn - h * 3600 - m * 60;
    if (m < 10) {
        m = m;
    }
    if (s < 10) {
        s = "0" + s;
    }
    var t = (m || 0) + ":" + (s || "00");
    return t;
};

String.prototype.ucfirst = function() {
    return this.charAt(0).toUpperCase() + this.slice(1);
};

Function.prototype.delay = function(a) {
    var b = [].slice.call(arguments, 1), c = this;
    return setTimeout(function() {
        c.apply(void 0, b);
    }, 1e3 * a);
};

var temple = new Temple(typeof temple != "undefined" ? temple.config : null);

window.addEventListener("load", temple.create.bind(temple));

function Temple(config) {
    this.type = "Standalone";
    this.version = "2.0.7", this.color = "#ff0088", this.isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent), 
    this.isiOS = /iPad|iPhone|iPod/.test(navigator.userAgent), this.isiOS9up = this.isiOS && navigator.appVersion.match(/OS (\d+)_(\d+)_?(\d+)?/)[1] > 9, 
    this.isiPad = /iPad/.test(navigator.userAgent), this.isSafari = /^((?!chrome|android).)*safari/i.test(navigator.userAgent), 
    this.core = {}, this.config = config, this.platforms = {}, this.templates = {}, 
    this.modules = {};
    this.isLive = function() {
        if (!this.config) return window.location.hostname != "localhost";
        if (!this.config.localhost) return window.location.hostname != "localhost";
        var live = window.location.hostname != "localhost";
        for (var i = 0; i < this.config.localhost.length; i++) {
            if (window.location.hostname == this.config.localhost[i]) {
                return false;
            }
        }
        return live;
    }();
    this.isAutoplayAvailable = function() {
        if (!this.isMobile) return true;
        if (!this.isiOS) {
            return true;
        } else if (this.isSafari) {
            if (this.isiPad) var os = Number(navigator.userAgent.split("iPad")[1].split(" ")[3].replace("_", ".")); else var os = navigator.userAgent.split("iPhone OS ")[1].split(" ")[0].split("_")[0];
            if (os >= 10) return true; else return false;
        } else {
            return false;
        }
    };
    this.utils = function() {
        var tracker = function(t) {
            temple.utils.debug("Tracker: " + t, "green");
        };
        var getQueryVar = function(v) {
            var q = window.location.search.substring(1);
            var vs = q.split("&");
            for (var i = 0; i < vs.length; i++) {
                var p = vs[i].split("=");
                if (p[0] == v) {
                    return p[1];
                }
            }
            return false;
        };
        var loadScript = function(u, c, e) {
            if (typeof u == "string") u = [ u ];
            t = 0;
            if (!u.length) {
                c();
                return;
            }
            var loader = function(sc) {
                var s = document.createElement("script");
                s.async = true;
                s.type = "text/javascript", s.readyState ? s.onreadystatechange = function() {
                    ("loaded" == s.readyState || "complete" == s.readyState) && (s.onreadystatechange = null, 
                    c && c());
                } : (s.onload = function(e) {
                    t++;
                    t == u.length ? c && c(e) : loader(u[t]);
                }, s.onerror = function() {
                    temple.utils.debug('ERROR LOADING SCRIPT "' + u + '"'), e && e();
                }), s.src = sc, document.body.appendChild(s);
            };
            loader(u[0]);
        };
        var loadJSON = function(u, c, e, nt) {
            if (typeof u == "string") u = [ u ];
            var t = 0;
            var comp = c;
            var obs = [];
            var data = [];
            c = function(o) {
                data[o] = nt === true ? obs[o].responseText : JSON.parse(obs[o].responseText);
                t++;
                if (t == u.length) {
                    if (data.length == 1) data = data[0];
                    comp.call(temple.banner, data);
                }
            };
            var xobj = [];
            for (var i = 0; i < u.length; i++) {
                xobj[i] = new XMLHttpRequest();
                xobj[i].i = i;
                obs.push(xobj[i]);
                xobj[i].overrideMimeType("application/json");
                xobj[i].open("GET", u[i], !0);
                xobj[i].onreadystatechange = function(e) {
                    x = e.currentTarget;
                    4 == x.readyState && "404" == x.status && (temple.utils.debug("No json found", "#ff0000"), 
                    e && e.call(temple.banner)), 4 == x.readyState && "200" == x.status && c && c(this.i);
                }, xobj[i].send(null);
            }
            if (!u.length) comp.call(temple.banner);
        };
        var loadImage = function(u, c, e) {
            if (typeof u == "string") u = [ u ];
            var t = 0;
            var imgs = [];
            for (var i = 0; i < u.length; i++) {
                var im = new Image();
                im.onload = function(e) {
                    imgs.push(this);
                    t++;
                    if (t == u.length) c && c(imgs, e);
                };
                im.onerror = e;
                im.src = u[i];
            }
        };
        var createStyle = function(n, r) {
            n = n != "banner" ? "#banner " + n : n;
            if (!temple.stylesheet) {
                temple.stylesheet = document.createElement("style"), temple.stylesheet.type = "text/css";
                var head = document.getElementsByTagName("head")[0];
                head.insertBefore(temple.stylesheet, head.firstChild);
            }
            (temple.stylesheet.sheet || {}).insertRule ? temple.stylesheet.sheet.insertRule(n + "{" + r + "}", 0) : (temple.stylesheet.styleSheet || temple.stylesheet.sheet).addRule(n, r);
        };
        var debug = function(e, c, v) {
            if (console.debug && (!temple.isLive || temple.config.debug === true)) {
                console.debug("%c[" + temple.type + "]%s", "font-weight:bold;color:" + (typeof c == "string" ? c : temple.color) + ";", " " + (v || temple.version), ":", e || "", typeof c != "string" && typeof c != "undefined" ? c : "");
            }
        };
        var fitText = function(t) {
            TweenMax.set(t, {
                clearProps: "fontSize, lineHeight"
            });
            var p = t.parentElement;
            var s = Number(window.getComputedStyle(p, null).getPropertyValue("font-size").replace("px", ""));
            if (t.offsetHeight > p.offsetHeight || t.offsetWidth > p.offsetWidth) {
                while (t.offsetHeight > p.offsetHeight || t.offsetWidth > p.offsetWidth) {
                    s -= .2;
                    t.style.fontSize = s + "px";
                    t.style.lineHeight = s + 1 + "px";
                }
            }
        };
        var validURL = function(str) {
            var pattern = new RegExp("^(https?:\\/\\/)?" + "((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.?)+[a-z]{2,}|" + "((\\d{1,3}\\.){3}\\d{1,3}))" + "(\\:\\d+)?(\\/[-a-z\\d%_.~+]*)*" + "(\\?[;&a-z\\d%_.~+=-]*)?" + "(\\#[-a-z\\d_]*)?$", "i");
            return pattern.test(str);
        };
        var findElements = function(e, styles) {
            if (styles) {
                var obj = {};
                obj.all = [];
                findElement(e, styles);
            } else {
                var obj = [];
                findElement(e);
            }
            function findElement(e, styles) {
                if (e && e.childNodes && e.childNodes.length > 0) {
                    for (var i = 0; i < e.childNodes.length; i++) {
                        var child = e.childNodes[i];
                        if (child.type == "image/svg+xml" || [ "DIV", "SPAN", "IMG", "CANVAS", "SVG", "CIRCLE", "PATH" ].indexOf(child.nodeName.toUpperCase()) != -1) {
                            if (child.id || child.className) {
                                if (styles) {
                                    styles = typeof styles == "string" ? [ styles ] : styles;
                                    for (var j = 0; j < styles.length; j++) {
                                        if (!obj[styles[j]]) {
                                            obj[styles[j]] = [];
                                        }
                                        if (child.id && obj[styles[j]].indexOf(child) == -1) {
                                            var val = getStyleRuleValue("." + styles[j], "#" + child.id);
                                            if (val) {
                                                obj[styles[j]].push(child);
                                            }
                                        }
                                        var c = typeof child.className == "object" ? String(child.className.baseVal).split(" ") : String(child.className).split(" ");
                                        for (var k = 0; k < c.length; k++) {
                                            if (c[k] && obj[styles[j]].indexOf(child) == -1) {
                                                var val = getStyleRuleValue("." + styles[j], "." + c[k]);
                                                if (val) {
                                                    obj[styles[j]].push(child);
                                                }
                                            }
                                        }
                                    }
                                    obj.all.push(child);
                                    findElement(child, styles);
                                } else {
                                    obj.push(child);
                                    findElement(child);
                                }
                            }
                        }
                    }
                }
            }
            function getStyleRuleValue(style, selector, sheet) {
                var sheets = typeof sheet !== "undefined" ? [ sheet ] : document.styleSheets;
                var ar = [];
                for (var i = 0, l = sheets.length; i < l; i++) {
                    var sheet = sheets[i];
                    if (!sheet.cssRules) continue;
                    for (var j = 0, k = sheet.cssRules.length; j < k; j++) {
                        var rule = sheet.cssRules[j];
                        if (rule.selectorText) {
                            if (rule.selectorText.indexOf(selector) != -1 && rule.selectorText.indexOf(style) != -1) {
                                var all = rule.selectorText.substring(0, rule.selectorText.indexOf(style)).split(".");
                                var node = all[all.length - 1];
                                return node;
                            }
                        }
                    }
                }
                return;
            }
            return obj;
        };
        return {
            tracker: function(v, e) {
                return tracker(v, e);
            },
            getQueryVar: function(v) {
                return getQueryVar(v);
            },
            loadScript: function(u, c, e) {
                loadScript(u, c, e);
            },
            loadJSON: function(u, c, e, nt) {
                loadJSON(u, c, e, nt);
            },
            loadImage: function(u, c, e) {
                loadImage(u, c, e);
            },
            debug: function(e, c, v) {
                debug(e, c, v);
            },
            createStyle: function(n, r) {
                createStyle(n, r);
            },
            fitText: function(t) {
                fitText(t);
            },
            findElements: function(e, styles) {
                return findElements(e, styles);
            },
            validURL: function(u) {
                return validURL(u);
            }
        };
    }();
    this.create = function() {
        var config = document.body.getAttribute("data-config") || "config.json";
        config = config.replace(".json", "");
        config = temple.utils.getQueryVar("c") && !this.isLive ? config + "_" + temple.utils.getQueryVar("c").replace("config_", "") + ".json" : config + ".json";
        if (temple.config) config = [];
        temple.utils.loadJSON(config, function(json) {
            this.config = json || temple.config;
            var scripts = [];
            var m = this.config.modules || [];
            if (m.length) {
                scripts.push(this.config.modules[0]);
            }
            temple.utils.loadScript(scripts, function(e) {
                if (temple.Banner) temple.banner = new temple.Banner();
            }.bind(this));
        }.bind(this));
    };
    this.events = {
        READY: "ready",
        SHOW: "show",
        CORE_READY: "core_ready",
        MODULE_READY: "module_ready",
        EXIT: "exit"
    };
}

temple.core.EventDispatcher = function() {
    function EventDispatcher() {}
    EventDispatcher.prototype.dispatchEvent = function(event, args) {
        if (!arguments[1]) arguments[1] = this;
        this._events = this._events || [];
        if (this._events[event]) {
            var listeners = this._events[event], len = listeners.length;
            while (len--) {
                temple.utils.debug("Event <" + event + "> " + (arguments[1].target ? arguments[1].target.constructor.name : arguments[1].constructor.name), "black");
                if (!args) args = {};
                if (!args.target) args.target = this;
                if (!listeners[len]._one) {
                    var f = listeners.splice(len, 1);
                    f[0](args);
                } else {
                    listeners[len](args);
                }
            }
            return true;
        }
        return false;
    };
    EventDispatcher.prototype.addEventListener = function(event, callback, _one) {
        callback._one = _one != undefined ? _one : true;
        this._events = this._events || [];
        this._events[event] = this._events[event] || [];
        if (this._events[event]) {
            this._events[event].push(callback);
        }
    };
    EventDispatcher.prototype.removeEventListener = function(event) {
        if (this._events[event]) {
            delete this._events[event];
        }
    };
    return EventDispatcher;
}();

temple.core.Module = function(_super) {
    __extends(Module, _super);
    function Module() {}
    Module.prototype._moduleReady = function() {
        temple.utils.debug("Module << " + this.constructor.name + " >>", this.color || "Tomato");
        this.dispatchEvent(temple.events.MODULE_READY);
    };
    Module.prototype.done = function() {
        setTimeout(this._moduleReady.bind(this), 50);
    };
    return Module;
}(temple.core.EventDispatcher);

temple.core.Core = function(_super) {
    __extends(Core, _super);
    function Core() {
        this._initCore();
    }
    Core.prototype.exit = function(url) {
        window.open(url || this.defaultExitURL, "_blank");
        this.dispatchEvent(temple.events.EXIT);
    };
    Core.prototype.chain = function(e) {
        try {
            e.prototype;
        } catch (err) {
            console.error("Module not loaded. Please add it to your config.");
            console.error("Available modules > ", temple.modules);
            return;
        }
        if (!this._chained) {
            this._chained = [];
            this._chained.push({
                m: e,
                a: arguments[1],
                c: arguments[2]
            });
            setTimeout(this._runChain.bind(this), 1);
        } else {
            this._chained.push({
                m: e,
                a: arguments[1],
                c: arguments[2]
            });
        }
        return this;
    };
    Core.prototype._politeLoads = function(c) {
        var loads = document.querySelectorAll("[multilingual], [polite]"), svgs = document.querySelectorAll("[svg]"), t = 0, t2 = 0, _s = [];
        function onload(e, img) {
            if (loads[t].nodeName == "DIV") {
                loads[t].style.backgroundImage = "url('" + loads[t].ml + loads[t].getAttribute("data-src") + "')";
                loads[t].style.width = img.width + "px";
                loads[t].style.height = img.height + "px";
            }
            t++;
            if (t + t2 == loads.length + svgs.length) if (c) setTimeout(c.call(this), 10);
        }
        for (var i = 0; i < loads.length; i++) {
            loads[i].ml = loads[i].hasAttribute("multilingual") || "";
            if (loads[i].ml === true) loads[i].ml = "img/" + this.config.language + "/";
            if (loads[i].nodeName == "DIV") {
                temple.utils.loadImage(loads[i].ml + loads[i].getAttribute("data-src"), onload.bind(this));
            } else {
                loads[i].onload = onload.bind(this, loads[i]);
                loads[i].src = loads[i].ml + loads[i].getAttribute("data-src");
            }
        }
        for (i = 0; i < svgs.length; i++) {
            _s[i] = {
                xhr: new XMLHttpRequest(),
                el: svgs[i]
            };
            _s[i].xhr.id = i;
            _s[i].xhr.onload = function(e) {
                var r = e.currentTarget.responseXML.documentElement;
                r.setAttribute("class", _s[e.currentTarget.id].el.getAttribute("class"));
                var id = _s[e.currentTarget.id].el.getAttribute("id");
                r.setAttribute("id", id);
                _s[e.currentTarget.id].el.parentNode.replaceChild(r, _s[e.currentTarget.id].el);
                window[id] = r;
                t2++;
                if (t + t2 == loads.length + svgs.length) if (c) setTimeout(c.call(this), 10);
            }.bind(this);
            _s[i].xhr.open("GET", svgs[i].getAttribute("data-src"), !0);
            _s[i].xhr.overrideMimeType("image/svg+xml");
            _s[i].xhr.send("");
        }
        if (!loads.length && !svgs.length) if (c) setTimeout(c.call(this), 10);
    };
    Core.prototype._initCore = function() {
        this.config = temple.config;
        temple.utils.debug(temple.type + " Platform");
        this._pageReady();
    };
    Core.prototype._pageReady = function() {
        this._bannerInit();
    };
    Core.prototype._bannerInit = function() {
        temple.utils.createStyle("#banner", "position:relative;overflow:hidden;background-color:#000;color:#fff;width:" + (temple.config.size.width ? temple.config.size.width + "px;height:" : "auto;height:") + (temple.config.size.height ? temple.config.size.height + "px;" : "auto;"));
        temple.utils.createStyle(".bannerClick", "position:absolute;top:0;left:0;width:100%;height:100%;cursor:pointer;background:url(data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7);");
        this.dispatchEvent(temple.events.CORE_READY);
    };
    Core.prototype._chainLoaded = function(e) {
        if (this._chained[0].c) this._chained[0].c.call(this);
        this._chained.splice(0, 1);
        this._runChain();
    };
    Core.prototype.async = function() {
        arguments.callee.caller.async = true;
        return function() {
            this._chainLoaded();
        }.bind(this);
    };
    Core.prototype._runChain = function(e) {
        if (!this._chained[0]) return;
        if (this._chained[0].m.prototype.__proto__.constructor != temple.core.Module) {
            this._chained[0].m.call(this, this._chained[0].a);
            if (!this._chained[0].m.async) this._chainLoaded();
            return;
        }
        var name = this._chained[0].m.name || this._chained[0].m.toString().match(/^function\s*([^\s(]+)/)[1];
        var moduleName = name.charAt(0).toLowerCase() + name.slice(1);
        var listName = moduleName;
        this[listName + "List"] = this[listName + "List"] || [];
        if (this[moduleName]) {
            var t = 2;
            var tempName = moduleName;
            tempName = moduleName + t;
            while (this[tempName]) {
                t++;
                tempName = moduleName + t;
            }
            moduleName = tempName;
        }
        this[moduleName] = new this._chained[0].m(this._chained[0].a || this, this, t || 0);
        this[moduleName].addEventListener(temple.events.MODULE_READY, this._chainLoaded.bind(this));
        this[listName + "List"].push(this[moduleName]);
    };
    return Core;
}(temple.core.EventDispatcher);

temple.platforms.doubleclick = {};

temple.platforms.doubleclick.Platform = function(_super) {
    __extends(Platform, _super);
    function Platform() {
        this.version = "1.0.3";
        this.defaultExitURL = "";
        this.exitURLs = [ "" ];
        temple.color = "#338e43";
        temple.type = "DoubleClick";
        temple.utils.tracker = this._tracker;
        this._platform = {
            _closeOverlay: function() {
                Enabler.close();
            }
        };
        if (typeof Enabler == "undefined") {
            temple.utils.loadScript("https://s0.2mdn.net/ads/studio/Enabler.js", this._initCore.bind(this));
        } else {
            this._initCore();
        }
    }
    Platform.prototype.setVideoTracking = function(player) {
        if (!studio.video) {
            Enabler.loadModule(studio.module.ModuleId.VIDEO, function() {
                this.setVideoTracking(player);
            }.bind(this));
            return;
        }
        if (player.playHistory) {
            studio.video.Reporter.detach(player.playHistory[player.playHistory.length - 1].id);
            studio.video.Reporter.attach(player.currentVideo.id, player._video);
        } else {
            studio.video.Reporter.attach(player.currentVideo.id, player._video);
        }
    };
    Platform.prototype.exit = function(url) {
        url = temple.utils.validURL(url) ? url : null;
        this.dispatchEvent(temple.events.EXIT, url || this.defaultExitURL);
        Enabler.exitOverride("Default Exit", url || this.defaultExitURL);
    };
    Platform.prototype._pageReady = function() {
        temple.isLive = Enabler.isServingInLiveEnvironment();
        if (typeof Enabler != "undefined") {
            if (Enabler.isInitialized()) this._pageLoaded(); else Enabler.addEventListener(studio.events.StudioEvent.INIT, this._pageLoaded.bind(this));
        } else {
            setTimeout(this.init.bind(this), 50);
        }
    };
    Platform.prototype._pageLoaded = function() {
        if (Enabler.isPageLoaded()) this._bannerInit(); else Enabler.addEventListener(studio.events.StudioEvent.PAGE_LOADED, this._bannerInit.bind(this));
    };
    Platform.prototype._tracker = function(title, repeat) {
        if (studio.video) return;
        if (repeat == undefined) repeat = true;
        this._trackedEvents = this._trackedEvents || [];
        if (this._trackedEvents.length > 19) return;
        if (repeat === false && this._trackedEvents.indexOf(title) >= 0) return;
        if (this._trackedEvents.indexOf(title) == -1) {
            this._trackedEvents.push(title);
        }
        Enabler.counter(title, repeat);
        temple.utils.debug("Tracked Event: " + (this._trackedEvents.indexOf(title) + 1) + " - " + title, "green");
    };
    Platform.prototype._addExitEvents = function() {
        Enabler.addEventListener(studio.events.StudioEvent.EXIT, this.onExit.bind(this));
    };
    return Platform;
}(temple.core.Core);

temple.platforms.Platform = temple.platforms.doubleclick.Platform;

temple.templates.MonetBanner = function(_super) {
    __extends(MonetBanner, _super);
    function MonetBanner() {
        _super.call(this, arguments[0]);
        temple.type = "Monet";
        temple.color = "#7b1df1";
        temple.utils.debug("Template <" + arguments.callee.name + ">");
    }
    MonetBanner.prototype.show = function(autoplay) {
        this.banner.classList.remove("hide");
        this.startAnimation();
        this.dispatchEvent(temple.events.SHOW);
    };
    MonetBanner.prototype.onBannerClick = function() {
        if (temple.utils.isiOS) {
            this.exit(this.monetData.rootAssets["url.Exit_URL_iOS"].url);
            return;
        }
        if (temple.utils.isMobile) {
            this.exit(this.monetData.rootAssets["url.Exit_URL_Android"].url);
            return;
        }
        this.exit(this.monetData.rootAssets["url.Exit_URL_Desktop"].url);
    };
    MonetBanner.prototype.startAnimation = function() {};
    MonetBanner.prototype.onTabChange = function() {};
    MonetBanner.prototype.onBackupImage = function() {};
    MonetBanner.prototype.onExit = function() {};
    MonetBanner.prototype.onOver = function(e) {};
    MonetBanner.prototype.onOut = function(e) {};
    MonetBanner.prototype.init = function(e) {};
    MonetBanner.prototype._bannerInit = function() {
        _super.prototype._bannerInit(this);
        this._ready();
    };
    MonetBanner.prototype._ready = function() {
        this.banner = document.getElementById("banner");
        this.bannerClick = document.querySelectorAll(".bannerClick");
        for (i = 0; i < this.bannerClick.length; i++) {
            this.bannerClick[i].addEventListener("click", this.onBannerClick.bind(this));
            this.bannerClick[i].addEventListener("mouseover", this.onOver.bind(this));
            this.bannerClick[i].addEventListener("mouseleave", this.onOut.bind(this));
        }
        this._addTabEvents();
        if (this._addExitEvents) this._addExitEvents(); else this.addEventListener(temple.events.EXIT, this.onExit.bind(this));
        this._politeLoads(function() {
            if (navigator.userAgent.toLowerCase().indexOf("firefox") > -1 && !window.innerHeight) {
                window.onresize = function() {
                    if (!temple.isVisible) {
                        temple.isVisible = true;
                        window.onresize = null;
                        this._webComponentReady();
                    }
                }.bind(this);
                if (!temple.isVisible) return;
            }
            this._webComponentReady();
        });
    };
    MonetBanner.prototype._webComponentReady = function() {
        this.monetComponent = document.querySelector("monet-integrator");
        if (this.monetComponent.hasAttribute("ready")) {
            this.initValidation();
            return;
        }
        this.monetComponent.addEventListener("ready", this.initValidation.bind(this));
    };
    MonetBanner.prototype.initValidation = function() {
        this.validateMonetData().then(function(data) {
            this.monetData = data;
            if (this.initDynamicComponents) this.initDynamicComponents();
            this.setImpressionLogging();
            this.dispatchEvent(temple.events.READY);
            this.init();
        }.bind(this));
    };
    MonetBanner.prototype.validateMonetData = function() {
        return new Promise(function(resolve, reject) {
            this.monetComponent.getMonetData().then(function(data) {
                if (!data.isBackupData) {
                    this.getBackupMonetData().then(function(backupData) {
                        for (var i in backupData.rootAssets) {
                            if (!data.rootAssets[i]) {
                                this.monetComponent.logEvent("MONET_DATA_VALIDATION_ERROR", {
                                    details: "Key `" + i + "` not found in Monet data; using backup data."
                                });
                                resolve(backupData);
                                return;
                            }
                        }
                        resolve(data);
                    }.bind(this));
                } else {
                    resolve(data);
                }
            }.bind(this));
        }.bind(this));
    };
    MonetBanner.prototype.getBackupMonetData = function() {
        return new Promise(function(resolve, reject) {
            temple.utils.loadJSON("backup.json", function(data) {
                resolve(data);
            }, reject);
        }.bind(this));
    };
    MonetBanner.prototype.setImpressionLogging = function() {
        this.impressionLoggingArray = this.monetData.assetGroups.length > 1 ? [ "MULTI_TITLE" ] : [ "SINGLE_TITLE" ];
        if (temple.config.monet.title_type) this.impressionLoggingArray = [ temple.config.monet.title_type ];
        if (temple.events.EXPAND) {
            this.impressionLoggingArray.push("EXPANDING");
        }
        var video = document.querySelectorAll("netflix-video");
        if (video.length) {
            var autoplay = false;
            for (var i = 0; i < video.length; i++) {
                if (video[i].hasAttribute("autoplay")) autoplay = true;
            }
            this.impressionType = "RICH_MEDIA";
            this.impressionLoggingArray.push("VIDEO");
            if (autoplay) {
                this.impressionLoggingArray.push("AUTOPLAY");
            }
        } else {
            this.impressionType = "STANDARD";
        }
        if (temple.config.monet.skills) {
            this.impressionLoggingArray = this.impressionLoggingArray.concat(temple.config.monet.skills);
        }
        Monet.logEvent("MONET_IMPRESSION", {
            type: this.impressionType,
            skills: this.impressionLoggingArray
        });
        this.banner.addEventListener("click", this.trackMonetEvent_CLICK.bind(this));
        this.addEventListener(temple.events.EXIT, this.trackMonetEvent_EXIT.bind(this));
        if (temple.config.expandable) {
            if (!this.banner.lightboxModule) {
                this.banner.expandingModule.addEventListener(temple.events.EXPAND, this.trackMonetExpandableEvent_EXPAND.bind(this));
                this.banner.expandingModule.addEventListener(temple.events.COLLAPSE, this.trackMonetExpandableEvent_COLLAPSE.bind(this));
            } else {
                this.banner.lightboxModule.addEventListener(temple.events.EXPAND, this.trackMonetExpandableEvent_EXPAND.bind(this));
                this.banner.lightboxModule.addEventListener(temple.events.COLLAPSE, this.trackMonetExpandableEvent_COLLAPSE.bind(this));
            }
        }
    };
    MonetBanner.prototype.trackMonetEvent_CLICK = function(event) {
        var t = String(event.target);
        Monet.logEvent("CLICK", {
            src: t,
            coords: {
                x: event.clientX,
                y: event.clientY
            }
        });
    };
    MonetBanner.prototype.trackMonetEvent_EXIT = function(event) {
        Monet.logEvent("AD_EXIT", {
            url: event.url
        });
    };
    MonetBanner.prototype.trackMonetExpandableEvent_EXPAND = function(event) {
        Monet.logEvent("UNIT_RESIZE", {
            type: "expand",
            Size: {
                width: temple.config.expandable.width,
                height: temple.config.expandable.height
            }
        });
    };
    MonetBanner.prototype.trackMonetExpandableEvent_COLLAPSE = function(event) {
        Monet.logEvent("UNIT_RESIZE", {
            type: "collapse",
            Size: {
                width: temple.config.size.width,
                height: temple.config.size.height
            }
        });
    };
    MonetBanner.prototype._addTabEvents = function() {
        this._isHidden = false;
        if ("hidden" in document) {
            document.addEventListener("visibilitychange", this.onTabChange.bind(this));
        } else if ((this._isHidden = "mozHidden") in document) {
            document.addEventListener("mozvisibilitychange", this.onTabChange.bind(this));
        } else if ((this._isHidden = "webkitHidden") in document) {
            document.addEventListener("webkitvisibilitychange", this.onTabChange.bind(this));
        } else if ((this._isHidden = "msHidden") in document) {
            document.addEventListener("msvisibilitychange", this.onTabChange.bind(this));
        } else if ("onfocusin" in document) {
            document.onfocusin = document.onfocusout = this.onTabChange.bind(this);
        } else {
            window.onpageshow = window.onpagehide = window.onfocus = window.onblur = this.onTabChange.bind(this);
        }
    };
    return MonetBanner;
}(temple.platforms.Platform || temple.core.Core);

temple.Template = temple.templates.MonetBanner;

temple.BlackMirrorBanners = function(_super) {
    __extends(BlackMirrorBanners, _super);
    function BlackMirrorBanners() {
        _super.call(this, arguments[0]);
    }
    BlackMirrorBanners.prototype.setupTimeline = function() {};
    BlackMirrorBanners.prototype.init = function() {
        if (!temple.isMobile) {
            $(".mobilePlayButton").hide();
        } else {
            TweenMax.set(".mobilePlayButton", {
                x: -50,
                autoalpha: 0
            });
        }
        this.allowMousePosition = false;
        this.bannerWidth = this.config.size.width;
        this.bannerHeight = this.config.size.height;
        this.horizontalMousePosition = 0;
        this.verticalMousePosition = 0;
        this.horizontalMouseDirection;
        this.verticalMouseDirection;
        this.setupTimeline();
        $("#ribbonComponent").addEventListener("leftPillarComplete", function() {
            if (temple.isMobile) {
                this.startArtAnimation();
            } else {
                $("#supercutComponent").play();
                $("#supercutLogoComponent").progress(1);
                TweenMax.to($(".supercutOverlay"), .3, {
                    opacity: 1,
                    ease: Quad.easeOut
                });
            }
        }.bind(this));
        $("#ribbonComponent").addEventListener("complete", function() {
            $("#ribbonComponent").hide();
            $(".ribbonClick").hide();
        });
        $("#supercutComponent").addEventListener("video-complete", this.startArtAnimation.bind(this));
        $("#supercutComponent").addEventListener("video-close", this.startArtAnimation.bind(this));
        $("#supercutComponent").addEventListener("video-click", this.onBannerClick.bind(this));
        $("#supercutComponent").addEventListener("video-time", this.onSupercutTime.bind(this));
        $(".mobilePlayButton").addEventListener("click", this.playTrailer.bind(this));
        $("#trailerPlay").addEventListener("click", this.playTrailer.bind(this));
        $("#trailerPlay").addEventListener("mouseover", this.overPlayTrailer.bind(this));
        $("#trailerPlay").addEventListener("mouseout", this.outPlayTrailer.bind(this));
        $("#trailerComponent").addEventListener("video-complete", this.reverseTrailerAnimation.bind(this));
        $("#trailerComponent").addEventListener("video-close", this.reverseTrailerAnimation.bind(this));
        $("#trailerComponent").addEventListener("video-click", this.onBannerClick.bind(this));
        var ctaLocale = Monet.getComponentLocale("text.CTA").substr(0, 2);
        $(".copyContainer").classList.add(ctaLocale);
        if (ctaLocale == "ar" || ctaLocale == "he") {
            $("#ctaComponent").setAttribute("rtl", true);
        }
        $("#pedigreeComponent").classList.add(ctaLocale);
        $("#trailerPlay").hide();
        this.show();
    };
    BlackMirrorBanners.prototype.startAnimation = function() {
        $("#ribbonComponent").play();
    };
    BlackMirrorBanners.prototype.startArtAnimation = function() {
        this.mainTimeline.play();
        $(".supercutOverlay").hide();
        $("#ctaComponent").resize();
    };
    BlackMirrorBanners.prototype.onSupercutTime = function(e) {
        var p = Math.ceil(e.detail.currentTime / e.detail.duration * 100);
        if (p > 3 && !this.supercutStart) {
            this.supercutStart = true;
            $("#supercutLogoComponent").reverse();
        }
        if (p > 75 && !this.supercutEnding) {
            this.supercutEnding = true;
            $("#supercutLogoComponent").play();
        }
    };
    BlackMirrorBanners.prototype.playTrailer = function() {
        this.allowMousePosition = false;
        this.explodeTL.timeScale(7).reverse();
        $("#trailerPlay").hide();
        if (temple.isMobile) {
            TweenMax.to(".mobilePlayButton", .5, {
                x: -50,
                ease: Power2.easeOut
            });
        }
        this.trailerInstance.play();
        setTimeout(function() {
            $("#trailerComponent").play();
        }, 500);
    };
    BlackMirrorBanners.prototype.reverseTrailerAnimation = function() {
        this.trailerInstance.reverse();
        this.playExplode();
        $("#trailerPlay").show();
        if (temple.isMobile) {
            TweenMax.to(".mobilePlayButton", .5, {
                x: 0,
                ease: Power2.easeOut
            });
        }
        this.spriteEmojiTL.yoyo(false).pause(0);
    };
    BlackMirrorBanners.prototype.overPlayTrailer = function() {
        this.spriteEmojiTL.yoyo(false).repeat(0).timeScale(6).play("start");
    };
    BlackMirrorBanners.prototype.outPlayTrailer = function() {
        this.spriteEmojiTL.yoyo(false).repeat(0).reverse();
    };
    BlackMirrorBanners.prototype.yoyoEmojiPlayer = function() {
        this.spriteEmojiTL.yoyo(true).repeat(5).timeScale(7).play();
    };
    BlackMirrorBanners.prototype.onOver = function() {
        if (!temple.isMobile) $("#ctaComponent").mouseover();
    };
    BlackMirrorBanners.prototype.onOut = function() {
        if (!temple.isMobile) $("#ctaComponent").mouseout();
    };
    BlackMirrorBanners.prototype.switchAllowMouse = function(_value) {
        this.allowMousePosition = _value;
    };
    BlackMirrorBanners.prototype.playExplode = function() {
        this.explodeTL.timeScale(5).play();
    };
    BlackMirrorBanners.prototype.reverseExplode = function() {
        this.explodeTL.timeScale(5).reverse();
    };
    BlackMirrorBanners.prototype.playTTAnimation = function() {
        this.introTreatmentTL.timeScale(5).play("start+=1");
    };
    BlackMirrorBanners.prototype.onExit = function() {
        if ($("#supercutComponent").playing) $("#supercutComponent").close();
        if ($("#trailerComponent").playing) $("#trailerComponent").close();
        $("#ribbonComponent").progress(1, true);
        $("#ribbonComponent").hide();
        $(".ribbonClick").hide();
        $("#trailerPlay").show();
        this.mainTimeline.pause("endframe", false);
        TweenMax.killDelayedCallsTo(this.playTrailer);
        this.spriteEmojiTL.yoyo(false).pause(0);
        if (temple.isMobile) {
            TweenMax.to(".mobilePlayButton", .5, {
                x: 0,
                ease: Power2.easeOut
            });
        }
        setTimeout(function() {
            $("#ctaComponent").mouseout();
        }, 1500);
    };
    BlackMirrorBanners.prototype.spriteAnimation = function(_div, _timeline, _spriteAnimationWidth, _spriteAnimationHeight, _spriteAnimationColumns, _spriteAnimationRows, _autoPlay, _spriteAnimationSpeed, _repeat) {
        if (!_repeat) {
            _repeat = 0;
        }
        this.introXMove = (_spriteAnimationWidth * _spriteAnimationColumns - _spriteAnimationWidth) * -1;
        for (i = 0; i < _spriteAnimationRows - 1; i++) {
            _timeline.to(_div, 1, {
                x: this.introXMove,
                ease: SteppedEase.config(_spriteAnimationColumns - 1)
            }).set(_div, {
                x: 0,
                y: "-=" + _spriteAnimationHeight
            });
        }
        _timeline.to(_div, 1, {
            x: this.introXMove,
            ease: SteppedEase.config(_spriteAnimationColumns - 1)
        });
        if (_autoPlay) _timeline.timeScale(_spriteAnimationSpeed).repeat(_repeat).play();
    };
    BlackMirrorBanners.prototype.checkMousePosition = function(e) {
        if (this.allowMousePosition) {
            var mousePosX = e.clientX - this.bannerWidth;
            var mousePosY = e.clientY - this.bannerHeight;
            var moveX;
            var moveY;
            if (mousePosX > this.horizontalMousePosition) {
                this.horizontalMouseDirection = "right";
            } else {
                this.horizontalMouseDirection = "left";
            }
            if (mousePosY > this.verticalMousePosition) {
                this.verticalMouseDirection = "up";
            } else {
                this.verticalMouseDirection = "down";
            }
            if (mousePosX > this.bannerWidth / 2) {
                moveX = 0;
                if (this.horizontalMousePosition == "right") {
                    moveX++;
                } else {
                    moveX--;
                }
                _posX = mousePosX - this.bannerWidth / 2 + moveX;
            } else if (mousePosX < this.bannerWidth / 2) {
                moveX = 0;
                if (this.horizontalMousePosition == "right") {
                    moveX++;
                } else {
                    moveX--;
                }
                _posX = mousePosX - this.bannerWidth / 2 - moveX;
            }
            this.horizontalMousePosition = mousePosX;
            if (mousePosY > this.bannerHeight / 2) {
                moveY = 0;
                if (this.verticalMouseDirection == "up") {
                    moveY++;
                } else {
                    moveY--;
                }
                _posY = mousePosY - this.bannerHeight / 2 + moveY;
            } else if (mousePosY < this.bannerHeight / 2) {
                moveY = 0;
                if (this.verticalMouseDirection == "up") {
                    moveY++;
                } else {
                    moveY--;
                }
                _posY = mousePosY - this.bannerHeight / 2 - moveY;
            }
            this.verticalMousePosition = mousePosY;
            this.moveParallax(_posX, _posY);
        }
    };
    return BlackMirrorBanners;
}(temple.Template);

temple.Banner = function(_super) {
    __extends(banner, _super);
    function banner() {
        _super.call(this, arguments[0]);
    }
    banner.prototype.init = function() {
        var locale = Monet.getComponentLocale("text.Pedigree").substr(0, 2);
        $("#mainCopyComponent").classList.add(locale);
        $(".ctaContainer").classList.add(locale);
        $("#logoComponent").classList.add(locale);
        $(".ratingBug").classList.add(locale);
        if (!temple.isMobile) {
            $("#banner").addEventListener("mousemove", this.checkMousePosition.bind(this));
        }
        TweenMax.set(".logo_break_holder", {
            scale: 1
        });
        TweenMax.set(".emojiHolder", {
            scale: .5
        });
        _super.prototype.init.call(this);
    };
    banner.prototype.setupTimeline = function() {
        this.mainTimeline = new TimelineMax({
            paused: true,
            onComplete: this.switchAllowMouse.bind(this),
            onCompleteParams: [ true ]
        });
        this.explodeTL = new TimelineMax({
            paused: true
        });
        this.spriteEmojiTL = new TimelineMax({
            paused: true
        });
        this.introTreatmentTL = new TimelineMax({
            paused: true
        });
        this.trailerInstance = new TimelineMax({
            paused: true,
            onReverseComplete: this.switchAllowMouse.bind(this),
            onReverseCompleteParams: [ true ]
        });
        this.mainTimeline.addCallback(this.playTTAnimation.bind(this), "start").to(".keyartWrapper", .5, {
            opacity: 1
        }, "start").to(".emojiHolder", .4, {
            opacity: 1
        }, "start+=.8").addCallback(this.playExplode.bind(this), "start+=.8").from(".left_chunks", 2, {
            opacity: 0,
            y: 60,
            rotation: -20,
            transformOrigin: "50 bottom",
            scale: .4,
            ease: Power4.easeOut
        }, "start+=.8").from(".middle_chunks", 2, {
            opacity: 0,
            y: 40,
            rotation: 20,
            transformOrigin: "50% top",
            scale: .4,
            ease: Power4.easeOut
        }, "start+=.8").from(".right_chunks", 2, {
            opacity: 0,
            y: 40,
            rotation: 20,
            transformOrigin: "50% top",
            scale: .4,
            ease: Power4.easeOut
        }, "start+=.8").fromTo(".ratingBug", 2, {
            opacity: 0
        }, {
            opacity: 1,
            ease: Quad.easeOut
        }, "start+=1").fromTo(".shadow", 1, {
            opacity: 0
        }, {
            opacity: 1,
            ease: Quad.easeOut
        }, "start+=1").fromTo($("#pedigreeComponent"), 2, {
            opacity: 0
        }, {
            opacity: 1,
            ease: Quad.easeOut
        }, "start+=1").fromTo($("#mainCopyComponent"), 2, {
            opacity: 0
        }, {
            opacity: 1,
            ease: Quad.easeOut
        }, "start+=1").fromTo($("#logoComponent"), 1, {
            opacity: 0
        }, {
            opacity: 1,
            ease: Quad.easeOut
        }, "start+=1").addCallback($("#logoComponent").play.bind($("#logoComponent")), "start+=1.6").fromTo($(".ctaContainer"), 1, {
            width: 0
        }, {
            width: 90,
            ease: Quad.easeOut
        }, "start+=1.6").addCallback(this.yoyoEmojiPlayer.bind(this), "start+=2").addCallback($("#trailerPlay").show.bind($("#trailerPlay")), "start+=2");
        if (temple.isMobile) {
            this.mainTimeline.to(".mobilePlayButton", 1, {
                x: 0,
                autoalpha: 1,
                ease: Power2.easeOut
            }, "start+=5.5");
        }
        this.mainTimeline.addPause("endframe");
        this.trailerInstance.to([ "#trailerPlay", ".emojiHolder" ], .5, {
            autoAlpha: 0
        }, "start").to(".left_chunks", .5, {
            opacity: 0,
            y: 60,
            rotation: 20,
            transformOrigin: "50 bottom",
            scale: .4,
            ease: Power4.easeIn
        }, "start").to(".middle_chunks", .5, {
            opacity: 0,
            y: 40,
            rotation: -20,
            transformOrigin: "50% top",
            scale: .4,
            ease: Power4.easeIn
        }, "start").to(".right_chunks", .5, {
            opacity: 0,
            y: 40,
            rotation: -20,
            transformOrigin: "50% top",
            scale: .4,
            ease: Power4.easeIn
        }, "start");
        if (temple.isMobile) {
            this.mainTimeline.to(".mobilePlayButton", 1, {
                x: -50,
                autoalpha: 0,
                ease: Power2.easeOut
            }, "start");
        }
        this.mainTimeline.addPause("trailer");
        this.spriteAnimation($("#logo_break"), this.introTreatmentTL, 485, 125, 4, 7, false);
        this.spriteAnimation($("#explode"), this.explodeTL, 485, 250, 5, 4, false);
        this.spriteAnimation($("#emoji"), this.spriteEmojiTL, 150, 150, 5, 4, false);
    };
    banner.prototype.moveParallax = function(_posX, _posY) {
        TweenMax.to([ ".explode_holder", ".emojiHolder" ], .5, {
            x: _posX / 100 * -1,
            y: _posY / 100 * -1,
            rotation: .01,
            force3D: true
        });
        TweenMax.to([ ".logo_break_holder", "#pedigreeComponent" ], .5, {
            x: _posX / 100 * -1,
            y: _posY / 100 * -1,
            rotation: .01,
            force3D: true
        });
        TweenMax.to(".left_chunks", .5, {
            x: _posX / 20 * -1,
            y: _posY / 20 * -1,
            rotation: .01,
            force3D: true
        });
        TweenMax.to(".middle_chunks", .5, {
            x: _posX / 30 * -1,
            y: _posY / 30 * -1,
            rotation: .01,
            force3D: true
        });
        TweenMax.to(".right_chunks", .5, {
            x: _posX / 30 * -1,
            y: _posY / 30 * -1,
            rotation: .01,
            force3D: true
        });
    };
    return banner;
}(temple.BlackMirrorBanners);