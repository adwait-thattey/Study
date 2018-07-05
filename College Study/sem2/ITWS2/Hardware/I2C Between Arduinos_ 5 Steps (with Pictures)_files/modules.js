window.Utils = window.Utils || {};

!function(e) {
    function n() {}
    function t(e, n) {
        return function() {
            e.apply(n, arguments);
        };
    }
    function o(e) {
        if ("object" != typeof this) throw new TypeError("Promises must be constructed via new");
        if ("function" != typeof e) throw new TypeError("not a function");
        this._state = 0, this._handled = !1, this._value = void 0, this._deferreds = [], 
        s(e, this);
    }
    function i(e, n) {
        for (;3 === e._state; ) e = e._value;
        return 0 === e._state ? void e._deferreds.push(n) : (e._handled = !0, void o._immediateFn(function() {
            var t = 1 === e._state ? n.onFulfilled : n.onRejected;
            if (null === t) return void (1 === e._state ? r : u)(n.promise, e._value);
            var o;
            try {
                o = t(e._value);
            } catch (i) {
                return void u(n.promise, i);
            }
            r(n.promise, o);
        }));
    }
    function r(e, n) {
        try {
            if (n === e) throw new TypeError("A promise cannot be resolved with itself.");
            if (n && ("object" == typeof n || "function" == typeof n)) {
                var i = n.then;
                if (n instanceof o) return e._state = 3, e._value = n, void f(e);
                if ("function" == typeof i) return void s(t(i, n), e);
            }
            e._state = 1, e._value = n, f(e);
        } catch (r) {
            u(e, r);
        }
    }
    function u(e, n) {
        e._state = 2, e._value = n, f(e);
    }
    function f(e) {
        2 === e._state && 0 === e._deferreds.length && o._immediateFn(function() {
            e._handled || o._unhandledRejectionFn(e._value);
        });
        for (var n = 0, t = e._deferreds.length; n < t; n++) i(e, e._deferreds[n]);
        e._deferreds = null;
    }
    function c(e, n, t) {
        this.onFulfilled = "function" == typeof e ? e : null, this.onRejected = "function" == typeof n ? n : null, 
        this.promise = t;
    }
    function s(e, n) {
        var t = !1;
        try {
            e(function(e) {
                t || (t = !0, r(n, e));
            }, function(e) {
                t || (t = !0, u(n, e));
            });
        } catch (o) {
            if (t) return;
            t = !0, u(n, o);
        }
    }
    var a = setTimeout;
    o.prototype["catch"] = function(e) {
        return this.then(null, e);
    }, o.prototype.then = function(e, t) {
        var o = new this.constructor(n);
        return i(this, new c(e, t, o)), o;
    }, o.all = function(e) {
        var n = Array.prototype.slice.call(e);
        return new o(function(e, t) {
            function o(r, u) {
                try {
                    if (u && ("object" == typeof u || "function" == typeof u)) {
                        var f = u.then;
                        if ("function" == typeof f) return void f.call(u, function(e) {
                            o(r, e);
                        }, t);
                    }
                    n[r] = u, 0 === --i && e(n);
                } catch (c) {
                    t(c);
                }
            }
            if (0 === n.length) return e([]);
            for (var i = n.length, r = 0; r < n.length; r++) o(r, n[r]);
        });
    }, o.resolve = function(e) {
        return e && "object" == typeof e && e.constructor === o ? e : new o(function(n) {
            n(e);
        });
    }, o.reject = function(e) {
        return new o(function(n, t) {
            t(e);
        });
    }, o.race = function(e) {
        return new o(function(n, t) {
            for (var o = 0, i = e.length; o < i; o++) e[o].then(n, t);
        });
    }, o._immediateFn = "function" == typeof setImmediate && function(e) {
        setImmediate(e);
    } || function(e) {
        a(e, 0);
    }, o._unhandledRejectionFn = function(e) {
        "undefined" != typeof console && console && console.warn("Possible Unhandled Promise Rejection:", e);
    }, o._setImmediateFn = function(e) {
        o._immediateFn = e;
    }, o._setUnhandledRejectionFn = function(e) {
        o._unhandledRejectionFn = e;
    }, "undefined" != typeof module && module.exports ? module.exports = o : e.Promise || (e.Promise = o);
}(this);

(function() {
    if (typeof window.CustomEvent === "function") {
        return;
    }
    function CustomEvent(event, params) {
        params = params || {
            bubbles: false,
            cancelable: false,
            detail: void 0
        };
        var evt = document.createEvent("CustomEvent");
        evt.initCustomEvent(event, params.bubbles, params.cancelable, params.detail);
        return evt;
    }
    CustomEvent.prototype = window.Event.prototype;
    window.CustomEvent = CustomEvent;
})();

window.Utils = window.Utils || {};

Utils.isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);

Utils.isiOS = /iPad|iPhone|iPod/.test(navigator.userAgent);

Utils.isiOS9up = this.isiOS && navigator.appVersion.match(/OS (\d+)_(\d+)_?(\d+)?/)[1] > 9;

Utils.isiPad = /iPad/.test(navigator.userAgent);

Utils.isSafari = /^((?!chrome|android).)*safari/i.test(navigator.userAgent);

var ComponentAssets = new function() {
    var assets = [];
    this.add = function(path, src) {
        var asset = getAsset(path);
        if (asset) {
            asset.src = src || null;
        } else {
            assets.push({
                path: path,
                src: src || null
            });
        }
    };
    this.get = function(path) {
        var asset = getAsset(path);
        if (asset) {
            return asset.src || asset.path;
        } else {
            return path;
        }
    };
    function getAsset(path) {
        for (var i in assets) {
            if (assets[i].path == path) {
                return assets[i];
            }
        }
    }
}();

window.ComponentAssets = ComponentAssets;

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

window.Utils = window.Utils || {};

Utils.createStyle = function(nodeId, styles) {
    var id = nodeId + "-component-stylesheet";
    stylesheet = document.getElementById(id) || this.stylesheet;
    if (!stylesheet) {
        stylesheet = document.createElement("style");
        stylesheet.type = "text/css";
        stylesheet.id = id;
        this.appendChild(stylesheet);
    }
    var str = stylesheet.innerHTML;
    for (var i = 0; i < arguments.length - 1; i += 2) {
        var nameArg = arguments[i + 1];
        var space = " ";
        if (Array.isArray(nameArg)) {
            if (nameArg[1] === true) space = "";
            nameArg = nameArg[0];
        }
        var names = nameArg.replace(/\,\s+/g, ",");
        str += nodeId + space;
        str += names;
        str += " { " + (arguments[i + 2] || "") + " }\n";
    }
    stylesheet.innerHTML = str;
    this.stylesheet = stylesheet;
};

window.Utils = window.Utils || {};

Utils.SvgIcon = function(id, path, color) {
    var i = document.createElementNS("http://www.w3.org/2000/svg", "path");
    i.setAttributeNS(null, "d", path);
    i.setAttribute("data-original", path);
    if (color != undefined) {
        i.setAttribute("fill", color);
    }
    i.setAttribute("class", id || "");
    return i;
};

(function() {
    function chooseExitURL(desktopExitURL, iosExitURL, androidExitURL) {
        var exitURL = null;
        if (Utils.isMobile) {
            exitURL = Utils.isiOS ? iosExitURL : androidExitURL;
        }
        return exitURL || desktopExitURL;
    }
    function doHTTPRequest(url) {
        return new Promise(function(resolve, reject) {
            var xhr = new XMLHttpRequest();
            xhr.addEventListener("load", function() {
                if (xhr.status >= 200 && xhr.status < 300) {
                    log("info", "url loaded", url, xhr.response);
                    resolve(xhr.response);
                    return;
                }
                var errorMessage = "Failed to load " + url + " [" + xhr.status + "]" + xhr.responseText;
                log("error", errorMessage);
                reject(new Error(errorMessage));
            });
            xhr.addEventListener("error", function(errorEvent) {
                var message = "Error in loading " + url;
                log("error", message, errorEvent);
                reject(errorEvent.error || new Error(message));
            });
            xhr.open("GET", url);
            xhr.send();
        });
    }
    function listenForLoad(target) {
        return new Promise(function(resolve, reject) {
            var onLoad = null;
            var onError = null;
            var onDone = function() {
                target.removeEventListener("load", onLoad);
                target.removeEventListener("error", onError);
            };
            onLoad = function() {
                onDone();
                resolve(null);
            };
            onError = function(event) {
                onDone();
                reject(event.error);
            };
            target.addEventListener("load", onLoad);
            target.addEventListener("error", onError);
        });
    }
    function log(level) {
        if (!!window.Enabler && Enabler.isServingInLiveEnvironment() && level !== "error") {
            return;
        }
        console[level].apply(console, Array.prototype.slice.call(arguments, 1));
    }
    function getGWDDynamicContent(dynamicFeedSheetName) {
        var dynamicContent = {};
        var windowDynamicContent = window.devDynamicContent || window.dynamicContent;
        if (!windowDynamicContent) {
            return dynamicContent;
        }
        dynamicContent[dynamicFeedSheetName] = windowDynamicContent[dynamicFeedSheetName];
        return dynamicContent;
    }
    var ElementCreationObserver = function() {
        function elementMatchesSelector(element, selector) {
            if (element.nodeType !== Node.ELEMENT_NODE) {
                return false;
            }
            var matcher = element.matches || element.matchesSelector || element.mozMatchesSelector || element.msMatchesSelector || element.oMatchesSelector || element.webkitMatchesSelector;
            if (!matcher) {
                return false;
            }
            return matcher.call(element, selector);
        }
        function ElementCreationObserver() {
            this.mutationObserver = null;
        }
        ElementCreationObserver.prototype.startObserving = function(selectorToObserve, callback) {
            if (!window.MutationObserver || window.MutationObserver._isPolyfilled) {
                var monetElementObserverFunctionName = "monetElementObserver_" + "_" + Math.floor(Math.random() * 1e4);
                window[monetElementObserverFunctionName] = function() {
                    var matchingElements = Array.prototype.slice.call(document.querySelectorAll(selectorToObserve));
                    if (matchingElements.length > 0) {
                        callback(matchingElements);
                    }
                    window[monetElementObserverFunctionName] = null;
                };
                var scriptSource = "window." + monetElementObserverFunctionName + "();";
                var scriptBase64URI = "data:text/javascript;base64," + btoa(scriptSource);
                var triggerScript = document.createElement("script");
                triggerScript.setAttribute("type", "text/javascript");
                triggerScript.setAttribute("src", scriptBase64URI);
                setTimeout(function() {
                    document.head.appendChild(triggerScript);
                }, 0);
            } else {
                var config = {
                    attributes: false,
                    childList: true,
                    characterData: false,
                    subtree: true
                };
                this.mutationObserver = new MutationObserver(function(mutations) {
                    var matchedNodes = [];
                    mutations.forEach(function(mutationRecord) {
                        if (mutationRecord.type !== "childList") {
                            return;
                        }
                        var addedNodes = Array.prototype.slice.call(mutationRecord.addedNodes);
                        addedNodes.forEach(function(addedNode) {
                            if (addedNode.nodeType !== Node.ELEMENT_NODE) {
                                return;
                            }
                            if (elementMatchesSelector(addedNode, selectorToObserve)) {
                                matchedNodes.push(addedNode);
                            }
                            var subtreeMatches = addedNode.querySelectorAll(selectorToObserve);
                            Array.prototype.push.apply(matchedNodes, subtreeMatches);
                        });
                    });
                    if (matchedNodes.length > 0) {
                        callback(matchedNodes);
                    }
                });
                this.mutationObserver.observe(document, config);
            }
        };
        ElementCreationObserver.prototype.stopObserving = function() {
            if (!!this.mutationObserver) {
                this.mutationObserver.disconnect();
                this.mutationObserver = null;
            }
        };
        return ElementCreationObserver;
    }();
    var MonetLoader = function() {
        var MONET_SDK_URL = "https://ae.nflximg.net/monet/scripts/monet.min.js";
        var ENABLER_URL = "https://s0.2mdn.net/ads/studio/Enabler.js";
        var monetInitialized = false;
        var scriptURLToLoadPromise = {};
        function loadScript(scriptURL) {
            var script = document.createElement("script");
            var loadPromise = listenForLoad(script);
            script.setAttribute("type", "text/javascript");
            script.setAttribute("src", scriptURL);
            document.head.appendChild(script);
            return loadPromise;
        }
        function ensureExternalScriptExecuted(scriptURL) {
            var scriptPromise = scriptURLToLoadPromise[scriptURL];
            if (!scriptPromise) {
                scriptPromise = scriptURLToLoadPromise[scriptURL] = loadScript(scriptURL);
            }
            return scriptPromise;
        }
        function ensureMonetSDKInjected() {
            if (!!window.Monet) {
                return Promise.resolve();
            }
            return ensureExternalScriptExecuted(MONET_SDK_URL);
        }
        function ensureEnablerInjected() {
            if (!!window.Enabler) {
                return Promise.resolve();
            }
            return ensureExternalScriptExecuted(ENABLER_URL);
        }
        function ensureEnablerInitialized() {
            if (Enabler.isInitialized()) {
                return Promise.resolve();
            }
            return new Promise(function(resolve, reject) {
                Enabler.addEventListener(studio.events.StudioEvent.INIT, function() {
                    resolve();
                });
            });
        }
        function initializeMonet() {
            return ensureEnablerInjected().then(ensureMonetSDKInjected).then(ensureEnablerInitialized).then(function() {
                if (!monetInitialized) {
                    monetInitialized = true;
                    Monet.initialize(Enabler);
                }
                return Monet;
            });
        }
        function MonetLoader() {}
        MonetLoader.prototype.getInitialized = function() {
            return initializeMonet();
        };
        return MonetLoader;
    }();
    var MonetDataProvider = function() {
        var STATIC_BACKUP_LOCATION = "backup.json";
        var MONET_COMPONENT_TYPE_TO_VALUE_FIELD_NAME = {
            text: "text",
            number: "value",
            image: "url",
            video: "url",
            url: "url",
            bool: "value"
        };
        var MonetDataProviderDataType = {
            MONET: "MONET",
            GWD: "GWD"
        };
        function getMonetComponentValueFieldForComponentType(monetComponentType) {
            return MONET_COMPONENT_TYPE_TO_VALUE_FIELD_NAME[monetComponentType] || "value";
        }
        function convertMonetAssetsToGWDAssets(monetAssets, dynamicFeedSheetName) {
            var gwdData = {};
            Object.keys(monetAssets.rootAssets).forEach(function(key) {
                var value = monetAssets.rootAssets[key];
                var monetComponentType = key.split(".")[0];
                var gwdKey = value.id;
                var gwdValue = value[getMonetComponentValueFieldForComponentType(monetComponentType) || "value"];
                if (monetComponentType === "url" || monetComponentType === "image" || monetComponentType === "video") {
                    gwdValue = {
                        Url: gwdValue
                    };
                }
                gwdData[gwdKey] = gwdValue;
            });
            var gwdAssets = {};
            gwdAssets[dynamicFeedSheetName] = [ gwdData ];
            return gwdAssets;
        }
        function guessGWDDataValueMonetComponentType(value) {
            if (typeof value === "boolean") {
                return "bool";
            }
            if (typeof value === "number") {
                return "number";
            }
            if (typeof value === "string") {
                if (/(^[^.]*$)|(\.(gif|jpg|jpeg|png)$)/i.test(value) || /^https:\/\/[^.]+.nflximg.net\/api\/v\d\/rendition/.test(value)) {
                    return "image";
                }
                if (/(^[^.]*$)|(\.(mpeg|webm|flv|mp4)$)/i.test(value)) {
                    return "video";
                }
                if (/^https?/.test(value)) {
                    return "url";
                }
                return "text";
            }
            return null;
        }
        function convertGWDAssetsToMonetAssets(gwdAssets, dynamicFeedSheetName) {
            var dynamicContentValues = gwdAssets[dynamicFeedSheetName][0];
            var rootAssets = {};
            Object.keys(dynamicContentValues).forEach(function(key) {
                var value = dynamicContentValues[key];
                if (typeof value === "object" && value.hasOwnProperty("Url")) {
                    value = value.Url;
                }
                var monetComponentType = guessGWDDataValueMonetComponentType(value);
                if (monetComponentType === null) {
                    log("warn", "Failed to guess monet type for GWD value", value);
                    return;
                }
                var monetKey = monetComponentType + "." + key;
                var monetValue = {
                    type: monetComponentType,
                    id: key
                };
                var valueFieldKey = getMonetComponentValueFieldForComponentType(monetComponentType);
                monetValue[valueFieldKey] = value;
                rootAssets[monetKey] = monetValue;
            });
            return {
                rootAssets: rootAssets
            };
        }
        function validateGWDAssets(providedGWDData, defaultDynamicContent) {
            var validationPromises = Object.keys(defaultDynamicContent).map(function(key) {
                if (key[0] === "_") {
                    return Promise.resolve();
                }
                if (!providedGWDData.hasOwnProperty(key)) {
                    var message = "GWD assets invalid - missing key " + key;
                    return Promise.reject(new Error(message));
                }
                var defaultValue = defaultDynamicContent[key];
                var providedValue = providedGWDData[key];
                var defaultValueType = guessGWDDataValueMonetComponentType(defaultValue);
                var providedValueType = guessGWDDataValueMonetComponentType(providedValue);
                if (defaultValueType !== providedValueType) {
                    var message = [ "GWD assets invalid - data type mismatch, expected", "\n\t defaultValueType:", defaultValueType, "\n\t found", "\n\t providedValueType:", providedValueType, "\n\t defaultValue:", defaultValue, "\n\t providedValue:", providedValue ].join(" ");
                    return Promise.reject(new Error(message));
                }
                if (typeof providedValue === "object") {
                    return validateGWDAssets(providedValue, defaultValue);
                }
                return Promise.resolve();
            });
            return Promise.all(validationPromises);
        }
        function processAssets(monetDataProvider, monetAssets, gwdAssets) {
            if (!gwdAssets && !!monetAssets && monetDataProvider.dynamicFeedSheetName) {
                gwdAssets = convertMonetAssetsToGWDAssets(monetAssets, monetDataProvider.dynamicFeedSheetName);
            }
            if (!monetAssets && !!gwdAssets && monetDataProvider.dynamicFeedSheetName) {
                monetAssets = convertGWDAssetsToMonetAssets(gwdAssets, monetDataProvider.dynamicFeedSheetName);
            }
            if (!!gwdAssets && monetDataProvider.dynamicFeedSheetName) {
                var dynSheet = gwdAssets[monetDataProvider.dynamicFeedSheetName][0];
                dynSheet.Exit_URL = {
                    Url: chooseExitURL(dynSheet.Exit_URL_Desktop.Url, dynSheet.Exit_URL_iOS.Url, dynSheet.Exit_URL_Android.Url)
                };
            }
            if (!!monetAssets) {
                var getExitURLForKey = function(key) {
                    return monetAssets.rootAssets[key] && monetAssets.rootAssets[key].url;
                };
                monetAssets.rootAssets["url.Exit_URL"] = {
                    type: "url",
                    id: "Exit_URL",
                    url: chooseExitURL(getExitURLForKey("url.Exit_URL_Desktop"), getExitURLForKey("url.Exit_URL_iOS"), getExitURLForKey("url.Exit_URL_Android"))
                };
            }
            monetDataProvider.dataTransformers.forEach(function(transformer) {
                transformer.call(monetDataProvider, gwdAssets, monetDataProvider);
            });
            var assets = {};
            assets[MonetDataProviderDataType.MONET] = monetAssets;
            assets[MonetDataProviderDataType.GWD] = gwdAssets;
            return assets;
        }
        function validateProcessedAssets(processedAssets, monet, dynamicFeedSheetName) {
            var defaultDynamicContent = getGWDDynamicContent(dynamicFeedSheetName);
            if (!defaultDynamicContent) {
                return Promise.resolve(processedAssets);
            }
            var primaryGWDAssets = processedAssets[MonetDataProvider.MonetDataProviderDataType.GWD];
            return validateGWDAssets(primaryGWDAssets, defaultDynamicContent).then(function() {
                return processedAssets;
            }, function(error) {
                monet.logEvent("MONET_DATA_ERROR", {
                    stack: error.stack,
                    details: error.message
                });
                return Promise.reject(error);
            });
        }
        function loadPrimaryAssets(monetDataProvider, monet) {
            if (!monetDataProvider.primaryAssetsPromise) {
                var monetRequestParams = monet.buildMonetRequest();
                monetDataProvider.primaryAssetsPromise = new Promise(function(resolve, reject) {
                    monet.load(monetRequestParams, function(monetAssets) {
                        monet.logEvent("MONET_ASSETS_LOADED");
                        var processedAssets = processAssets(monetDataProvider, monetAssets, null);
                        validateProcessedAssets(processedAssets, monet, monetDataProvider.dynamicFeedSheetName).then(function() {
                            resolve(processedAssets);
                        }, reject);
                    }, function(error) {
                        log("warn", "Error in loading creative assets from monet", error);
                        reject(error);
                    });
                });
            }
            return monetDataProvider.primaryAssetsPromise;
        }
        function loadBackupAssets(monetDataProvider, monet) {
            if (!monetDataProvider.backupAssetsPromise) {
                monetDataProvider.backupAssetsPromise = doHTTPRequest(monetDataProvider.backupLocation || STATIC_BACKUP_LOCATION).then(function(backupMonetAssets) {
                    backupMonetAssets = JSON.parse(backupMonetAssets);
                    backupMonetAssets.isBackupData = true;
                    monet.logEvent("BACKUP_ASSETS_LOADED");
                    var processedAssets = processAssets(monetDataProvider, backupMonetAssets, null);
                    return validateProcessedAssets(processedAssets, monet, monetDataProvider.dynamicFeedSheetName);
                }).then(null, function(error) {
                    log("warn", "Backup load failed, trying dynamicContent", error);
                    var dynContent = getGWDDynamicContent(monetDataProvider.dynamicFeedSheetName);
                    if (!!dynContent) {
                        monet.logEvent("DYNAMIC_CONTENT_LOADED");
                        return processAssets(monetDataProvider, null, dynContent);
                    }
                    return Promise.reject(error);
                });
            }
            return monetDataProvider.backupAssetsPromise;
        }
        function MonetDataProvider(monetLoader, dynamicFeedSheetName, backupLocation) {
            this.backupLocation = backupLocation;
            this.monetLoader = monetLoader;
            this.dynamicFeedSheetName = dynamicFeedSheetName;
            this.dataLoadPromise = null;
            this.dataLoadFinished = false;
            this.loadedData = null;
            this.primaryAssetsPromise = null;
            this.backupAssetsPromise = null;
            this.dataTransformers = [];
        }
        MonetDataProvider.prototype.loadData = function() {
            var monetLoader = this.monetLoader;
            var monetDataProvider = this;
            if (!this.dataLoadPromise) {
                this.dataLoadPromise = monetLoader.getInitialized().then(function(monet) {
                    return loadPrimaryAssets(monetDataProvider, monet);
                }).then(null, function(error) {
                    log("warn", "primary assets load failed, trying backup", error);
                    return monetLoader.getInitialized().then(function(monet) {
                        return loadBackupAssets(monetDataProvider, monet);
                    });
                }).then(function(data) {
                    monetDataProvider.dataLoadFinished = true;
                    return monetDataProvider.loadedData = data;
                }, function(error) {
                    monetDataProvider.dataLoadFinished = true;
                    return Promise.reject(error);
                });
            }
            return this.dataLoadPromise;
        };
        MonetDataProvider.prototype.isDataLoaded = function() {
            return this.dataLoadFinished;
        };
        MonetDataProvider.prototype.getData = function(dataType) {
            if (!this.dataLoadFinished) {
                return null;
            }
            return this.loadedData[dataType];
        };
        MonetDataProvider.prototype.getDataWhenLoaded = function(dataType) {
            return this.dataLoadPromise.then(function(data) {
                return data[dataType];
            });
        };
        MonetDataProvider.prototype.getBackupData = function(dataType) {
            var monetDataProvider = this;
            return this.monetLoader.getInitialized().then(function(monet) {
                return loadBackupAssets(monetDataProvider, monet).then(function(backupAssets) {
                    return backupAssets[dataType];
                });
            });
        };
        MonetDataProvider.prototype.addDataTransformer = function(dataTransformer) {
            this.dataTransformers.push(dataTransformer);
        };
        MonetDataProvider.MonetDataProviderDataType = MonetDataProviderDataType;
        return MonetDataProvider;
    }();
    (function() {
        var MONET_GWD_COMPONENT_NAME = "monet-integrator";
        var DOUBLECLICK_COMPONENT_NAME = "gwd-doubleclick";
        var DOUBLECLICK_COMPONENT_DATA_PROVIDER_ATTRIBUTE_NAME = "data-provider";
        var DEFAULT_GWD_DATA_PROVIDER_TAG_NAME = "gwd-gpa-data-provider";
        var elementCreationObserver = new ElementCreationObserver();
        var _collection = [];
        var _isEmpty = true;
        function fireEvent(monetComponent, eventName) {
            var event = new CustomEvent(eventName, {
                bubbles: true,
                cancelable: true
            });
            monetComponent.dispatchEvent(event);
        }
        function replaceDoubleClickDataProvider(monetGWDComponent) {
            var monetGWDComponentId = monetGWDComponent.getAttribute("id");
            var doubleClickComponents = document.querySelectorAll(DOUBLECLICK_COMPONENT_NAME);
            for (var i = 0; i < doubleClickComponents.length; ++i) {
                var doubleClickComponent = doubleClickComponents[i];
                doubleClickComponent.setAttribute(DOUBLECLICK_COMPONENT_DATA_PROVIDER_ATTRIBUTE_NAME, monetGWDComponentId);
            }
            var defaultGWDDataProvider = document.querySelector(DEFAULT_GWD_DATA_PROVIDER_TAG_NAME);
            if (!!defaultGWDDataProvider && !!defaultGWDDataProvider.parentNode) {
                defaultGWDDataProvider.parentNode.removeChild(defaultGWDDataProvider);
            }
        }
        function setUpMonetComponentRePrioritization() {
            elementCreationObserver.startObserving("monet-integrator", function(createdNodes) {
                elementCreationObserver.stopObserving();
                var monetGWDNode = createdNodes[0];
                document.body.insertBefore(monetGWDNode, document.body.firstChild);
                replaceDoubleClickDataProvider(monetGWDNode);
            });
        }
        var proto = Object.create(HTMLElement.prototype, {
            pendingLogs: {
                value: [],
                enumerable: false
            },
            createdCallback: {
                value: function() {
                    this.monetLoader = null;
                    this.monetDataProvider = null;
                    replaceDoubleClickDataProvider(this);
                },
                enumerable: true
            },
            attachedCallback: {
                value: function() {
                    if (this._attached) return;
                    this._attached = true;
                    var component = this;
                    this.monetLoader = new MonetLoader();
                    this.monetLoader.getInitialized().then(function(monet) {
                        if (component.pendingLogs.length === 0) {
                            return;
                        }
                        var pendingLogs = component.pendingLogs.slice();
                        component.pendingLogs.length = 0;
                        monet.logEvents(pendingLogs);
                    });
                    var dynamicFeedSheetName = this.getAttribute("dynamic-feed-sheet-name");
                    if (!dynamicFeedSheetName || dynamicFeedSheetName && dynamicFeedSheetName.length < 1) {
                        log("warn", 'Missing `dynamic-feed-sheet-name="your sheet name"`');
                    }
                    this.monetDataProvider = new MonetDataProvider(this.monetLoader, dynamicFeedSheetName, this.getAttribute("backup"));
                    this.monetDataProvider.loadData().then(function() {}, function(error) {
                        fireEvent(component, "error");
                    });
                },
                enumerable: true
            },
            attributeChangedCallback: {
                value: function(attributeName) {},
                enumerable: true
            },
            isDataLoaded: {
                value: function() {
                    return !!this.monetDataProvider && this.monetDataProvider.isDataLoaded();
                }
            },
            getData: {
                value: function() {
                    return this.monetDataProvider.getData(MonetDataProvider.MonetDataProviderDataType.GWD);
                }
            },
            getMonetData: {
                value: function() {
                    return this.monetDataProvider.getDataWhenLoaded(MonetDataProvider.MonetDataProviderDataType.MONET);
                }
            },
            getBackupMonetData: {
                value: function() {
                    return this.monetDataProvider.getBackupData(MonetDataProvider.MonetDataProviderDataType.MONET);
                }
            },
            addDataTransformer: {
                value: function(transformer) {
                    return this.monetDataProvider.addDataTransformer(transformer);
                }
            },
            logEvent: {
                value: function(eventType, eventData) {
                    if (!this.monetLoader) {
                        this.pendingLogs.push({
                            eventType: eventType,
                            eventData: eventData
                        });
                        return;
                    }
                    this.monetLoader.getInitialized().then(function(monet) {
                        monet.logEvent(eventType, eventData);
                    }, function(error) {
                        log("error", "Failed to log Monet event", error, eventType, eventData);
                    });
                }
            },
            register: {
                value: function(component) {
                    _isEmpty = false;
                    if (_collection.indexOf(component) > -1) {
                        return;
                    }
                    _collection.push(component);
                    component.addEventListener("ready", function(event) {
                        var index = _collection.indexOf(event.target);
                        if (index > -1) {
                            _collection.splice(index, 1);
                            if (_collection.length == 0) {
                                this.setAttribute("ready", "");
                                fireEvent(this, "ready");
                            }
                        }
                    }.bind(this));
                }
            }
        });
        setUpMonetComponentRePrioritization();
        document.registerElement(MONET_GWD_COMPONENT_NAME, {
            prototype: proto
        });
    })();
})();

(function() {
    function aa(a, b, c) {
        return a.call.apply(a.bind, arguments);
    }
    function ba(a, b, c) {
        if (!a) throw Error();
        if (2 < arguments.length) {
            var d = Array.prototype.slice.call(arguments, 2);
            return function() {
                var c = Array.prototype.slice.call(arguments);
                Array.prototype.unshift.apply(c, d);
                return a.apply(b, c);
            };
        }
        return function() {
            return a.apply(b, arguments);
        };
    }
    function p(a, b, c) {
        p = Function.prototype.bind && -1 != Function.prototype.bind.toString().indexOf("native code") ? aa : ba;
        return p.apply(null, arguments);
    }
    var q = Date.now || function() {
        return +new Date();
    };
    function ca(a, b) {
        this.a = a;
        this.m = b || a;
        this.c = this.m.document;
    }
    var da = !!window.FontFace;
    function t(a, b, c, d) {
        b = a.c.createElement(b);
        if (c) for (var e in c) c.hasOwnProperty(e) && ("style" == e ? b.style.cssText = c[e] : b.setAttribute(e, c[e]));
        d && b.appendChild(a.c.createTextNode(d));
        return b;
    }
    function u(a, b, c) {
        a = a.c.getElementsByTagName(b)[0];
        a || (a = document.documentElement);
        a.insertBefore(c, a.lastChild);
    }
    function v(a) {
        a.parentNode && a.parentNode.removeChild(a);
    }
    function w(a, b, c) {
        b = b || [];
        c = c || [];
        for (var d = a.className.split(/\s+/), e = 0; e < b.length; e += 1) {
            for (var f = !1, g = 0; g < d.length; g += 1) if (b[e] === d[g]) {
                f = !0;
                break;
            }
            f || d.push(b[e]);
        }
        b = [];
        for (e = 0; e < d.length; e += 1) {
            f = !1;
            for (g = 0; g < c.length; g += 1) if (d[e] === c[g]) {
                f = !0;
                break;
            }
            f || b.push(d[e]);
        }
        a.className = b.join(" ").replace(/\s+/g, " ").replace(/^\s+|\s+$/, "");
    }
    function y(a, b) {
        for (var c = a.className.split(/\s+/), d = 0, e = c.length; d < e; d++) if (c[d] == b) return !0;
        return !1;
    }
    function z(a) {
        if ("string" === typeof a.f) return a.f;
        var b = a.m.location.protocol;
        "about:" == b && (b = a.a.location.protocol);
        return "https:" == b ? "https:" : "http:";
    }
    function ea(a) {
        return a.m.location.hostname || a.a.location.hostname;
    }
    function A(a, b, c) {
        function d() {
            k && e && f && (k(g), k = null);
        }
        b = t(a, "link", {
            rel: "stylesheet",
            href: b,
            media: "all"
        });
        var e = !1, f = !0, g = null, k = c || null;
        da ? (b.onload = function() {
            e = !0;
            d();
        }, b.onerror = function() {
            e = !0;
            g = Error("Stylesheet failed to load");
            d();
        }) : setTimeout(function() {
            e = !0;
            d();
        }, 0);
        u(a, "head", b);
    }
    function B(a, b, c, d) {
        var e = a.c.getElementsByTagName("head")[0];
        if (e) {
            var f = t(a, "script", {
                src: b
            }), g = !1;
            f.onload = f.onreadystatechange = function() {
                g || this.readyState && "loaded" != this.readyState && "complete" != this.readyState || (g = !0, 
                c && c(null), f.onload = f.onreadystatechange = null, "HEAD" == f.parentNode.tagName && e.removeChild(f));
            };
            e.appendChild(f);
            setTimeout(function() {
                g || (g = !0, c && c(Error("Script load timeout")));
            }, d || 5e3);
            return f;
        }
        return null;
    }
    function C() {
        this.a = 0;
        this.c = null;
    }
    function D(a) {
        a.a++;
        return function() {
            a.a--;
            E(a);
        };
    }
    function F(a, b) {
        a.c = b;
        E(a);
    }
    function E(a) {
        0 == a.a && a.c && (a.c(), a.c = null);
    }
    function G(a) {
        this.a = a || "-";
    }
    G.prototype.c = function(a) {
        for (var b = [], c = 0; c < arguments.length; c++) b.push(arguments[c].replace(/[\W_]+/g, "").toLowerCase());
        return b.join(this.a);
    };
    function H(a, b) {
        this.c = a;
        this.f = 4;
        this.a = "n";
        var c = (b || "n4").match(/^([nio])([1-9])$/i);
        c && (this.a = c[1], this.f = parseInt(c[2], 10));
    }
    function fa(a) {
        return I(a) + " " + (a.f + "00") + " 300px " + J(a.c);
    }
    function J(a) {
        var b = [];
        a = a.split(/,\s*/);
        for (var c = 0; c < a.length; c++) {
            var d = a[c].replace(/['"]/g, "");
            -1 != d.indexOf(" ") || /^\d/.test(d) ? b.push("'" + d + "'") : b.push(d);
        }
        return b.join(",");
    }
    function K(a) {
        return a.a + a.f;
    }
    function I(a) {
        var b = "normal";
        "o" === a.a ? b = "oblique" : "i" === a.a && (b = "italic");
        return b;
    }
    function ga(a) {
        var b = 4, c = "n", d = null;
        a && ((d = a.match(/(normal|oblique|italic)/i)) && d[1] && (c = d[1].substr(0, 1).toLowerCase()), 
        (d = a.match(/([1-9]00|normal|bold)/i)) && d[1] && (/bold/i.test(d[1]) ? b = 7 : /[1-9]00/.test(d[1]) && (b = parseInt(d[1].substr(0, 1), 10))));
        return c + b;
    }
    function ha(a, b) {
        this.c = a;
        this.f = a.m.document.documentElement;
        this.h = b;
        this.a = new G("-");
        this.j = !1 !== b.events;
        this.g = !1 !== b.classes;
    }
    function ia(a) {
        a.g && w(a.f, [ a.a.c("wf", "loading") ]);
        L(a, "loading");
    }
    function M(a) {
        if (a.g) {
            var b = y(a.f, a.a.c("wf", "active")), c = [], d = [ a.a.c("wf", "loading") ];
            b || c.push(a.a.c("wf", "inactive"));
            w(a.f, c, d);
        }
        L(a, "inactive");
    }
    function L(a, b, c) {
        if (a.j && a.h[b]) if (c) a.h[b](c.c, K(c)); else a.h[b]();
    }
    function ja() {
        this.c = {};
    }
    function ka(a, b, c) {
        var d = [], e;
        for (e in b) if (b.hasOwnProperty(e)) {
            var f = a.c[e];
            f && d.push(f(b[e], c));
        }
        return d;
    }
    function N(a, b) {
        this.c = a;
        this.f = b;
        this.a = t(this.c, "span", {
            "aria-hidden": "true"
        }, this.f);
    }
    function O(a) {
        u(a.c, "body", a.a);
    }
    function P(a) {
        return "display:block;position:absolute;top:-9999px;left:-9999px;font-size:300px;width:auto;height:auto;line-height:normal;margin:0;padding:0;font-variant:normal;white-space:nowrap;font-family:" + J(a.c) + ";" + ("font-style:" + I(a) + ";font-weight:" + (a.f + "00") + ";");
    }
    function Q(a, b, c, d, e, f) {
        this.g = a;
        this.j = b;
        this.a = d;
        this.c = c;
        this.f = e || 3e3;
        this.h = f || void 0;
    }
    Q.prototype.start = function() {
        var a = this.c.m.document, b = this, c = q(), d = new Promise(function(d, e) {
            function k() {
                q() - c >= b.f ? e() : a.fonts.load(fa(b.a), b.h).then(function(a) {
                    1 <= a.length ? d() : setTimeout(k, 25);
                }, function() {
                    e();
                });
            }
            k();
        }), e = new Promise(function(a, d) {
            setTimeout(d, b.f);
        });
        Promise.race([ e, d ]).then(function() {
            b.g(b.a);
        }, function() {
            b.j(b.a);
        });
    };
    function R(a, b, c, d, e, f, g) {
        this.v = a;
        this.B = b;
        this.c = c;
        this.a = d;
        this.s = g || "BESbswy";
        this.f = {};
        this.w = e || 3e3;
        this.u = f || null;
        this.o = this.j = this.h = this.g = null;
        this.g = new N(this.c, this.s);
        this.h = new N(this.c, this.s);
        this.j = new N(this.c, this.s);
        this.o = new N(this.c, this.s);
        a = new H(this.a.c + ",serif", K(this.a));
        a = P(a);
        this.g.a.style.cssText = a;
        a = new H(this.a.c + ",sans-serif", K(this.a));
        a = P(a);
        this.h.a.style.cssText = a;
        a = new H("serif", K(this.a));
        a = P(a);
        this.j.a.style.cssText = a;
        a = new H("sans-serif", K(this.a));
        a = P(a);
        this.o.a.style.cssText = a;
        O(this.g);
        O(this.h);
        O(this.j);
        O(this.o);
    }
    var S = {
        D: "serif",
        C: "sans-serif"
    }, T = null;
    function U() {
        if (null === T) {
            var a = /AppleWebKit\/([0-9]+)(?:\.([0-9]+))/.exec(window.navigator.userAgent);
            T = !!a && (536 > parseInt(a[1], 10) || 536 === parseInt(a[1], 10) && 11 >= parseInt(a[2], 10));
        }
        return T;
    }
    R.prototype.start = function() {
        this.f.serif = this.j.a.offsetWidth;
        this.f["sans-serif"] = this.o.a.offsetWidth;
        this.A = q();
        la(this);
    };
    function ma(a, b, c) {
        for (var d in S) if (S.hasOwnProperty(d) && b === a.f[S[d]] && c === a.f[S[d]]) return !0;
        return !1;
    }
    function la(a) {
        var b = a.g.a.offsetWidth, c = a.h.a.offsetWidth, d;
        (d = b === a.f.serif && c === a.f["sans-serif"]) || (d = U() && ma(a, b, c));
        d ? q() - a.A >= a.w ? U() && ma(a, b, c) && (null === a.u || a.u.hasOwnProperty(a.a.c)) ? V(a, a.v) : V(a, a.B) : na(a) : V(a, a.v);
    }
    function na(a) {
        setTimeout(p(function() {
            la(this);
        }, a), 50);
    }
    function V(a, b) {
        setTimeout(p(function() {
            v(this.g.a);
            v(this.h.a);
            v(this.j.a);
            v(this.o.a);
            b(this.a);
        }, a), 0);
    }
    function W(a, b, c) {
        this.c = a;
        this.a = b;
        this.f = 0;
        this.o = this.j = !1;
        this.s = c;
    }
    var X = null;
    W.prototype.g = function(a) {
        var b = this.a;
        b.g && w(b.f, [ b.a.c("wf", a.c, K(a).toString(), "active") ], [ b.a.c("wf", a.c, K(a).toString(), "loading"), b.a.c("wf", a.c, K(a).toString(), "inactive") ]);
        L(b, "fontactive", a);
        this.o = !0;
        oa(this);
    };
    W.prototype.h = function(a) {
        var b = this.a;
        if (b.g) {
            var c = y(b.f, b.a.c("wf", a.c, K(a).toString(), "active")), d = [], e = [ b.a.c("wf", a.c, K(a).toString(), "loading") ];
            c || d.push(b.a.c("wf", a.c, K(a).toString(), "inactive"));
            w(b.f, d, e);
        }
        L(b, "fontinactive", a);
        oa(this);
    };
    function oa(a) {
        0 == --a.f && a.j && (a.o ? (a = a.a, a.g && w(a.f, [ a.a.c("wf", "active") ], [ a.a.c("wf", "loading"), a.a.c("wf", "inactive") ]), 
        L(a, "active")) : M(a.a));
    }
    function pa(a) {
        this.j = a;
        this.a = new ja();
        this.h = 0;
        this.f = this.g = !0;
    }
    pa.prototype.load = function(a) {
        this.c = new ca(this.j, a.context || this.j);
        this.g = !1 !== a.events;
        this.f = !1 !== a.classes;
        qa(this, new ha(this.c, a), a);
    };
    function ra(a, b, c, d, e) {
        var f = 0 == --a.h;
        (a.f || a.g) && setTimeout(function() {
            var a = e || null, k = d || null || {};
            if (0 === c.length && f) M(b.a); else {
                b.f += c.length;
                f && (b.j = f);
                var h, m = [];
                for (h = 0; h < c.length; h++) {
                    var l = c[h], n = k[l.c], r = b.a, x = l;
                    r.g && w(r.f, [ r.a.c("wf", x.c, K(x).toString(), "loading") ]);
                    L(r, "fontloading", x);
                    r = null;
                    null === X && (X = window.FontFace ? (x = /Gecko.*Firefox\/(\d+)/.exec(window.navigator.userAgent)) ? 42 < parseInt(x[1], 10) : !0 : !1);
                    X ? r = new Q(p(b.g, b), p(b.h, b), b.c, l, b.s, n) : r = new R(p(b.g, b), p(b.h, b), b.c, l, b.s, a, n);
                    m.push(r);
                }
                for (h = 0; h < m.length; h++) m[h].start();
            }
        }, 0);
    }
    function qa(a, b, c) {
        var d = [], e = c.timeout;
        ia(b);
        var d = ka(a.a, c, a.c), f = new W(a.c, b, e);
        a.h = d.length;
        b = 0;
        for (c = d.length; b < c; b++) d[b].load(function(b, d, c) {
            ra(a, f, b, d, c);
        });
    }
    function sa(a, b) {
        this.c = a;
        this.a = b;
    }
    function ta(a, b, c) {
        var d = z(a.c);
        a = (a.a.api || "fast.fonts.net/jsapi").replace(/^.*http(s?):(\/\/)?/, "");
        return d + "//" + a + "/" + b + ".js" + (c ? "?v=" + c : "");
    }
    sa.prototype.load = function(a) {
        function b() {
            if (f["__mti_fntLst" + d]) {
                var c = f["__mti_fntLst" + d](), e = [], h;
                if (c) for (var m = 0; m < c.length; m++) {
                    var l = c[m].fontfamily;
                    void 0 != c[m].fontStyle && void 0 != c[m].fontWeight ? (h = c[m].fontStyle + c[m].fontWeight, 
                    e.push(new H(l, h))) : e.push(new H(l));
                }
                a(e);
            } else setTimeout(function() {
                b();
            }, 50);
        }
        var c = this, d = c.a.projectId, e = c.a.version;
        if (d) {
            var f = c.c.m;
            B(this.c, ta(c, d, e), function(e) {
                e ? a([]) : (f["__MonotypeConfiguration__" + d] = function() {
                    return c.a;
                }, b());
            }).id = "__MonotypeAPIScript__" + d;
        } else a([]);
    };
    function ua(a, b) {
        this.c = a;
        this.a = b;
    }
    ua.prototype.load = function(a) {
        var b, c, d = this.a.urls || [], e = this.a.families || [], f = this.a.testStrings || {}, g = new C();
        b = 0;
        for (c = d.length; b < c; b++) A(this.c, d[b], D(g));
        var k = [];
        b = 0;
        for (c = e.length; b < c; b++) if (d = e[b].split(":"), d[1]) for (var h = d[1].split(","), m = 0; m < h.length; m += 1) k.push(new H(d[0], h[m])); else k.push(new H(d[0]));
        F(g, function() {
            a(k, f);
        });
    };
    function va(a, b, c) {
        a ? this.c = a : this.c = b + wa;
        this.a = [];
        this.f = [];
        this.g = c || "";
    }
    var wa = "//fonts.googleapis.com/css";
    function xa(a, b) {
        for (var c = b.length, d = 0; d < c; d++) {
            var e = b[d].split(":");
            3 == e.length && a.f.push(e.pop());
            var f = "";
            2 == e.length && "" != e[1] && (f = ":");
            a.a.push(e.join(f));
        }
    }
    function ya(a) {
        if (0 == a.a.length) throw Error("No fonts to load!");
        if (-1 != a.c.indexOf("kit=")) return a.c;
        for (var b = a.a.length, c = [], d = 0; d < b; d++) c.push(a.a[d].replace(/ /g, "+"));
        b = a.c + "?family=" + c.join("%7C");
        0 < a.f.length && (b += "&subset=" + a.f.join(","));
        0 < a.g.length && (b += "&text=" + encodeURIComponent(a.g));
        return b;
    }
    function za(a) {
        this.f = a;
        this.a = [];
        this.c = {};
    }
    var Aa = {
        latin: "BESbswy",
        "latin-ext": "çöüğş",
        cyrillic: "йяЖ",
        greek: "αβΣ",
        khmer: "កខគ",
        Hanuman: "កខគ"
    }, Ba = {
        thin: "1",
        extralight: "2",
        "extra-light": "2",
        ultralight: "2",
        "ultra-light": "2",
        light: "3",
        regular: "4",
        book: "4",
        medium: "5",
        "semi-bold": "6",
        semibold: "6",
        "demi-bold": "6",
        demibold: "6",
        bold: "7",
        "extra-bold": "8",
        extrabold: "8",
        "ultra-bold": "8",
        ultrabold: "8",
        black: "9",
        heavy: "9",
        l: "3",
        r: "4",
        b: "7"
    }, Ca = {
        i: "i",
        italic: "i",
        n: "n",
        normal: "n"
    }, Da = /^(thin|(?:(?:extra|ultra)-?)?light|regular|book|medium|(?:(?:semi|demi|extra|ultra)-?)?bold|black|heavy|l|r|b|[1-9]00)?(n|i|normal|italic)?$/;
    function Ea(a) {
        for (var b = a.f.length, c = 0; c < b; c++) {
            var d = a.f[c].split(":"), e = d[0].replace(/\+/g, " "), f = [ "n4" ];
            if (2 <= d.length) {
                var g;
                var k = d[1];
                g = [];
                if (k) for (var k = k.split(","), h = k.length, m = 0; m < h; m++) {
                    var l;
                    l = k[m];
                    if (l.match(/^[\w-]+$/)) {
                        var n = Da.exec(l.toLowerCase());
                        if (null == n) l = ""; else {
                            l = n[2];
                            l = null == l || "" == l ? "n" : Ca[l];
                            n = n[1];
                            if (null == n || "" == n) n = "4"; else var r = Ba[n], n = r ? r : isNaN(n) ? "4" : n.substr(0, 1);
                            l = [ l, n ].join("");
                        }
                    } else l = "";
                    l && g.push(l);
                }
                0 < g.length && (f = g);
                3 == d.length && (d = d[2], g = [], d = d ? d.split(",") : g, 0 < d.length && (d = Aa[d[0]]) && (a.c[e] = d));
            }
            a.c[e] || (d = Aa[e]) && (a.c[e] = d);
            for (d = 0; d < f.length; d += 1) a.a.push(new H(e, f[d]));
        }
    }
    function Fa(a, b) {
        this.c = a;
        this.a = b;
    }
    var Ga = {
        Arimo: !0,
        Cousine: !0,
        Tinos: !0
    };
    Fa.prototype.load = function(a) {
        var b = new C(), c = this.c, d = new va(this.a.api, z(c), this.a.text), e = this.a.families;
        xa(d, e);
        var f = new za(e);
        Ea(f);
        A(c, ya(d), D(b));
        F(b, function() {
            a(f.a, f.c, Ga);
        });
    };
    function Ha(a, b) {
        this.c = a;
        this.a = b;
    }
    Ha.prototype.load = function(a) {
        var b = this.a.id, c = this.c.m;
        b ? B(this.c, (this.a.api || "https://use.typekit.net") + "/" + b + ".js", function(b) {
            if (b) a([]); else if (c.Typekit && c.Typekit.config && c.Typekit.config.fn) {
                b = c.Typekit.config.fn;
                for (var e = [], f = 0; f < b.length; f += 2) for (var g = b[f], k = b[f + 1], h = 0; h < k.length; h++) e.push(new H(g, k[h]));
                try {
                    c.Typekit.load({
                        events: !1,
                        classes: !1,
                        async: !0
                    });
                } catch (m) {}
                a(e);
            }
        }, 2e3) : a([]);
    };
    function Ia(a, b) {
        this.c = a;
        this.f = b;
        this.a = [];
    }
    Ia.prototype.load = function(a) {
        var b = this.f.id, c = this.c.m, d = this;
        b ? (c.__webfontfontdeckmodule__ || (c.__webfontfontdeckmodule__ = {}), c.__webfontfontdeckmodule__[b] = function(b, c) {
            for (var g = 0, k = c.fonts.length; g < k; ++g) {
                var h = c.fonts[g];
                d.a.push(new H(h.name, ga("font-weight:" + h.weight + ";font-style:" + h.style)));
            }
            a(d.a);
        }, B(this.c, z(this.c) + (this.f.api || "//f.fontdeck.com/s/css/js/") + ea(this.c) + "/" + b + ".js", function(b) {
            b && a([]);
        })) : a([]);
    };
    var Y = new pa(window);
    Y.a.c.custom = function(a, b) {
        return new ua(b, a);
    };
    Y.a.c.fontdeck = function(a, b) {
        return new Ia(b, a);
    };
    Y.a.c.monotype = function(a, b) {
        return new sa(b, a);
    };
    Y.a.c.typekit = function(a, b) {
        return new Ha(b, a);
    };
    Y.a.c.google = function(a, b) {
        return new Fa(b, a);
    };
    window.WebFont = {
        load: p(Y.load, Y)
    };
    if (window.WebFontConfig) Y.load(window.WebFontConfig);
})();

(function() {
    var COMPONENT_NAME = "netflix-fonts";
    function onlyUnique(value, index, self) {
        return self.indexOf(value) === index;
    }
    function loadFonts(locales, comp) {
        var fonts = {};
        var fontFamilies = {
            en: [ "Netflix Sans" ],
            he: [ "Noto Sans Hebrew", "Assistant", "Rubik" ],
            th: [ "Neue Helvetica Thai", "Prompt" ],
            ar: [ "Neue Helvetica Arab", "Changa", "Droid Arabic Kufi" ]
        };
        locales = locales.filter(onlyUnique);
        for (var i = 0; i < locales.length; i++) {
            switch (locales[i]) {
              case "he":
                fonts.he = {
                    links: [ "https://fonts.googleapis.com/earlyaccess/notosanshebrew.css", "https://fonts.googleapis.com/css?family=Assistant:400,600,700&subset=hebrew", "https://fonts.googleapis.com/css?family=Rubik:400,700&subset=hebrew" ],
                    fams: fontFamilies.he.slice()
                };
                break;

              case "th":
                fonts.th = {
                    links: [ "https://ae.nflximg.net/monet/fonts/thai/neuehelveticathai.css", "https://fonts.googleapis.com/css?family=Prompt:400,600,700&subset=thai" ],
                    fams: fontFamilies.th.slice()
                };
                break;

              case "ar":
                fonts.ar = {
                    links: [ "https://ae.nflximg.net/monet/fonts/arabic/neuehelveticaarabic.css", "https://fonts.googleapis.com/css?family=Changa:400,600,700&subset=arabic", "https://fonts.googleapis.com/earlyaccess/droidarabickufi.css" ],
                    fams: fontFamilies.ar.slice()
                };
                break;
            }
        }
        fonts.en = {
            links: [ "https://ae.nflximg.net/monet/fonts/netflixsans.css" ],
            fams: fontFamilies.en.slice()
        };
        var failed = [];
        function onComplete() {
            if (failed.length) {
                var urls = [];
                var fams = [];
                for (var i = 0; i < failed.length; i++) {
                    for (f in fontFamilies) {
                        var index = fontFamilies[f].indexOf(failed[i]);
                        if (index > -1) {
                            if (fontFamilies[f][index + 1]) {
                                urls.push(fonts[f].links.shift());
                                fams.push(fonts[f].fams.shift());
                            }
                            break;
                        }
                    }
                }
                if (urls[0]) {
                    WebFontConfig.custom.families = fams;
                    WebFontConfig.custom.urls = urls;
                    WebFont.load(WebFontConfig);
                } else {
                    this.fontsLoaded = true;
                }
                failed = [];
            } else {
                this.fontsLoaded = true;
            }
            comp.dispatchEvent(new CustomEvent("ready"));
        }
        var urls = [];
        var fams = [];
        for (var i in fonts) {
            var u = fonts[i].links.shift();
            var f = fonts[i].fams.shift();
            if (u) {
                urls.push(u);
                fams.push(f);
            }
        }
        var WebFontConfig = {
            custom: {
                families: fams,
                urls: urls
            },
            timeout: 2e3,
            active: onComplete.bind(this),
            inactive: onComplete.bind(this),
            fontinactive: function(familyName) {
                failed.push(familyName);
            }
        };
        WebFont.load(WebFontConfig);
    }
    if (document.registerElement) {
        var component = Object.create(HTMLElement.prototype, {
            attachedCallback: {
                value: function() {
                    var dom = this;
                    Utils.createStyle.call(dom, "", "body, .en, .da, .nl, .fi, .fr, .de, .it, .no, .pt, .ro, .es, .sv, .tr, .pl, .el", "font-family: 'Netflix Sans', Helvetica, Arial, sans-serif;", ".zh", "-webkit-locale: 'zh'; font-family: 'Netflix Sans', 'Microsoft JhengHei UI', '微軟正黑體', 'Heiti TC', '黑体-简', Arial, Helvetica, sans-serif;", ".ja", "-webkit-locale: 'ja'; font-family: 'Netflix Sans', 'Yu Gothic Medium', 'Hiragino Kaku Gothic Pro', 'ヒラギノ角ゴ', Arial, Helvetica, sans-serif;", ".ko", "-webkit-locale: 'ko'; font-family: 'Netflix Sans', 'Malgun Gothic', '맑은 고딕', 'Apple SD Gothic Neo', '애플 SD 산돌고딕 Neo', Arial, Helvetica, sans-serif;", ".ar", "font-family: 'Netflix Sans', 'Neue Helvetica Arab', 'Changa', 'Droid Arabic Kufi', Arial, sans-serif;", ".th", "font-family: 'Netflix Sans', 'Neue Helvetica Thai', 'Prompt', Arial, sans-serif;", ".th .cta_copy", "margin-top: -2px;", ".he", "font-family: 'Netflix Sans', 'Noto Sans Hebrew', 'Assistant', 'Rubik', Arial, sans-serif;");
                    var locales = [];
                    var MonetComponent = document.querySelector("monet-integrator");
                    if (MonetComponent) {
                        MonetComponent.register(this);
                        MonetComponent.getMonetData().then(function(data) {
                            try {
                                for (var i in data.rootAssets) {
                                    if (i.split(".")[0] == "text") {
                                        locales.push(Monet.getComponentLocale(i).substr(0, 2));
                                    }
                                }
                                loadFonts(locales, dom);
                            } catch (e) {
                                MonetComponent.getBackupMonetData().then(function(backupData) {
                                    for (var i in data.rootAssets) {
                                        if (i.split(".")[0] == "text") {
                                            locales.push(Monet.getComponentLocale(i).substr(0, 2));
                                        }
                                    }
                                    loadFonts(locales, dom);
                                }, function(error) {
                                    Monet.logEvent("MONET_DATA_ERROR", {
                                        details: "Failed to load backup Monet data",
                                        stack: error
                                    });
                                });
                            }
                        });
                    }
                }
            }
        });
        document.registerElement(COMPONENT_NAME, {
            prototype: component
        });
    }
})();

(function() {
    var COMPONENT_NAME = "netflix-video";
    window.Utils = function(Utils) {
        Utils.tracker = function(s, u, d) {
            if (typeof Monet !== "undefined") {
                Monet.logEvent(s, {
                    url: u,
                    pos: d.time
                });
            }
            if (typeof Enabler !== "undefined") {
                switch (s) {
                  case "VIDEO_FIRST_QUART":
                    Enabler.counter("VIDEO_FIRST_QUART");
                    break;

                  case "VIDEO_SECOND_QUART":
                    Enabler.counter("VIDEO_SECOND_QUART");
                    break;

                  case "VIDEO_THIRD_QUART":
                    Enabler.counter("VIDEO_THIRD_QUART");
                    break;

                  case "VIDEO_PLAY":
                    Enabler.counter("VIDEO_PLAY");
                    break;

                  case "VIDEO_COMPLETE":
                    Enabler.counter("VIDEO_COMPLETE");
                    break;

                  case "VIDEO_PAUSE":
                    Enabler.counter("VIDEO_PAUSE");
                    break;

                  case "VIDEO_STOP":
                    Enabler.counter("VIDEO_STOP");
                    break;

                  case "VIDEO_UNMUTE":
                    Enabler.counter("VIDEO_UNMUTE");
                    break;

                  case "VIDEO_MUTE":
                    Enabler.counter("VIDEO_MUTE");
                    break;

                  case "VIDEO_STOP":
                    Enabler.counter("VIDEO_STOP");
                    break;
                }
            }
        };
        Utils.isAutoplayAvailable = function() {
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
        Utils.timeFormat = function(time) {
            var sn = parseInt(time, 10);
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
        Utils.hide = function(el) {
            el.classList.add("hide");
        };
        Utils.show = function(el) {
            el.classList.remove("hide");
        };
        return Utils;
    }(window.Utils || {});
    var VideoSource = function(id, config) {
        function VideoSource(id, config) {
            this._id = id;
            this.id = id;
            this.title = config.sources[id].split("/").pop().split(".")[0];
            this.plays = 0;
            this.completed = 0;
            this.layers = [];
            this.source = config.sources[id];
            this.customControls = config.customControls[id] || false;
            this.controls = config.controls[id] === undefined ? true : config.controls[id];
            this.muted = config.muted[id] || false;
            this.hideOnComplete = config.hideOnComplete[id] || false;
        }
        VideoSource.prototype.hasBeenPlayed = function() {
            return Boolean(this.plays);
        };
        return VideoSource;
    }();
    var NetflixVideo = function(component, config) {
        function NetflixVideo(component, config) {
            this.component = component;
            this.config = config;
            this.sources = [];
            this.wrapper = document.createElement("div");
            this.closeButton = createCloseButton.call(this);
            this.container = document.createElement("div");
            this.container.className = "netflix-video-container";
            this.clickArea = document.createElement("div");
            this.closeButton.classList.add("close");
            this.clickArea.classList.add("videoClick");
            this.wrapper.classList.add("netflix-video");
            this.wrapper.appendChild(this.container);
            this.wrapper.appendChild(this.clickArea);
            this.wrapper.appendChild(this.closeButton);
            this.component.appendChild(this.wrapper);
            for (var i = 0; i < this.config.sources.length; i++) {
                this.sources.push(new VideoSource(i, this.config));
                this.sources[i].muted = this.config.muted[i];
            }
            this.stopTimer = function() {
                this.playing = false;
                this.component.playing = false;
                clearInterval(this.timer);
                setTimeDisplay.call(this);
            };
            style.call(this);
            buildControls.call(this);
            createPlayer.call(this);
            function createPlayer() {
                var id = 0;
                this.id = id;
                this.video_id = this.component.getAttribute("video_id");
                this.PlayerState = {
                    ENDED: "ended",
                    PLAYING: "loadeddata",
                    PAUSED: "pause",
                    CUED: "loadstart",
                    BUFFERING: "play",
                    LOADED: "loadeddata",
                    VOLUME: "volumechange"
                };
                this._video = document.createElement("video");
                this._video.width = this.config.size[id] ? this.config.size[id].width : this.config.size[0].width;
                this._video.height = this.config.size[id] ? this.config.size[id].height : this.config.size[0].height;
                this._video.addEventListener("ended", onStateChanged.bind(this));
                this._video.addEventListener("play", onStateChanged.bind(this));
                this._video.addEventListener("pause", onStateChanged.bind(this));
                this._video.addEventListener("volumechange", onStateChanged.bind(this));
                this._video.addEventListener("loadeddata", onStateChanged.bind(this));
                this.spinner = document.createElement("div");
                this.wrapper.insertBefore(this.spinner, this.wrapper.firstChild);
                this.spinner.classList.add("spinner");
                this.spinner.innerHTML = '<svg width="38" height="38" viewBox="0 0 38 38" xmlns="http://www.w3.org/2000/svg"> <defs> <linearGradient x1="8.042%" y1="0%" x2="65.682%" y2="23.865%" id="a"> <stop stop-color="#fff" stop-opacity="0" offset="0%"/> <stop stop-color="#fff" stop-opacity=".631" offset="63.146%"/> <stop stop-color="#fff" offset="100%"/> </linearGradient> </defs> <g fill="none" fill-rule="evenodd"> <g transform="translate(1 1)"> <path d="M36 18c0-9.94-8.06-18-18-18" id="Oval-2" stroke="url(#a)" stroke-width="2"> <animateTransform attributeName="transform" type="rotate" from="0 18 18" to="360 18 18" dur="0.9s" repeatCount="indefinite"/> </path> <circle fill="#fff" cx="36" cy="18" r="1"> <animateTransform attributeName="transform" type="rotate" from="0 18 18" to="360 18 18" dur="0.9s" repeatCount="indefinite"/> </circle> </g> </g></svg>';
                Utils.createStyle.call(this.component, COMPONENT_NAME, ".spinner", "position:absolute;top:50%;left:50%;width:38px;height:38px;transform:translate(-50%,-50%)");
                this._video.removeAttribute("controls");
                this.container.appendChild(this._video);
                this.video = {
                    cueVideoById: function(src) {
                        var htmlElem = document.getElementsByTagName("html")[0];
                        var isInception = htmlElem.hasAttribute("monet-inception-pristine-element");
                        if (typeof Enabler !== "undefined" && !isInception) {
                            this._video.src = Enabler.getUrl(src);
                        } else {
                            this._video.src = src;
                        }
                    }.bind(this),
                    getDuration: function() {
                        return this._video.duration;
                    }.bind(this),
                    getCurrentTime: function() {
                        return this._video.currentTime;
                    }.bind(this),
                    isMuted: function() {
                        return this._video.muted;
                    }.bind(this),
                    pauseVideo: function() {
                        this._video.pause();
                    }.bind(this),
                    playVideo: function() {
                        this._video.play();
                    }.bind(this),
                    unMute: function() {
                        this._video.muted = false;
                    }.bind(this),
                    mute: function() {
                        this._video.muted = true;
                    }.bind(this),
                    seekTo: function(t) {
                        this._video.currentTime = t;
                    }.bind(this)
                };
                this.resize();
                setEvents.call(this);
                this.hide();
                if (Utils.isAutoplayAvailable() && this.config.autoplay === true) {
                    if (typeof gwd != "undefined") {
                        this.show();
                        this.setSource(0);
                        this._video.setAttribute("autoplay", "");
                        if (Utils.isMobile) {
                            this._video.setAttribute("playsinline", "");
                            this._video.setAttribute("muted", "");
                        }
                    } else {
                        this.play(0);
                    }
                }
                if (typeof Enabler != "undefined") Enabler.loadModule(studio.module.ModuleId.VIDEO, function() {
                    studio.video.Reporter.attach("Video " + this.video_id, this._video);
                }.bind(this));
            }
            function style() {
                Utils.createStyle.call(this.component, COMPONENT_NAME, ".hide", "border: 0 !important;clip: rect(0 0 0 0) !important;height: 1px !important;margin: -1px !important;overflow: hidden !important;padding: 0 !important;position: absolute !important;width: 1px !important;", [ ".hide", true ], "border: 0 !important;clip: rect(0 0 0 0) !important;height: 1px !important;margin: -1px !important;overflow: hidden !important;padding: 0 !important;position: absolute !important;width: 1px !important;", ".netflix-video", "background-color:#000; position: absolute; top: 0; left: 0;", ".netflix-video .netflix-video-container", "position:absolute;top:0;left:0;", ".netflix-video .videoClick", "position:absolute;top:0;left:0;cursor:pointer;width:100%;height:100%;background:url(data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7);", ".netflix-video .close", "position:absolute;top:10px;left:10px;z-index:15;cursor:pointer;width:" + this.config.closeButtonSize + "px;height:" + this.config.closeButtonSize + "px;overflow:hidden;", ".netflix-video .videoPanels", "width:100%;height:100%;position:absolute;pointer-events:none;", ".netflix-video .iVideoPanels", "width:0;height:0;position:absolute;", ".netflix-video .controls", "z-index:12;position:absolute;bottom:27px;width:100%;height:0;", ".netflix-video .playButton.v_icon", "margin-left:5px;", ".netflix-video .v_icon", "width:25px;height:25px;float:left;cursor:pointer;", ".netflix-video .timer", "float:left;font-family:Arial,sans-serif;font-weight:700;font-size:12px;letter-spacing:1px;text-shadow:0 1px 2px rgba(0,0,0,.5);line-height:26px;margin-left:9px;pointer-events:none;");
            }
            function svgButton(id, hover) {
                var i = document.createElementNS("http://www.w3.org/2000/svg", "svg");
                i.setAttribute("width", "25px");
                i.setAttribute("height", "25px");
                i.setAttribute("viewBox", "0 0 50 50");
                i.id = id || "";
                i.hover = hover;
                return i;
            }
            function createCloseButton() {
                var w = 20;
                var i = document.createElementNS("http://www.w3.org/2000/svg", "svg");
                i.setAttribute("width", w + "px");
                i.setAttribute("height", w + "px");
                i.fill = new Utils.SvgIcon("closeButtonFill", "M0," + w / 2 + "a" + w / 2 + "," + w / 2 + " 0 1,0 " + w + ",0a" + w / 2 + "," + w / 2 + " 0 1,0 -" + w + ",0", this.config.closeColors[0]);
                var a = Math.round(w * .7);
                var b = w - a;
                i.cross = new Utils.SvgIcon("line1", "M" + b + " " + b + " L" + a + " " + a + " M" + a + " " + b + " L" + b + " " + a + "");
                i.cross.setAttribute("stroke", this.config.closeColors[1]);
                i.cross.setAttribute("stroke-width", w < 15 ? 1 : 2);
                i.appendChild(i.fill);
                i.appendChild(i.cross);
                return i;
            }
            function buildControls() {
                this.controls = document.createElement("div");
                this.bar = document.createElement("div");
                this.bar.classList.add("bar");
                this.bar.innerHTML = '<div class="track"></div>';
                this.barFill = document.createElement("div");
                this.barFill.classList.add("fill");
                this.barFill.style.backgroundColor = this.config.colors[0];
                this.barIndicator = document.createElement("div");
                this.barIndicator.classList.add("indicator");
                this.barIndicator.style.backgroundColor = this.config.colors[0];
                this.bar.appendChild(this.barFill);
                this.bar.appendChild(this.barIndicator);
                Utils.hide(this.barIndicator);
                Utils.hide(this.bar);
                Utils.createStyle.call(this.component, COMPONENT_NAME, ".bar", "height:15px; position: absolute; top: -10px; left: 10px; cursor:pointer;", ".bar .track", "width:100%;height:1px; background-color: " + this.config.colors[1] + ";position: absolute; top: 10px; left: 0;", ".bar .fill", "height:1px; position: absolute; top: 10px; left: 0;", ".bar .indicator", "width:10px;height:10px; border-radius:5px; position: absolute; top: 5px; left: 0px;background-color:" + this.config.colors[1] + ";pointer-events: none;");
                if (this.config.controlsAutoHide) {
                    this.controls.addEventListener("mouseover", function() {
                        TweenMax.to(this.controls, .3, {
                            alpha: 1,
                            ease: Cubic.easeOut
                        });
                    }.bind(this));
                    this.controls.addEventListener("mouseout", function() {
                        if (this.playing) {
                            TweenMax.to(this.controls, 1, {
                                alpha: 0,
                                ease: Cubic.easeOut
                            });
                        }
                    }.bind(this));
                    this.clickArea.addEventListener("mouseover", function() {
                        TweenMax.to(this.controls, .3, {
                            alpha: 1,
                            ease: Cubic.easeOut
                        });
                    }.bind(this));
                    this.clickArea.addEventListener("mouseout", function() {
                        if (this.playing) {
                            TweenMax.to(this.controls, 1, {
                                alpha: 0,
                                ease: Cubic.easeOut
                            });
                        }
                    }.bind(this));
                }
                this.bar.addEventListener("click", function(e) {
                    var p = e.offsetX / this.bar.getBoundingClientRect().width;
                    this.seek(this.video.getDuration() * p);
                }.bind(this));
                this.bar.addEventListener("mouseover", function() {
                    Utils.show(this.barIndicator);
                    this.barFill.seeking = true;
                    this.barFill.current = this.barFill.style.width;
                }.bind(this));
                this.bar.addEventListener("mouseout", function() {
                    this.barFill.seeking = false;
                    Utils.hide(this.barIndicator);
                    this.barFill.style.width = this.barFill.current;
                }.bind(this));
                this.bar.addEventListener("mousemove", function(e) {
                    if (e.offsetX < this.bar.getBoundingClientRect().width - 6 && e.offsetX > 6) TweenMax.set(this.barIndicator, {
                        x: e.offsetX - 6
                    });
                    var p = e.offsetX / this.bar.getBoundingClientRect().width * 100;
                    TweenMax.set(this.barFill, {
                        width: p + "%"
                    });
                }.bind(this));
                this.playButton = new svgButton(null, "M16,15 L16,35 24,30 24,19 M24,19 L24,30 35,25 35,25");
                this.playButton.icon = new Utils.SvgIcon("svgIcon", "M16,15 L16,36 23,36 23,15 M28,15 L28,36 35,36 35,15", this.config.colors[0]);
                this.playButton.appendChild(this.playButton.icon);
                this.playButton.tween = {
                    play: function() {
                        this.icon.setAttributeNS(null, "d", this.hover);
                    }.bind(this.playButton),
                    reverse: function() {
                        this.icon.setAttributeNS(null, "d", this.icon.getAttribute("data-original"));
                    }.bind(this.playButton)
                };
                this.muteButton = new svgButton(null, "M35,20 L46,31 M35,31 L46,20");
                this.muteButton.fill = new Utils.SvgIcon("", "M13,20 L13,31 21,31 29,37 31,37 31,14 29,14 21,20 13,20 M35,20 L45,30", this.config.colors[0]);
                this.muteButton.appendChild(this.muteButton.fill);
                this.muteButton.icon = new Utils.SvgIcon("svgIcon", "M35,20 A5,5 0 0,1 35,31", this.config.colors[0]);
                this.muteButton.icon.setAttribute("stroke", this.config.colors[0]);
                this.muteButton.icon.setAttribute("stroke-width", "3");
                this.muteButton.icon.setAttribute("fill-opacity", "0");
                this.muteButton.appendChild(this.muteButton.icon);
                this.muteButton.tween = {
                    play: function() {
                        this.icon.setAttributeNS(null, "d", this.hover);
                    }.bind(this.muteButton),
                    reverse: function() {
                        this.icon.setAttributeNS(null, "d", this.icon.getAttribute("data-original"));
                    }.bind(this.muteButton)
                };
                this.timerView = document.createElement("div");
                this.playButton.classList.add("playButton");
                this.playButton.classList.add("v_icon");
                this.muteButton.classList.add("muteButton");
                this.muteButton.classList.add("v_icon");
                this.timerView.className = "timer";
                this.timerView.style.color = this.config.colors[0];
                this.controls.classList.add("controls");
                this.controls.appendChild(this.playButton);
                this.controls.appendChild(this.muteButton);
                this.controls.appendChild(this.timerView);
                this.controls.appendChild(this.bar);
                this.wrapper.appendChild(this.controls);
                if (Utils.isiOS) Utils.hide(this.muteButton);
                this.playButton.addEventListener("click", togglePlay.bind(this));
                this.playButton.addEventListener("mouseover", function() {
                    TweenMax.to(this.playButton.icon, .2, {
                        fill: this.config.colors[1],
                        ease: Quad.easeOut
                    });
                }.bind(this));
                this.playButton.addEventListener("mouseout", function() {
                    TweenMax.to(this.playButton.icon, .2, {
                        fill: this.config.colors[0],
                        ease: Quad.easeOut
                    });
                }.bind(this));
                this.muteButton.addEventListener("click", toggleMute.bind(this));
                this.muteButton.addEventListener("mouseover", function() {
                    TweenMax.to(this.muteButton.icon, .2, {
                        fill: this.config.colors[1],
                        stroke: this.config.colors[1],
                        ease: Quad.easeOut
                    });
                    TweenMax.to(this.muteButton.fill, .2, {
                        fill: this.config.colors[1],
                        ease: Quad.easeOut
                    });
                }.bind(this));
                this.muteButton.addEventListener("mouseout", function() {
                    TweenMax.to(this.muteButton.icon, .2, {
                        stroke: this.config.colors[0],
                        ease: Quad.easeOut
                    });
                    TweenMax.to(this.muteButton.fill, .2, {
                        fill: this.config.colors[0],
                        ease: Quad.easeOut
                    });
                }.bind(this));
                if (this.config.customControlsMobile) {
                    TweenMax.set([ this.playButton, this.muteButton ], {
                        scale: 1.5
                    });
                }
                this.playButton.classList.remove("pause");
                this.playButton.tween.play();
            }
            function togglePlay() {
                if (this._video.paused) {
                    this.resume();
                } else {
                    this.pause();
                }
            }
            function toggleMute() {
                if (this.video.isMuted()) {
                    this.unmute();
                } else {
                    this.mute();
                }
            }
            function startTimer() {
                clearInterval(this.timer);
                this.playing = true;
                this.component.playing = true;
                this.timer = setInterval(function setInterval() {
                    timeStep.call(this);
                }.bind(this), 10);
                timeStep.call(this);
            }
            function timeStep() {
                if (this.video.getDuration()) {
                    setTimeDisplay.call(this);
                    var p = this.video.getCurrentTime() / this.video.getDuration();
                    if (!this.barFill.seeking) this.barFill.style.width = p * 100 + "%";
                }
                this.component.dispatch("video-time", {
                    currentTime: this.video.getCurrentTime(),
                    duration: this.video.getDuration() || 0,
                    target: this.component
                });
                switch (Math.round(p * 100)) {
                  case 25:
                    if (!this.currentVideo.firstQuart) {
                        Utils.tracker("VIDEO_FIRST_QUART", this.currentVideo.source, {
                            time: this.video.getCurrentTime()
                        });
                        this.currentVideo.firstQuart = true;
                    }
                    break;

                  case 50:
                    if (!this.currentVideo.secondQuart) {
                        Utils.tracker("VIDEO_SECOND_QUART", this.currentVideo.source, {
                            time: this.video.getCurrentTime()
                        });
                        this.currentVideo.secondQuart = true;
                    }
                    break;

                  case 75:
                    if (!this.currentVideo.thirdQuart) {
                        Utils.tracker("VIDEO_THIRD_QUART", this.currentVideo.source, {
                            time: this.video.getCurrentTime()
                        });
                        this.currentVideo.thirdQuart = true;
                    }
                    break;
                }
            }
            function setTimeDisplay(current) {
                this.timerView.innerHTML = this.timerView.innerHTML = Utils.timeFormat(current || Math.round(this.video.getCurrentTime())) + " / " + Utils.timeFormat(Math.round(this.video.getDuration()));
            }
            function setEvents() {
                this.clickArea.addEventListener("click", onVideoClick.bind(this));
                this.closeFunction = this.close.bind(this);
                this.closeButton.addEventListener("click", this.closeFunction);
                this.closeButton.addEventListener("mouseover", function() {
                    TweenMax.to(this.closeButton.fill, .3, {
                        fill: this.config.closeColors[1],
                        ease: Quad.easeOut
                    });
                    this.closeButton.cross.setAttribute("stroke", this.config.closeColors[0]);
                }.bind(this));
                this.closeButton.addEventListener("mouseout", function() {
                    TweenMax.to(this.closeButton.fill, .3, {
                        fill: this.config.closeColors[0],
                        ease: Quad.easeOut
                    });
                    this.closeButton.cross.setAttribute("stroke", this.config.closeColors[1]);
                }.bind(this));
            }
            function onVideoClick() {
                this.component.dispatch("video-click");
            }
            function onStateChanged(e) {
                switch (e.data != undefined ? e.data : e.type) {
                  case "ended":
                    this.active = false;
                    onVideoEnded.call(this);
                    break;

                  case "loadeddata":
                    if (!this.active || this.initPlay) {
                        this.initPlay = false;
                        onVideoPlay.call(this);
                    }
                    this.active = true;
                    break;

                  case "pause":
                    this.component.dispatch("video-pause");
                    onVideoPause.call(this);
                    break;

                  case "play":
                    if (this.ended) onVideoPlay.call(this);
                    this.ended = false;
                    Utils.tracker("VIDEO_PLAY", this.currentVideo.source, {
                        time: this.video.getCurrentTime()
                    });
                    this.component.dispatch("video-play");
                    break;
                }
            }
            function onVideoEnded() {
                if (this.currentVideo.hideOnComplete) {
                    this.hide();
                }
                this.stopTimer();
                this.initPlay = true;
                this.ended = true;
                this.playing = false;
                this.playButton.classList.remove("pause");
                this.playButton.tween.play();
                this.barFill.style.width = "100%";
                this.barFill.current = this.barFill.style.width;
                Utils.tracker("VIDEO_COMPLETE", this.currentVideo.source, {
                    time: this.video.getCurrentTime()
                });
                this.component.dispatch("video-complete");
                this.currentVideo.completed++;
            }
            function onVideoPlay() {
                startTimer.call(this);
                Utils.show(this.container);
                this.playButton.classList.add("pause");
                this.playButton.tween.reverse();
                if (this.config.controlsAutoHide && this.config.controlsAutoHide[this.id]) {
                    TweenMax.to(this.controls, 2, {
                        alpha: 0,
                        delay: 2,
                        ease: Cubic.easeOut
                    });
                }
                this.currentVideo.duration = this.video.duration;
                if (this.autoplay == true) {
                    this.autoplay = false;
                }
                this.currentVideo.plays++;
            }
            function onVideoPause() {
                this.playButton.classList.remove("pause");
                this.playButton.tween.play();
                Utils.tracker("VIDEO_PAUSE", this.currentVideo.source, {
                    time: this.video.getCurrentTime()
                });
            }
        }
        NetflixVideo.prototype.resize = function(size) {
            size = size || {};
            var i = this.config.size[this.id] ? this.id : 0;
            this.previousSize = {
                width: this.width,
                height: this.height
            };
            this.width = size.width || this.config.size[i].width;
            this.height = size.height || this.config.size[i].height;
            this.container.setAttribute("width", this.width);
            this.container.setAttribute("height", this.height);
            TweenMax.set(this.bar, {
                width: this.width - 20
            });
            TweenMax.set([ this.container, this._video, this.wrapper, this.component ], {
                width: this.width,
                height: this.height
            });
        };
        NetflixVideo.prototype.setSource = function(id) {
            this.videoLoaded = this.currentVideo === this.sources[id];
            this.currentVideo = this.sources[id];
            this.currentVideo.firstQuart = false;
            this.currentVideo.secondQuart = false;
            this.currentVideo.thirdQuart = false;
            this.video.id = "video_" + id;
            this.active = false;
            this.resize(this.config.size[id]);
            if (this.config.showBar[id] !== undefined) {
                if (this.config.showBar[id]) Utils.show(this.bar); else Utils.hide(this.bar);
            } else {
                if (this.config.showBar[0]) Utils.show(this.bar); else Utils.hide(this.bar);
            }
            if (!this.currentVideo.customControls) this.disableCustomControls();
            if (this.currentVideo.controls) this.enableControls();
            if (!this.currentVideo.controls) this.disableControls();
            if (this.currentVideo.customControls) this.enableCustomControls();
            this.playHistory = this.playHistory || [];
            this.playHistory.push(this.currentVideo);
            if (this.currentVideo.muted) {
                this.mute();
            } else {
                this.unmute();
            }
            this.timerView.innerHTML = "";
            this.video.cueVideoById(this.currentVideo.source);
        };
        NetflixVideo.prototype.play = function(id) {
            this.initPlay = true;
            if (id === -1) {
                this.autoplay = true;
            }
            if (!this.sources.length) return;
            id = this.sources[id] ? id : this.currentVideo ? this.currentVideo._id : 0;
            if (this.config.fullscreen[typeof this.config.fullscreen[id] === "undefined" ? 0 : id] && id !== -1) {
                this.enterFullscreen();
            }
            this.load(id);
            this.videoPlays = this.videoPlays || {};
            this.videoPlays[id] = this.videoPlays[id] ? this.videoPlays[id] + 1 : 1;
            this.resume();
        };
        NetflixVideo.prototype.pause = function(time) {
            this.initPlay = true;
            this.video.pauseVideo();
            if (time !== null && time !== undefined) {
                this.seek(time);
            }
            this.playing = false;
            this.component.playing = false;
        };
        NetflixVideo.prototype.stop = function() {
            this.initPlay = true;
            if (this._video.ended) return;
            this.pause(0, false);
            this.active = false;
            Utils.tracker("VIDEO_STOP", this.currentVideo.source, {
                time: this.video.getCurrentTime()
            });
            this.stopTimer();
        };
        NetflixVideo.prototype.resume = function() {
            this.playing = true;
            this.component.playing = true;
            this.video.playVideo();
            this.playButton.classList.add("pause");
            this.playButton.tween.reverse();
        };
        NetflixVideo.prototype.seek = function(time) {
            this.video.seekTo(time || 0);
            this.barFill.current = this.barFill.style.width;
        };
        NetflixVideo.prototype.unmute = function() {
            this.video.unMute();
            this.currentVideo.muted = false;
            Utils.show(this.muteButton);
            this.muteButton.classList.add("unmute");
            this.muteButton.tween.reverse();
            Utils.tracker("VIDEO_UNMUTE", this.currentVideo.source, {
                time: this.video.getCurrentTime()
            });
        };
        NetflixVideo.prototype.mute = function() {
            this.video.mute();
            this.currentVideo.muted = true;
            this.muteButton.classList.remove("unmute");
            this.muteButton.tween.play();
            Utils.tracker("VIDEO_MUTE", this.currentVideo.source, {
                time: this.video.getCurrentTime()
            });
        };
        NetflixVideo.prototype.load = function(id) {
            if (!this.sources.length) return;
            this.show();
            this.setSource(id);
            if (this._video) this._video.load();
        };
        NetflixVideo.prototype.hide = function() {
            this.pause(null, false);
            Utils.hide(this.component);
            Utils.hide(this.container);
            Utils.hide(this.wrapper);
            this.stopTimer();
            this.active = false;
        };
        NetflixVideo.prototype.show = function() {
            Utils.show(this.component);
            Utils.show(this.wrapper);
            Utils.show(this.container);
        };
        NetflixVideo.prototype.close = function() {
            this.hide();
            if (this.currentVideo && this.currentVideo.source) {
                Utils.tracker("VIDEO_STOP", this.currentVideo.source, {
                    time: this.video.getCurrentTime()
                });
            }
            this.component.dispatch("video-close");
        };
        NetflixVideo.prototype.enableCustomControls = function() {
            Utils.show(this.controls);
            Utils.show(this.clickArea);
            this._video.removeAttribute("controls");
        };
        NetflixVideo.prototype.disableCustomControls = function() {
            Utils.hide(this.controls);
            Utils.hide(this.clickArea);
            this._video.setAttribute("controls", "controls");
        };
        NetflixVideo.prototype.enableControls = function() {
            Utils.hide(this.clickArea);
            this._video.setAttribute("controls", "controls");
        };
        NetflixVideo.prototype.disableControls = function() {
            Utils.show(this.clickArea);
            this._video.removeAttribute("controls");
        };
        return NetflixVideo;
    }();
    (function() {
        var component = Object.create(HTMLElement.prototype, {
            createdCallback: {
                value: function() {},
                enumerable: true
            },
            attachedCallback: {
                value: function() {
                    if (this._attached) return;
                    this._attached = true;
                    this.width = parseInt(this.getAttribute("width") || this.offsetWidth);
                    this.height = parseInt(this.getAttribute("height") || this.offsetHeight);
                    var elements = document.querySelectorAll("netflix-video");
                    for (var i = 0; i < elements.length; i++) {
                        elements[i].setAttribute("video_id", i + 1);
                        elements[i].style.position = "absolute";
                    }
                    var config = this.config = {};
                    config.size = [ {
                        width: this.width,
                        height: this.height
                    } ];
                    config.sources = [ this.getAttribute("source") ];
                    config.closeButtonSize = 20;
                    config.colors = [ this.getAttribute("color-1"), this.getAttribute("color-2") ];
                    config.showBar = [ true ];
                    config.controlsAutoHide = [ true ];
                    config.closeColors = [ this.getAttribute("close-color-1") || this.getAttribute("color-1"), this.getAttribute("close-color-2") || this.getAttribute("color-2") ];
                    config.hideOnComplete = [ this.hasAttribute("hideOnComplete") ];
                    config.customControls = [ this.hasAttribute("controls") ];
                    config.controls = [ false ];
                    config.fullscreen = [ this.hasAttribute("fullscreen") ];
                    config.muted = [ this.hasAttribute("muted") ];
                    config.autoplay = this.hasAttribute("autoplay");
                    if (config.autoplay) {
                        config.muted[0] = true;
                    }
                    if (Utils.isMobile) {
                        config.controls = [ true ];
                        config.customControls = [ false ];
                    }
                    if (!this.getAttribute("data-dynamic-key")) {
                        window.addEventListener("adinitialized", function() {
                            this.video = new NetflixVideo(this, config);
                        }.bind(this), false);
                    } else {
                        var videoComponent = this;
                        var MonetComponent = document.querySelector("monet-integrator");
                        if (MonetComponent) {
                            MonetComponent.register(this);
                            MonetComponent.getMonetData().then(function(data) {
                                var d = videoComponent.getAttribute("data-dynamic-key");
                                try {
                                    config.sources = getVideoNode(data, d);
                                    this.video = new NetflixVideo(this, config);
                                    this.dispatchEvent(new CustomEvent("ready"));
                                } catch (e) {
                                    console.error("Monet dynamic ID:", d, "not found in JSON. Trying backup");
                                    MonetComponent.getBackupMonetData().then(function(backupData) {
                                        console.log(backupData);
                                        config.sources = getVideoNode(backupData, d);
                                        this.video = new NetflixVideo(this, config);
                                        this.dispatchEvent(new CustomEvent("ready"));
                                    }.bind(this), function(error) {
                                        console.error("Failed to load backup Monet data", error);
                                    });
                                }
                            }.bind(this), function(error) {
                                console.error("Failed to load Monet data", error);
                            });
                        } else {
                            this.video = new NetflixVideo(this, config);
                            this.dispatchEvent(new CustomEvent("ready"));
                        }
                    }
                    function getVideoNode(data, key) {
                        var r = data.rootAssets;
                        var types = [ "video", "url" ];
                        for (var i = 0; i < 2; i++) {
                            var combo = types[i] + "." + key;
                            if (r[combo]) {
                                return [ r[combo].url ];
                            }
                        }
                        throw new Error("Monet dynamic ID: " + key + " not found in backup JSON");
                    }
                },
                enumerable: true
            },
            play: {
                value: function() {
                    if (this.video) {
                        this.video.play();
                    }
                }
            },
            pause: {
                value: function() {
                    if (this.video) {
                        this.video.pause();
                    }
                }
            },
            close: {
                value: function() {
                    if (this.video) {
                        this.video.close();
                    }
                }
            },
            mute: {
                value: function() {
                    this.video.mute();
                }
            },
            unmute: {
                value: function() {
                    this.video.unmute();
                }
            },
            seek: {
                value: function(t) {
                    this.video.seek(t);
                }
            },
            resize: {
                value: function(w, h) {
                    this.video.resize({
                        width: w,
                        height: h
                    });
                }
            },
            dispatch: {
                value: function(e, d) {
                    c = document.createEvent("CustomEvent");
                    c.initCustomEvent(e, !0, !0, d);
                    this.dispatchEvent(c);
                }
            },
            preview: {
                value: function() {
                    this.video = new NetflixVideo(this, this.config);
                }
            }
        });
        document.registerElement(COMPONENT_NAME, {
            prototype: component
        });
    })();
})();

var _gsScope = "undefined" != typeof module && module.exports && "undefined" != typeof global ? global : this || window;

(_gsScope._gsQueue || (_gsScope._gsQueue = [])).push(function() {
    "use strict";
    var a = Math.PI / 180, b = 180 / Math.PI, c = /[achlmqstvz]|(-?\d*\.?\d*(?:e[\-+]?\d+)?)[0-9]/gi, d = /(?:(-|-=|\+=)?\d*\.?\d*(?:e[\-+]?\d+)?)[0-9]/gi, e = /[achlmqstvz]/gi, f = _gsScope.TweenLite, g = function(a) {
        window.console && console.log(a);
    }, h = function(b, c) {
        var d, e, f, g, h, i, j = Math.ceil(Math.abs(c) / 90), k = 0, l = [];
        for (b *= a, c *= a, d = c / j, e = 4 / 3 * Math.sin(d / 2) / (1 + Math.cos(d / 2)), 
        i = 0; j > i; i++) f = b + i * d, g = Math.cos(f), h = Math.sin(f), l[k++] = g - e * h, 
        l[k++] = h + e * g, f += d, g = Math.cos(f), h = Math.sin(f), l[k++] = g + e * h, 
        l[k++] = h - e * g, l[k++] = g, l[k++] = h;
        return l;
    }, i = function(c, d, e, f, g, i, j, k, l) {
        if (c !== k || d !== l) {
            e = Math.abs(e), f = Math.abs(f);
            var m = g % 360 * a, n = Math.cos(m), o = Math.sin(m), p = (c - k) / 2, q = (d - l) / 2, r = n * p + o * q, s = -o * p + n * q, t = e * e, u = f * f, v = r * r, w = s * s, x = v / t + w / u;
            x > 1 && (e = Math.sqrt(x) * e, f = Math.sqrt(x) * f, t = e * e, u = f * f);
            var y = i === j ? -1 : 1, z = (t * u - t * w - u * v) / (t * w + u * v);
            0 > z && (z = 0);
            var A = y * Math.sqrt(z), B = A * (e * s / f), C = A * -(f * r / e), D = (c + k) / 2, E = (d + l) / 2, F = D + (n * B - o * C), G = E + (o * B + n * C), H = (r - B) / e, I = (s - C) / f, J = (-r - B) / e, K = (-s - C) / f, L = Math.sqrt(H * H + I * I), M = H;
            y = 0 > I ? -1 : 1;
            var N = y * Math.acos(M / L) * b;
            L = Math.sqrt((H * H + I * I) * (J * J + K * K)), M = H * J + I * K, y = 0 > H * K - I * J ? -1 : 1;
            var O = y * Math.acos(M / L) * b;
            !j && O > 0 ? O -= 360 : j && 0 > O && (O += 360), O %= 360, N %= 360;
            var P, Q, R, S = h(N, O), T = n * e, U = o * e, V = o * -f, W = n * f, X = S.length - 2;
            for (P = 0; X > P; P += 2) Q = S[P], R = S[P + 1], S[P] = Q * T + R * V + F, S[P + 1] = Q * U + R * W + G;
            return S[S.length - 2] = k, S[S.length - 1] = l, S;
        }
    }, j = function(a) {
        var b, d, e, f, h, j, k, l, m, n, o, p, q, r = (a + "").match(c) || [], s = [], t = 0, u = 0, v = r.length, w = 2, x = 0;
        if (!a || !isNaN(r[0]) || isNaN(r[1])) return g("ERROR: malformed path data: " + a), 
        s;
        for (b = 0; v > b; b++) if (q = h, isNaN(r[b]) ? (h = r[b].toUpperCase(), j = h !== r[b]) : b--, 
        e = +r[b + 1], f = +r[b + 2], j && (e += t, f += u), 0 === b && (l = e, m = f), 
        "M" === h) k && k.length < 8 && (s.length -= 1, w = 0), t = l = e, u = m = f, k = [ e, f ], 
        x += w, w = 2, s.push(k), b += 2, h = "L"; else if ("C" === h) k || (k = [ 0, 0 ]), 
        k[w++] = e, k[w++] = f, j || (t = u = 0), k[w++] = t + 1 * r[b + 3], k[w++] = u + 1 * r[b + 4], 
        k[w++] = t += 1 * r[b + 5], k[w++] = u += 1 * r[b + 6], b += 6; else if ("S" === h) "C" === q || "S" === q ? (n = t - k[w - 4], 
        o = u - k[w - 3], k[w++] = t + n, k[w++] = u + o) : (k[w++] = t, k[w++] = u), k[w++] = e, 
        k[w++] = f, j || (t = u = 0), k[w++] = t += 1 * r[b + 3], k[w++] = u += 1 * r[b + 4], 
        b += 4; else if ("Q" === h) n = e - t, o = f - u, k[w++] = t + 2 * n / 3, k[w++] = u + 2 * o / 3, 
        j || (t = u = 0), t += 1 * r[b + 3], u += 1 * r[b + 4], n = e - t, o = f - u, k[w++] = t + 2 * n / 3, 
        k[w++] = u + 2 * o / 3, k[w++] = t, k[w++] = u, b += 4; else if ("T" === h) n = t - k[w - 4], 
        o = u - k[w - 3], k[w++] = t + n, k[w++] = u + o, n = t + 1.5 * n - e, o = u + 1.5 * o - f, 
        k[w++] = e + 2 * n / 3, k[w++] = f + 2 * o / 3, k[w++] = t = e, k[w++] = u = f, 
        b += 2; else if ("H" === h) f = u, k[w++] = t + (e - t) / 3, k[w++] = u + (f - u) / 3, 
        k[w++] = t + 2 * (e - t) / 3, k[w++] = u + 2 * (f - u) / 3, k[w++] = t = e, k[w++] = f, 
        b += 1; else if ("V" === h) f = e, e = t, j && (f += u - t), k[w++] = e, k[w++] = u + (f - u) / 3, 
        k[w++] = e, k[w++] = u + 2 * (f - u) / 3, k[w++] = e, k[w++] = u = f, b += 1; else if ("L" === h || "Z" === h) "Z" === h && (e = l, 
        f = m, k.closed = !0), ("L" === h || Math.abs(t - e) > .5 || Math.abs(u - f) > .5) && (k[w++] = t + (e - t) / 3, 
        k[w++] = u + (f - u) / 3, k[w++] = t + 2 * (e - t) / 3, k[w++] = u + 2 * (f - u) / 3, 
        k[w++] = e, k[w++] = f, "L" === h && (b += 2)), t = e, u = f; else if ("A" === h) {
            for (p = i(t, u, 1 * r[b + 1], 1 * r[b + 2], 1 * r[b + 3], 1 * r[b + 4], 1 * r[b + 5], (j ? t : 0) + 1 * r[b + 6], (j ? u : 0) + 1 * r[b + 7]), 
            d = 0; d < p.length; d++) k[w++] = p[d];
            t = k[w - 2], u = k[w - 1], b += 7;
        } else g("Error: malformed path data: " + a);
        return s.totalPoints = x + w, s;
    }, k = function(a, b) {
        var c, d, e, f, g, h, i, j, k, l, m, n, o, p, q = 0, r = .999999, s = a.length, t = b / ((s - 2) / 6);
        for (o = 2; s > o; o += 6) for (q += t; q > r; ) c = a[o - 2], d = a[o - 1], e = a[o], 
        f = a[o + 1], g = a[o + 2], h = a[o + 3], i = a[o + 4], j = a[o + 5], p = 1 / (Math.floor(q) + 1), 
        k = c + (e - c) * p, m = e + (g - e) * p, k += (m - k) * p, m += (g + (i - g) * p - m) * p, 
        l = d + (f - d) * p, n = f + (h - f) * p, l += (n - l) * p, n += (h + (j - h) * p - n) * p, 
        a.splice(o, 4, c + (e - c) * p, d + (f - d) * p, k, l, k + (m - k) * p, l + (n - l) * p, m, n, g + (i - g) * p, h + (j - h) * p), 
        o += 6, s += 6, q--;
        return a;
    }, l = function(a) {
        var b, c, d, e, f = "", g = a.length, h = 100;
        for (c = 0; g > c; c++) {
            for (e = a[c], f += "M" + e[0] + "," + e[1] + " C", b = e.length, d = 2; b > d; d++) f += (e[d++] * h | 0) / h + "," + (e[d++] * h | 0) / h + " " + (e[d++] * h | 0) / h + "," + (e[d++] * h | 0) / h + " " + (e[d++] * h | 0) / h + "," + (e[d] * h | 0) / h + " ";
            e.closed && (f += "z");
        }
        return f;
    }, m = function(a) {
        for (var b = [], c = a.length - 1, d = 0; --c > -1; ) b[d++] = a[c], b[d++] = a[c + 1], 
        c--;
        for (c = 0; d > c; c++) a[c] = b[c];
        a.reversed = a.reversed ? !1 : !0;
    }, n = function(a) {
        var b, c = a.length, d = 0, e = 0;
        for (b = 0; c > b; b++) d += a[b++], e += a[b];
        return [ d / (c / 2), e / (c / 2) ];
    }, o = function(a) {
        var b, c, d, e = a.length, f = a[0], g = f, h = a[1], i = h;
        for (d = 6; e > d; d += 6) b = a[d], c = a[d + 1], b > f ? f = b : g > b && (g = b), 
        c > h ? h = c : i > c && (i = c);
        return a.centerX = (f + g) / 2, a.centerY = (h + i) / 2, a.size = (f - g) * (h - i);
    }, p = function(a) {
        for (var b, c, d, e, f, g = a.length, h = a[0][0], i = h, j = a[0][1], k = j; --g > -1; ) for (f = a[g], 
        b = f.length, e = 6; b > e; e += 6) c = f[e], d = f[e + 1], c > h ? h = c : i > c && (i = c), 
        d > j ? j = d : k > d && (k = d);
        return a.centerX = (h + i) / 2, a.centerY = (j + k) / 2, a.size = (h - i) * (j - k);
    }, q = function(a, b) {
        return b.length - a.length;
    }, r = function(a, b) {
        var c = a.size || o(a), d = b.size || o(b);
        return Math.abs(d - c) < (c + d) / 20 ? b.centerX - a.centerX || b.centerY - a.centerY : d - c;
    }, s = function(a, b) {
        var c, d, e = a.slice(0), f = a.length, g = f - 2;
        for (b = 0 | b, c = 0; f > c; c++) d = (c + b) % g, a[c++] = e[d], a[c] = e[d + 1];
    }, t = function(a, b, c, d, e) {
        var f, g, h, i, j = a.length, k = 0, l = j - 2;
        for (c *= 6, g = 0; j > g; g += 6) f = (g + c) % l, i = a[f] - (b[g] - d), h = a[f + 1] - (b[g + 1] - e), 
        k += Math.sqrt(h * h + i * i);
        return k;
    }, u = function(a, b, c) {
        var d, e, f, g = a.length, h = n(a), i = n(b), j = i[0] - h[0], k = i[1] - h[1], l = t(a, b, 0, j, k), o = 0;
        for (f = 6; g > f; f += 6) e = t(a, b, f / 6, j, k), l > e && (l = e, o = f);
        if (c) for (d = a.slice(0), m(d), f = 6; g > f; f += 6) e = t(d, b, f / 6, j, k), 
        l > e && (l = e, o = -f);
        return o / 6;
    }, v = function(a, b, c) {
        for (var d, e, f, g, h, i, j = a.length, k = 99999999999, l = 0, m = 0; --j > -1; ) for (d = a[j], 
        i = d.length, h = 0; i > h; h += 6) e = d[h] - b, f = d[h + 1] - c, g = Math.sqrt(e * e + f * f), 
        k > g && (k = g, l = d[h], m = d[h + 1]);
        return [ l, m ];
    }, w = function(a, b, c, d, e, f) {
        var g, h, i, j, k, l = b.length, m = 0, n = Math.min(a.size || o(a), b[c].size || o(b[c])) * d, p = 999999999999, q = a.centerX + e, r = a.centerY + f;
        for (h = c; l > h && (g = b[h].size || o(b[h]), !(n > g)); h++) i = b[h].centerX - q, 
        j = b[h].centerY - r, k = Math.sqrt(i * i + j * j), p > k && (m = h, p = k);
        return k = b[m], b.splice(m, 1), k;
    }, x = function(a, b, c, d) {
        var e, f, h, i, j, l, n, t = b.length - a.length, x = t > 0 ? b : a, y = t > 0 ? a : b, z = 0, A = "complexity" === d ? q : r, B = "position" === d ? 0 : "number" == typeof d ? d : .8, C = y.length, D = "object" == typeof c && c.push ? c.slice(0) : [ c ], E = "reverse" === D[0] || D[0] < 0, F = "log" === c;
        if (y[0]) {
            if (x.length > 1 && (a.sort(A), b.sort(A), l = x.size || p(x), l = y.size || p(y), 
            l = x.centerX - y.centerX, n = x.centerY - y.centerY, A === r)) for (C = 0; C < y.length; C++) x.splice(C, 0, w(y[C], x, C, B, l, n));
            if (t) for (0 > t && (t = -t), x[0].length > y[0].length && k(y[0], (x[0].length - y[0].length) / 6 | 0), 
            C = y.length; t > z; ) i = x[C].size || o(x[C]), h = v(y, x[C].centerX, x[C].centerY), 
            i = h[0], j = h[1], y[C++] = [ i, j, i, j, i, j, i, j ], y.totalPoints += 8, z++;
            for (C = 0; C < a.length; C++) e = b[C], f = a[C], t = e.length - f.length, 0 > t ? k(e, -t / 6 | 0) : t > 0 && k(f, t / 6 | 0), 
            E && !f.reversed && m(f), c = D[C] || 0 === D[C] ? D[C] : "auto", c && (f.closed || Math.abs(f[0] - f[f.length - 2]) < .5 && Math.abs(f[1] - f[f.length - 1]) < .5 ? "auto" === c || "log" === c ? (D[C] = c = u(f, e, 0 === C), 
            0 > c && (E = !0, m(f), c = -c), s(f, 6 * c)) : "reverse" !== c && (C && 0 > c && m(f), 
            s(f, 6 * (0 > c ? -c : c))) : !E && ("auto" === c && Math.abs(e[0] - f[0]) + Math.abs(e[1] - f[1]) + Math.abs(e[e.length - 2] - f[f.length - 2]) + Math.abs(e[e.length - 1] - f[f.length - 1]) > Math.abs(e[0] - f[f.length - 2]) + Math.abs(e[1] - f[f.length - 1]) + Math.abs(e[e.length - 2] - f[0]) + Math.abs(e[e.length - 1] - f[1]) || c % 2) ? (m(f), 
            D[C] = -1, E = !0) : "auto" === c ? D[C] = 0 : "reverse" === c && (D[C] = -1), f.closed !== e.closed && (f.closed = e.closed = !1));
            return F && g("shapeIndex:[" + D.join(",") + "]"), D;
        }
    }, y = function(a, b, c, d) {
        var e = j(a[0]), f = j(a[1]);
        x(e, f, b || 0 === b ? b : "auto", c) && (a[0] = l(e), a[1] = l(f), ("log" === d || d === !0) && g('precompile:["' + a[0] + '","' + a[1] + '"]'));
    }, z = function(a, b, c) {
        return b || c || a || 0 === a ? function(d) {
            y(d, a, b, c);
        } : y;
    }, A = function(a, b) {
        if (!b) return a;
        var c, e, f, g = a.match(d) || [], h = g.length, i = "";
        for ("reverse" === b ? (e = h - 1, c = -2) : (e = (2 * (parseInt(b, 10) || 0) + 1 + 100 * h) % h, 
        c = 2), f = 0; h > f; f += 2) i += g[e - 1] + "," + g[e] + " ", e = (e + c) % h;
        return i;
    }, B = function(a, b) {
        var c, d, e, f, g, h, i, j = 0, k = parseFloat(a[0]), l = parseFloat(a[1]), m = k + "," + l + " ", n = .999999;
        for (e = a.length, c = .5 * b / (.5 * e - 1), d = 0; e - 2 > d; d += 2) {
            if (j += c, h = parseFloat(a[d + 2]), i = parseFloat(a[d + 3]), j > n) for (g = 1 / (Math.floor(j) + 1), 
            f = 1; j > n; ) m += (k + (h - k) * g * f).toFixed(2) + "," + (l + (i - l) * g * f).toFixed(2) + " ", 
            j--, f++;
            m += h + "," + i + " ", k = h, l = i;
        }
        return m;
    }, C = function(a) {
        var b = a[0].match(d) || [], c = a[1].match(d) || [], e = c.length - b.length;
        e > 0 ? a[0] = B(b, e) : a[1] = B(c, -e);
    }, D = function(a) {
        return isNaN(a) ? C : function(b) {
            C(b), b[1] = A(b[1], parseInt(a, 10));
        };
    }, E = function(a, b) {
        var c = document.createElementNS("http://www.w3.org/2000/svg", "path"), d = Array.prototype.slice.call(a.attributes), e = d.length;
        for (b = "," + b + ","; --e > -1; ) -1 === b.indexOf("," + d[e].nodeName + ",") && c.setAttributeNS(null, d[e].nodeName, d[e].nodeValue);
        return c;
    }, F = function(a, b) {
        var c, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y = a.tagName.toLowerCase(), z = .552284749831;
        return "path" !== y && a.getBBox ? (i = E(a, "x,y,width,height,cx,cy,rx,ry,r,x1,x2,y1,y2,points"), 
        "rect" === y ? (g = +a.getAttribute("rx") || 0, h = +a.getAttribute("ry") || 0, 
        e = +a.getAttribute("x") || 0, f = +a.getAttribute("y") || 0, m = (+a.getAttribute("width") || 0) - 2 * g, 
        n = (+a.getAttribute("height") || 0) - 2 * h, g || h ? (o = e + g * (1 - z), p = e + g, 
        q = p + m, r = q + g * z, s = q + g, t = f + h * (1 - z), u = f + h, v = u + n, 
        w = v + h * z, x = v + h, c = "M" + s + "," + u + " V" + v + " C" + [ s, w, r, x, q, x, q - (q - p) / 3, x, p + (q - p) / 3, x, p, x, o, x, e, w, e, v, e, v - (v - u) / 3, e, u + (v - u) / 3, e, u, e, t, o, f, p, f, p + (q - p) / 3, f, q - (q - p) / 3, f, q, f, r, f, s, t, s, u ].join(",") + "z") : c = "M" + (e + m) + "," + f + " v" + n + " h" + -m + " v" + -n + " h" + m + "z") : "circle" === y || "ellipse" === y ? ("circle" === y ? (g = h = +a.getAttribute("r") || 0, 
        k = g * z) : (g = +a.getAttribute("rx") || 0, h = +a.getAttribute("ry") || 0, k = h * z), 
        e = +a.getAttribute("cx") || 0, f = +a.getAttribute("cy") || 0, j = g * z, c = "M" + (e + g) + "," + f + " C" + [ e + g, f + k, e + j, f + h, e, f + h, e - j, f + h, e - g, f + k, e - g, f, e - g, f - k, e - j, f - h, e, f - h, e + j, f - h, e + g, f - k, e + g, f ].join(",") + "z") : "line" === y ? c = "M" + a.getAttribute("x1") + "," + a.getAttribute("y1") + " L" + a.getAttribute("x2") + "," + a.getAttribute("y2") : ("polyline" === y || "polygon" === y) && (l = (a.getAttribute("points") + "").match(d) || [], 
        e = l.shift(), f = l.shift(), c = "M" + e + "," + f + " L" + l.join(","), "polygon" === y && (c += "," + e + "," + f + "z")), 
        i.setAttribute("d", c), b && a.parentNode && (a.parentNode.insertBefore(i, a), a.parentNode.removeChild(a)), 
        i) : a;
    }, G = function(a, b, c) {
        var e, h, i = "string" == typeof a;
        return (!i || (a.match(d) || []).length < 3) && (e = i ? f.selector(a) : [ a ], 
        e && e[0] ? (e = e[0], h = e.nodeName.toUpperCase(), b && "PATH" !== h && (e = F(e, !1), 
        h = "PATH"), a = e.getAttribute("PATH" === h ? "d" : "points") || "", e === c && (a = e.getAttributeNS(null, "data-original") || a)) : (g("WARNING: invalid morph to: " + a), 
        a = !1)), a;
    }, H = "Use MorphSVGPlugin.convertToPath(elementOrSelectorText) to convert to a path before morphing.", I = _gsScope._gsDefine.plugin({
        propName: "morphSVG",
        API: 2,
        global: !0,
        version: "0.8.1",
        init: function(a, b, c) {
            var d, f, h, i, j;
            return "function" != typeof a.setAttribute ? !1 : (d = a.nodeName.toUpperCase(), 
            j = "POLYLINE" === d || "POLYGON" === d, "PATH" === d || j ? (f = "PATH" === d ? "d" : "points", 
            ("string" == typeof b || b.getBBox || b[0]) && (b = {
                shape: b
            }), i = G(b.shape || b.d || b.points || "", "d" === f, a), j && e.test(i) ? (g("WARNING: a <" + d + "> cannot accept path data. " + H), 
            !1) : (i && (this._target = a, a.getAttributeNS(null, "data-original") || a.setAttributeNS(null, "data-original", a.getAttribute(f)), 
            h = this._addTween(a, "setAttribute", a.getAttribute(f) + "", i + "", "morphSVG", !1, f, "object" == typeof b.precompile ? function(a) {
                a[0] = b.precompile[0], a[1] = b.precompile[1];
            } : "d" === f ? z(b.shapeIndex, b.map || I.defaultMap, b.precompile) : D(b.shapeIndex)), 
            h && (this._overwriteProps.push("morphSVG"), h.end = i, h.endProp = f)), !0)) : (g("WARNING: cannot morph a <" + d + "> SVG element. " + H), 
            !1));
        },
        set: function(a) {
            var b;
            if (this._super.setRatio.call(this, a), 1 === a) for (b = this._firstPT; b; ) b.end && this._target.setAttribute(b.endProp, b.end), 
            b = b._next;
        }
    });
    I.pathFilter = y, I.pointsFilter = C, I.subdivideRawBezier = k, I.defaultMap = "size", 
    I.pathDataToRawBezier = function(a) {
        return j(G(a, !0));
    }, I.equalizeSegmentQuantity = x, I.convertToPath = function(a, b) {
        "string" == typeof a && (a = f.selector(a));
        for (var c = a && 0 !== a.length ? a.length && a[0] && a[0].nodeType ? Array.prototype.slice.call(a, 0) : [ a ] : [], d = c.length; --d > -1; ) c[d] = F(c[d], b !== !1);
        return c;
    }, I.pathDataToBezier = function(a, b) {
        var c, d, e, g, h, i, k, l, m = j(G(a, !0))[0] || [], n = 0;
        if (b = b || {}, l = b.align || b.relative, g = b.matrix || [ 1, 0, 0, 1, 0, 0 ], 
        h = b.offsetX || 0, i = b.offsetY || 0, "relative" === l || l === !0 ? (h -= m[0] * g[0] + m[1] * g[2], 
        i -= m[0] * g[1] + m[1] * g[3], n = "+=") : (h += g[4], i += g[5], l && (l = "string" == typeof l ? f.selector(l) : [ l ], 
        l && l[0] && (k = l[0].getBBox() || {
            x: 0,
            y: 0
        }, h -= k.x, i -= k.y))), c = [], e = m.length, g) for (d = 0; e > d; d += 2) c.push({
            x: n + (m[d] * g[0] + m[d + 1] * g[2] + h),
            y: n + (m[d] * g[1] + m[d + 1] * g[3] + i)
        }); else for (d = 0; e > d; d += 2) c.push({
            x: n + (m[d] + h),
            y: n + (m[d + 1] + i)
        });
        return c;
    };
}), _gsScope._gsDefine && _gsScope._gsQueue.pop()();

(function() {
    var COMPONENT_NAME = "netflix-brand-logo";
    var svg;
    function createGradient(svg, id, stops, p) {
        var svgNS = svg.namespaceURI;
        var grad = document.createElementNS(svgNS, "linearGradient");
        grad.setAttribute("id", id);
        grad.setAttribute("gradientUnits", "userSpaceOnUse");
        grad.setAttribute("spreadMethod", "pad");
        grad.setAttribute("x1", p.x1 || 0);
        grad.setAttribute("y1", p.y1 || 0);
        grad.setAttribute("x2", p.x2 || 0);
        grad.setAttribute("y2", p.y2 || 0);
        var s = [];
        for (var i = 0; i < stops.length; i++) {
            var attrs = stops[i];
            var stop = document.createElementNS(svgNS, "stop");
            for (var attr in attrs) {
                if (attrs.hasOwnProperty(attr)) stop.setAttribute(attr, attrs[attr]);
            }
            grad.appendChild(stop);
            s.push(stop);
        }
        var defs = svg.querySelector("defs") || svg.insertBefore(document.createElementNS(svgNS, "defs"), svg.firstChild);
        defs.appendChild(grad);
        return s;
    }
    function drawPath(path, fill, gradient) {
        var p = document.createElementNS("http://www.w3.org/2000/svg", "path");
        p.setAttributeNS(null, "d", path);
        p.setAttribute("fill", fill);
        if (gradient) {
            var stops = [];
            stops.push({
                offset: "0%",
                "stop-color": gradient.stop1 || "#B60009"
            });
            if (gradient.stop3) {
                stops.push({
                    offset: "50%",
                    "stop-color": gradient.stop2 || "#540001"
                });
                stops.push({
                    offset: "100%",
                    "stop-color": gradient.stop3 || "#B60009"
                });
            } else {
                stops.push({
                    offset: "100%",
                    "stop-color": gradient.stop2 || "#540001"
                });
            }
            p.gradient = createGradient(svg, fill.replace("url(#", "").replace(")", ""), stops, gradient);
        }
        return p;
    }
    var Utils = function() {
        function Utils() {}
        Utils.createStyle = function(n, r, o) {
            var stylesheet = "";
            this.stylesheet = document.getElementById(COMPONENT_NAME + "-component-stylesheet");
            if (!this.stylesheet) return;
            this.styles = this.styles || [];
            this.styles.push({
                e: n,
                s: r
            });
            this.styles.forEach(function(row) {
                stylesheet += COMPONENT_NAME + (o ? "" : " ") + row.e + "{" + row.s + "}\n";
            });
            this.stylesheet.innerHTML = stylesheet;
        };
        Utils.dispatch = function(target, event, d) {
            c = document.createEvent("CustomEvent");
            c.initCustomEvent(event, !0, !0, d);
            target.dispatchEvent(c);
        };
        Utils.isInception = function(target, event, d) {
            var htmlElem = document.getElementsByTagName("html")[0];
            var isInception = htmlElem.hasAttribute("monet-inception-pristine-element");
            return isInception;
        };
        Utils.isiOS = /iPad|iPhone|iPod/.test(navigator.userAgent);
        Utils.isSafari = /^((?!chrome|android).)*safari/i.test(navigator.userAgent);
        return Utils;
    }();
    (function() {
        var component = Object.create(HTMLElement.prototype, {
            createdCallback: {
                value: function() {},
                enumerable: true
            },
            attachedCallback: {
                value: function() {
                    var useGradient = !(Utils.isInception() && (Utils.isiOS || Utils.isSafari));
                    var comps = document.querySelectorAll(COMPONENT_NAME);
                    for (var i = 0; i < comps.length; i++) {
                        if (comps[i].uid == undefined) {
                            comps[i].uid = i;
                        } else {
                            continue;
                        }
                    }
                    this.stylesheet = document.createElement("style");
                    this.stylesheet.id = COMPONENT_NAME + "-component-stylesheet";
                    this.stylesheet.type = "text/css";
                    this.appendChild(this.stylesheet);
                    Utils.createStyle("", "position:absolute;");
                    Utils.createStyle("svg", "-webkit-backface-visibility:hidden;backface-visibility:hidden;-webkit-transform-origin:top left;transform-origin:top left;");
                    this.animDuration = this.getAttribute("duration") || 1.375;
                    svg = this.svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
                    this.svg.setAttribute("width", "936px");
                    this.svg.setAttribute("height", "254px");
                    this.svg.setAttribute("viewBox", "0 0 936 254");
                    this.resize();
                    this.n_leftShape = drawPath("M 45 2 L 0 2 0 235 Q 17 231 45 232 L 45 2 Z", useGradient ? "url(#n_leftGrad" + this.uid + ")" : "#9D030C", {
                        x1: "-48",
                        y1: "-141",
                        x2: "-38",
                        y2: "-144"
                    });
                    this.n_leftShape.to = "M 37 2 L 0 2 0 254 Q 19 251 40 249 L 37 2 Z";
                    this.n_rightShape = drawPath("M 127 2 L 83 2 83 219 127 235 127 2 Z", useGradient ? "url(#n_rightGrad" + this.uid + ")" : "#9D030C", {
                        x1: "104",
                        y1: "140",
                        x2: "84",
                        y2: "146"
                    });
                    this.n_rightShape.to = "M 128 2 L 90 2 89 242 128 238 129 2 Z";
                    this.n_midShape = drawPath("M 45 2 L 0 2 81 232 Q 110 231 127 236 L 45 2 Z", "#E50914");
                    this.n_midShape.to = "M 37 2 L 0 2 85 243 123 239 37 2 Z";
                    this.e_topShape = drawPath("M 274 41 L 274 1 167 1 167 41 274 41 Z", "#E50914");
                    this.e_topShape.to = "M 167 41 L 167 1 167 1 167 41 167 41 Z";
                    this.e_mainShape = drawPath("M 206 3 L 167 3 167 227 206 227 206 3 Z", useGradient ? "url(#e_mainGrad" + this.uid + ")" : "#9D030C", {
                        x1: "190",
                        y1: "65",
                        x2: "190",
                        y2: "24",
                        stop1: "#E50914"
                    });
                    this.e_mainShape.to = "M 206 3 L 206 3 167 3 167 3 206 3 Z";
                    this.e_bottomShape = drawPath("M 274 186 L 167 188 167 227 274 225 274 186 Z", useGradient ? "url(#e_bottomGrad" + this.uid + ")" : "#9D030C", {
                        x1: "232",
                        y1: "204",
                        x2: "197",
                        y2: "205",
                        stop1: "#E50914"
                    });
                    this.e_bottomShape.to = "M 167 188 L 167 188 167 227 167 227 167 188 Z";
                    this.e_midShape = drawPath("M 182 134 L 257 134 257 94 182 94 182 134 Z", "#E50914");
                    this.e_midShape.to = "M 182 94 L 182 94 182 134 182 134 182 94 Z";
                    this.t_midShape = drawPath("M 381 8 L 341 8 341 224 381 222 381 8 Z", useGradient ? "url(#t_midGrad" + this.uid + ")" : "#9D030C", {
                        x1: "366",
                        y1: "69",
                        x2: "366",
                        y2: "29",
                        stop1: "#E50914"
                    });
                    this.t_midShape.to = "M 381 8 L 381 8 341 8 341 8 381 8 Z";
                    this.t_topShape = drawPath("M 423 41 L 423 1 300 1 300 41 423 41 Z", "#E50914");
                    this.t_topShape.to = "M 300 41 L 300 1 300 1 300 41 300 41 ";
                    this.f_topShape = drawPath("M 558 41 L 558 1 448 1 448 41 558 41 Z", "#E50914");
                    this.f_topShape.to = "M 448 41 L 448 1 448 1 448 41 448 41 Z";
                    this.f_midShape = drawPath("M 541 132 L 541 92 466 92 466 132 541 132 Z", "#E50914");
                    this.f_midShape.to = "M 466 132 L 466 92 466 92 466 132 466 132 Z";
                    this.f_mainShape = drawPath("M 488 18 L 448 18 448 222 488 222 488 18 Z", useGradient ? "url(#f_mainGrad" + this.uid + ")" : "#9D030C", {
                        x1: "472",
                        y1: "69",
                        x2: "472",
                        y2: "28",
                        stop1: "#E50914"
                    });
                    this.f_mainShape.to = "M 488 18 L 448 18 448 18 488 18 488 18 Z";
                    this.l_bottomShape = drawPath("M 691 231 L 691 192 584 184 584 223 691 231 Z", "#E50914");
                    this.l_bottomShape.to = "M 584 231 L 584 192 584 184 584 223 584 231 Z";
                    this.l_mainShape = drawPath("M 624 0 L 584 0 584 223 624 223 624 0 Z", useGradient ? "url(#l_mainGrad" + this.uid + ")" : "#9D030C", {
                        x1: "599",
                        y1: "158",
                        x2: "599",
                        y2: "201",
                        stop1: "#E50914"
                    });
                    this.l_mainShape.to = "M 624 0 L 584 0 584 0 624 0 624 0 Z";
                    this.i_mainShape = drawPath("M 763 0 L 723 0 723 230 763 233 763 0 Z", "#E50914");
                    this.i_mainShape.to = "M 763 0 L 723 0 723 0 763 0 763 0 Z";
                    this.x_frontShape = drawPath("M 791 236 L 791 236 831 241 831 241 791 236 Z", "#E50914");
                    this.x_frontShape.to = "M 935 1 L 893 1 791 236 831 241 935 1 Z";
                    this.x_backShape = drawPath("M 891 248 L 934 254 837 0 794 0 891 248 Z", useGradient ? "url(#x_backGrad" + this.uid + ")" : "#9D030C", {
                        x1: "946",
                        y1: "-104",
                        x2: "1011",
                        y2: "-64",
                        stop1: "#E50914",
                        stop2: "#680001",
                        stop3: "#E50914"
                    });
                    this.x_backShape.to = "M 827 0 L 784 0 791 0 833 0 827 0 Z";
                    this.svg.appendChild(this.n_leftShape);
                    this.svg.appendChild(this.n_rightShape);
                    this.svg.appendChild(this.n_midShape);
                    this.svg.appendChild(this.e_bottomShape);
                    this.svg.appendChild(this.e_midShape);
                    this.svg.appendChild(this.e_mainShape);
                    this.svg.appendChild(this.e_topShape);
                    this.svg.appendChild(this.t_midShape);
                    this.svg.appendChild(this.t_topShape);
                    this.svg.appendChild(this.f_midShape);
                    this.svg.appendChild(this.f_mainShape);
                    this.svg.appendChild(this.f_topShape);
                    this.svg.appendChild(this.l_mainShape);
                    this.svg.appendChild(this.l_bottomShape);
                    this.svg.appendChild(this.i_mainShape);
                    this.svg.appendChild(this.x_backShape);
                    this.svg.appendChild(this.x_frontShape);
                    this.appendChild(this.svg);
                    this.timeline = new TimelineMax({
                        paused: true,
                        onComplete: this.onPlayComplete.bind(this),
                        onReverseComplete: this.onReverseComplete.bind(this)
                    });
                    this.timeline.add("start");
                    var left = Number(window.getComputedStyle(this, "left").left.replace("px", ""));
                    this.timeline.to(this.n_leftShape, 1.3, {
                        morphSVG: this.n_leftShape.to,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.2");
                    this.timeline.to(this.n_leftShape.gradient, 1.3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.2");
                    this.timeline.to(this.n_rightShape, 1.3, {
                        morphSVG: this.n_rightShape.to,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.2");
                    this.timeline.to(this.n_rightShape.gradient, 1.3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.2");
                    this.timeline.to(this.n_midShape, 1.3, {
                        morphSVG: this.n_midShape.to,
                        ease: Quad.easeOut
                    }, "start+=.2");
                    this.timeline.fromTo(this.e_topShape, .15, {
                        morphSVG: this.e_topShape.to
                    }, {
                        morphSVG: this.e_topShape,
                        ease: Quad.easeOut
                    }, "start+=.425");
                    this.timeline.fromTo(this.e_mainShape, .15, {
                        morphSVG: this.e_mainShape.to
                    }, {
                        morphSVG: this.e_mainShape,
                        ease: Quad.easeOut
                    }, "start+=.45");
                    this.timeline.to(this.e_mainShape, .9, {
                        morphSVG: "M 206 7 L 167 9 167 234 206 231 206 7 Z",
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.7");
                    this.timeline.to(this.e_mainShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.6");
                    this.timeline.fromTo(this.e_midShape, .15, {
                        morphSVG: this.e_midShape.to
                    }, {
                        morphSVG: this.e_midShape,
                        ease: Quad.easeOut
                    }, "start+=.55");
                    this.timeline.fromTo(this.e_bottomShape, .15, {
                        morphSVG: this.e_bottomShape.to
                    }, {
                        morphSVG: this.e_bottomShape.to,
                        ease: Quad.easeOut
                    }, "start+=.575");
                    this.timeline.to(this.e_bottomShape, .15, {
                        morphSVG: "M 274 187 L 167 194 167 233 274 226 274 187 Z",
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.585");
                    this.timeline.to(this.e_bottomShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.595");
                    this.timeline.fromTo(this.t_topShape, .15, {
                        morphSVG: this.t_topShape.to
                    }, {
                        morphSVG: this.t_topShape,
                        ease: Quad.easeOut
                    }, "start+=.575");
                    this.timeline.fromTo(this.t_midShape, .15, {
                        morphSVG: this.t_midShape.to
                    }, {
                        morphSVG: this.t_midShape,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.6");
                    this.timeline.to(this.t_midShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.75");
                    this.timeline.fromTo(this.f_topShape, .15, {
                        morphSVG: this.f_topShape.to
                    }, {
                        morphSVG: this.f_topShape,
                        ease: Quad.easeOut
                    }, "start+=.625");
                    this.timeline.fromTo(this.f_mainShape, .2, {
                        morphSVG: this.f_mainShape.to
                    }, {
                        morphSVG: this.f_mainShape,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.675");
                    this.timeline.fromTo(this.f_midShape, .15, {
                        morphSVG: this.f_midShape.to
                    }, {
                        morphSVG: this.f_midShape,
                        ease: Quad.easeOut
                    }, "start+=.775");
                    this.timeline.to(this.f_mainShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=.9");
                    this.timeline.fromTo(this.l_mainShape, .15, {
                        morphSVG: this.l_mainShape.to
                    }, {
                        morphSVG: this.l_mainShape,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.725");
                    this.timeline.fromTo(this.l_bottomShape, .15, {
                        morphSVG: this.l_bottomShape.to
                    }, {
                        morphSVG: this.l_bottomShape,
                        ease: Quad.easeOut
                    }, "start+=.85");
                    this.timeline.to(this.l_bottomShape, .3, {
                        morphSVG: "M 691 228 L 691 189 584 184 584 223 691 228 Z",
                        ease: Quad.easeOut
                    }, "start+=1");
                    this.timeline.to(this.l_mainShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=1.025");
                    this.timeline.fromTo(this.i_mainShape, .15, {
                        morphSVG: this.i_mainShape.to
                    }, {
                        morphSVG: this.i_mainShape,
                        ease: Quad.easeOut
                    }, "start+=.875");
                    this.timeline.fromTo(this.x_backShape, .3, {
                        morphSVG: this.x_backShape.to
                    }, {
                        morphSVG: this.x_backShape,
                        fill: useGradient ? "" : "#E50914",
                        ease: Quad.easeOut
                    }, "start+=.925");
                    this.timeline.to(this.x_frontShape, .3, {
                        morphSVG: {
                            shape: "M 935 1 L 893 1 790 237 831 241 935 1 Z",
                            shapeIndex: 3
                        },
                        ease: Quad.easeOut
                    }, "start+=1.025");
                    this.timeline.to(this.x_backShape.gradient, .3, {
                        stopColor: "#E50914",
                        ease: Linear.easeNone
                    }, "start+=1.025");
                },
                enumerable: true
            },
            attributeChangedCallback: {
                value: function() {
                    var width = this.getAttribute("width");
                    width = parseInt(width, 10);
                    if (this.size.w != width) {
                        this.resize();
                    }
                },
                enumerable: true
            },
            resize: {
                value: function(s) {
                    if (s) {
                        var width = s.w;
                        var height = s.h;
                    } else {
                        var width = Number(this.getAttribute("width") || this.offsetWidth || 100);
                        var height = Number(254 / 936 * width);
                    }
                    scale = width / 936;
                    this.size = {
                        w: width,
                        h: height
                    };
                    TweenLite.set(this, {
                        width: width,
                        height: height
                    });
                    this.svg.setAttribute("style", "transform: scale(" + scale + ");" + "-webkit-transform: scale(" + scale + ");");
                }
            },
            play: {
                value: function() {
                    this.timeline.duration(this.animDuration).play();
                }
            },
            reset: {
                value: function() {
                    this.timeline.seek(0);
                }
            },
            reverse: {
                value: function() {
                    this.timeline.reverse();
                }
            },
            progress: {
                value: function(t) {
                    this.timeline.progress(t);
                }
            },
            onPlayComplete: {
                value: function() {
                    Utils.dispatch(this, "playComplete");
                }
            },
            onReverseComplete: {
                value: function() {
                    Utils.dispatch(this, "reverseComplete");
                }
            },
            preview: {
                value: function() {
                    this.play();
                    setTimeout(this.reverse.bind(this), 3e3);
                }
            }
        });
        document.registerElement(COMPONENT_NAME, {
            prototype: component
        });
    })();
})();

(function() {
    var COMPONENT_NAME = "netflix-ratings-bug";
    function getIconDimensions(iconPath) {
        if (iconPath && iconPath.indexOf("_") > 0) {
            var startingPoint = iconPath.lastIndexOf("_");
            var dimensions = iconPath.substr(Number(startingPoint) + 1).split("x");
            if (dimensions && dimensions.length > 1) {
                return {
                    width: dimensions[0],
                    height: dimensions[1]
                };
            }
            return null;
        }
    }
    if (document.registerElement) {
        var ratingIconSrc = "";
        var iconWidth = 20;
        var iconHeight = 20;
        var component = Object.create(HTMLElement.prototype, {
            attachedCallback: {
                value: function() {
                    var dom = this;
                    var MonetComponent = document.querySelector("monet-integrator");
                    if (MonetComponent) {
                        MonetComponent.register(this);
                        MonetComponent.getMonetData().then(function(data) {
                            var ratingIcon = dom.getAttribute("rating-icon");
                            try {
                                var imgSrc = data.rootAssets["image." + ratingIcon];
                                var dimensions = getIconDimensions(ratingIcon);
                                if (dimensions) {
                                    iconWidth = dimensions.width;
                                    iconHeight = dimensions.height;
                                }
                                if (imgSrc) {
                                    ratingIconSrc = data.rootAssets["image." + ratingIcon].url;
                                }
                            } catch (e) {
                                MonetComponent.getBackupMonetData().then(function(backupData) {
                                    ratingIconSrc = backupData.rootAssets["image.Ratings_Bug_20x20"].url;
                                }, function(error) {
                                    console.error("Failed to load backup Monet data", error);
                                });
                            }
                            var ratingsIcon = document.createElement("img");
                            ratingsIcon.id = "RatingsIcon";
                            ratingsIcon.className = "ratings-icon";
                            ratingsIcon.onload = function(event) {
                                dom.dispatchEvent(new CustomEvent("ready"));
                            };
                            ratingsIcon.onerror = function(event) {
                                dom.dispatchEvent(new CustomEvent("ready"));
                            };
                            ratingsIcon.setAttribute("src", ratingIconSrc);
                            ratingsIcon.setAttribute("width", iconWidth);
                            ratingsIcon.setAttribute("height", iconHeight);
                            dom.appendChild(ratingsIcon);
                        });
                    }
                }
            },
            preview: {
                value: function() {}
            }
        });
        document.registerElement(COMPONENT_NAME, {
            prototype: component
        });
    }
})();

(function() {
    var COMPONENT_NAME = "netflix-flushed-ribbon";
    window.Utils = function(Utils) {
        Utils.SvgContainer = function(width, height, coordinates, stroke) {
            return '<svg xmlns="http://www.w3.org/2000/svg" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" preserveAspectRatio="none" x="0px" y="0px" ' + 'width="' + width + 'px" ' + 'height="' + height + 'px" ' + 'viewBox="0 0 ' + width + " " + height + '"><defs><linearGradient id="Gradient_1" gradientUnits="userSpaceOnUse" ' + coordinates + ' spreadMethod="pad"><stop  offset="0%" stop-color="#AD050F"/><stop offset="100%" stop-color="#9D030C"/></linearGradient>' + "<g " + 'transform="scale(' + width / 100 + "," + height / 100 + ')" >' + '<path fill="#9D030C" stroke="none" d="' + stroke + '"/></g></defs><g transform="matrix( 1, 0, 0, 1, 0,0) "></svg>';
        };
        return Utils;
    }(window.Utils || {});
    var component = Object.create(HTMLElement.prototype, {
        createdCallback: {
            value: function() {
                this.leftContainer = create("leftContainer", this);
                this.rightContainer = create("rightContainer", this);
                this.midContainer = create("midContainer", this);
                this.mid = create("mid", this.midContainer);
                function create(name, target) {
                    var elem = document.createElement("div");
                    elem.classList.add(name);
                    if (target) {
                        target.appendChild(elem);
                    }
                    return elem;
                }
            },
            enumerable: true
        },
        attachedCallback: {
            value: function() {
                this.width = this.getAttribute("width") || this.offsetWidth || 300;
                this.height = this.getAttribute("height") || this.offsetHeight || 250;
                this.scale = 1;
                var defaultScale = {
                    "970x250": 2.5,
                    "300x600": 1.5,
                    "728x90": 2,
                    "320x480": 1.3,
                    "980x250": 2.5
                };
                var offset = this.width > this.height ? -6 : 7;
                if (defaultScale[this.width + "x" + this.height]) {
                    this.scale = defaultScale[this.width + "x" + this.height];
                }
                if (Number(this.getAttribute("scale"))) {
                    this.scale = Number(this.getAttribute("scale"));
                }
                var scaleWidth = this.width * .5;
                var scaleHeight = 600;
                this.leftContainer.innerHTML = Utils.SvgContainer(scaleWidth, scaleHeight, 'x1="-11.475" y1="55.6375" x2="62.875" y2="50.4625"', "M 0 0 L 0 100 100 100 100 0 0 0 Z");
                this.rightContainer.innerHTML = Utils.SvgContainer(scaleWidth, scaleHeight, 'x1="111.475" y1="44.3125" x2="37.125" y2="49.4875"', "M 100 100 L 100 0 0 0 0 100 100 100 Z");
                Utils.createStyle.call(this, COMPONENT_NAME, "", "overflow: hidden; width:" + this.width + "px; height:" + this.height + "px; display:block; position:relative; pointer-events:none; z-index:100;", ".leftContainer", "background-color: #9d030c;position: absolute; top: 0; left: 0; width: 50%; height: " + this.height + "px; overflow: hidden;", ".rightContainer", "background-color: #9d030c;position: absolute; top: 0; right: 0; width: 50%; height: " + this.height + "px;overflow: hidden;", ".midContainer", "position: absolute; width: " + this.width + "px; height: " + this.height + "px; transform-origin: 50% 50%; -webkit-transform: rotate(-19deg); transform:rotate(-19deg);", ".mid", "position:absolute; top:50%; left:50%; width: " + 160 * this.scale + "px; height: " + this.height * 2.5 + "px; overflow: hidden; transform: translate(-50%,-150%); background-color: #e50914;");
                TweenMax.set([ this.leftContainer, this.rightContainer ], {
                    y: this.height
                });
                this.timeline = new TimelineMax({
                    paused: true
                });
                this.timeline.fromTo(this.leftContainer, .2, {
                    y: this.height
                }, {
                    y: 0,
                    ease: Power2.easeIn
                }, "start").fromTo(this.mid, .2, {
                    x: "-50%",
                    y: "-150%"
                }, {
                    x: "-50%",
                    y: "-50%",
                    ease: Power2.easeIn
                }, "start+=.2").fromTo(this.rightContainer, .2, {
                    y: this.height
                }, {
                    y: 0,
                    ease: Power2.easeIn
                }, "start+=.4").to(this.leftContainer, .2, {
                    y: -this.height,
                    ease: Power2.easeIn,
                    onComplete: this.onLeftPillarComplete.bind(this)
                }, "start+=.85").to(this.mid, .3, {
                    x: "-50%",
                    y: "200%",
                    ease: Power2.easeIn
                }, "start+=1.15").to(this.rightContainer, .3, {
                    y: -this.height,
                    ease: Power2.easeIn,
                    onComplete: this.onComplete.bind(this)
                }, "start+=1.35");
                this.dispatchEvent(new CustomEvent("ready"));
            },
            enumerable: true
        },
        play: {
            value: function() {
                this.timeline.play();
            }
        },
        onComplete: {
            value: function() {
                this.dispatchEvent(new CustomEvent("complete"));
            }
        },
        onLeftPillarComplete: {
            value: function() {
                this.dispatchEvent(new CustomEvent("leftPillarComplete"));
            }
        },
        progress: {
            value: function(value, suppressEvents) {
                this.timeline.progress(value, suppressEvents);
            }
        },
        preview: {
            value: function() {
                this.play();
            }
        }
    });
    document.registerElement(COMPONENT_NAME, {
        prototype: component
    });
})();

(function() {
    var COMPONENT_NAME = "netflix-cta";
    var PREFIX = "mm-component";
    function style() {
        Utils.createStyle.call(this, COMPONENT_NAME, ".button", "cursor: pointer;overflow: hidden;text-align: center;font-size:" + this.data.size + "px; font-family: " + this.data.font, ".button .fill", "width:100%;height:100%;transform-origin:top left;-webkit-transform-origin:top left;transform: scale(0, 1);-webkit-transform: scale(0, 1); transition: transform .4s cubic-bezier(0.19, 1, 0.22, 1);", ".button .arrow", "position:absolute;text-align: right;top:50%;left:auto;right:auto;width:100%;font-size:160% !important;-webkit-transform: translate(0%, -50%);transform: translate(0%, -50%);", ".button .arrow svg", "position:absolute;right:4%;left:auto;top:0;", ".button .copy", "transform-origin: 0 0;white-space:nowrap;letter-spacing:1.5px; padding:4px 8%;transition: color .4s cubic-bezier(0.19, 1, 0.22, 1);color:" + this.data.color[1], ".button .border", "-webkit-box-sizing: border-box;box-sizing: border-box;position: absolute;top: 0;left: 0;width:100%;height:100%;border:solid " + this.borderSize + "px " + this.data.color[0], "*", "position: absolute;top: 0;left: 0;");
        if (!Utils.isMobile) {
            Utils.createStyle.call(this, COMPONENT_NAME, ".button:hover .bgImageHover", "width:100% !important;", ".button.hover .bgImageHover", "width:100% !important;", ".button:hover .fill", "transform: scale(1, 1); -webkit-transform: scale(1, 1);", ".button.hover .fill", "transform: scale(1, 1); -webkit-transform: scale(1, 1);", ".button:hover .arrow", "color:" + this.data.color[0], ".button.hover .arrow", "color:" + this.data.color[0], ".button:hover .copy", "color:" + this.data.color[0], ".button.hover .copy", "color:" + this.data.color[0], ".button.isArrow:hover .copy", "color:" + this.data.color[0]);
        }
        this.className += " " + PREFIX;
        this.style.position = "absolute";
        this.button.style.backgroundColor = this.data.color[0];
        this.fill.style.backgroundColor = this.data.color[1];
    }
    var component = Object.create(HTMLElement.prototype, {
        createdCallback: {
            value: function() {
                this._attached = false;
            },
            enumerable: true
        },
        attachedCallback: {
            value: function() {
                this._attached = true;
                this.data = {};
                this.data.color = [ this.getAttribute("color-1") || "#e50914", this.getAttribute("color-2") || "#ffffff" ];
                this.data.size = 20;
                this.data.font = (this.getAttribute("font") || "Netflix Sans") + ", Arial, sans-serif";
                this.data.text = this.getAttribute("text");
                this.button = document.createElement("div");
                this.button.className = "button";
                this.fill = document.createElement("div");
                this.fill.className = "fill";
                this.copy = document.createElement("div");
                this.copy.className = "copy";
                this.arrow = document.createElement("div");
                this.arrow.className = "arrow";
                this.border = document.createElement("div");
                this.border.className = "border";
                var bgImg = this.getAttribute("background-image");
                if (bgImg) {
                    this.bgImgContainer = document.createElement("div");
                    this.bgImgContainer.className = "bgImage";
                    var img = new Image();
                    img.src = bgImg;
                    this.bgImgContainer.appendChild(img);
                    this.button.appendChild(this.bgImgContainer);
                    this.bgImgContainer.setAttribute("style", "position: absolute; top:0;left:0;");
                    img.setAttribute("style", "min-width:" + this.width + "px;");
                }
                this.appendChild(this.button);
                this.button.appendChild(this.fill);
                var bgImgHover = this.getAttribute("background-image-hover");
                if (bgImgHover) {
                    this.bgImgContainerHover = document.createElement("div");
                    this.bgImgContainerHover.className = "bgImageHover";
                    var imgHover = new Image();
                    imgHover.src = bgImgHover;
                    this.bgImgContainerHover.appendChild(imgHover);
                    this.button.appendChild(this.bgImgContainerHover);
                    this.bgImgContainerHover.setAttribute("style", "position: absolute; top:0;left:0;width:0%;overflow:hidden;height:" + this.height + "px; transition: width .4s cubic-bezier(0.19, 1, 0.22, 1);");
                    imgHover.setAttribute("style", "min-width:" + this.width + "px;");
                    this.fill.setAttribute("style", "display:none;");
                }
                this.button.appendChild(this.copy);
                this.hasArrow = this.hasAttribute("arrow");
                this.hasBorder = this.hasAttribute("border");
                this.borderSize = this.getAttribute("border") || 1;
                if (this.hasArrow) {
                    this.button.appendChild(this.arrow);
                    this.button.className += " isArrow";
                }
                if (this.hasBorder) {
                    this.button.appendChild(this.border);
                }
                style.call(this);
                this.button.addEventListener("click", function() {
                    if (this.click) this.click();
                    c = document.createEvent("CustomEvent");
                    c.initCustomEvent("cta-click", !0, !0, "Netflix CTA Click");
                    this.dispatchEvent(c);
                }.bind(this));
                this.button.addEventListener("mouseover", function(event) {
                    this.mouseover.call(this);
                }.bind(this));
                this.button.addEventListener("mouseout", function(event) {
                    this.mouseout.call(this);
                }.bind(this));
                var cta = "WATCH NOW";
                var MonetComponent = document.querySelector("monet-integrator");
                if (MonetComponent) {
                    MonetComponent.register(this);
                    MonetComponent.getMonetData().then(function(data) {
                        var key = this.getAttribute("data-dynamic-key") || "CTA";
                        var d = key;
                        if (d.split(".").length == 1) {
                            d = 'rootAssets["text.' + d + '"].text';
                        }
                        try {
                            cta = eval("data." + d);
                            this.copy.classList.add(Monet.getComponentLocale("text." + key).substr(0, 2));
                            this.text(cta);
                            this.dispatchEvent(new CustomEvent("ready"));
                        } catch (e) {
                            Monet.logEvent("MONET_DATA_ERROR", {
                                details: "Netflix CTA Component error; Could not find data in rootAssets: " + "text." + d,
                                stack: e
                            });
                            MonetComponent.getBackupMonetData().then(function(backupData) {
                                var ld = d;
                                if (d.split(".").length == 1) {
                                    d = 'rootAssets["text.' + d + '"].text';
                                }
                                cta = eval("backupData." + d);
                                this.copy.classList.add(Monet.getComponentLocale("text." + key).substr(0, 2));
                                this.text(cta);
                                this.dispatchEvent(new CustomEvent("ready"));
                            }.bind(this), function(error) {
                                Monet.logEvent("MONET_DATA_ERROR", {
                                    details: "Failed to load backup Monet data",
                                    stack: error
                                });
                            });
                        }
                    }.bind(this), function(error) {
                        Monet.logEvent("MONET_DATA_ERROR", {
                            details: "Failed to load backup Monet data",
                            stack: error
                        });
                    });
                }
            },
            enumerable: true
        },
        attributeChangedCallback: {
            value: function() {
                if (this._attached) this.resize();
            },
            enumerable: true
        },
        text: {
            value: function(text, size) {
                this.copy.innerHTML = text || this.copy.innerHTML;
                this.resize();
            }
        },
        resize: {
            value: function(w, h) {
                this.rtl = this.getAttribute("rtl");
                if (this.rtl) {
                    this.arrow.setAttribute("style", "position:absolute;text-align: left;top:50%;left:auto;right:auto;width:100%;font-size:160% !important;-webkit-transform: scale(-1,1) translate(0%, -50%);transform: scale(-1,1) translate(0%, -50%);");
                } else {
                    this.arrow.setAttribute("style", "position:absolute;text-align: right;top:50%;left:auto;right:auto;width:100%;font-size:160% !important;-webkit-transform: translate(0%, -50%);transform: translate(0%, -50%);");
                }
                var width = w || (this.getAttribute("width") || (this.offsetWidth || 109));
                var height = h || (this.getAttribute("height") || (this.offsetHeight || 28));
                this.button.style.width = this.style.width = width + "px";
                this.button.style.height = this.style.height = height + "px";
                this.copy.setAttribute("style", "transform: scale(1);");
                var bb = this.copy.getBoundingClientRect();
                var bbb = this.button.getBoundingClientRect();
                var pr = "8%";
                if (this.hasArrow) {
                    var s = bb.width / bbb.width;
                    pr = s * 16 + "%";
                    if (this.rtl) {
                        this.copy.setAttribute("style", "padding-left: " + pr + ";padding-right: " + s * 16 + "%");
                    } else {
                        this.copy.setAttribute("style", "padding-right: " + pr + ";padding-left: " + s * 16 + "%");
                    }
                    bb = this.copy.getBoundingClientRect();
                    bbb = this.button.getBoundingClientRect();
                }
                var widthTransform = bbb.width / bb.width;
                var heightTransform = bbb.height / bb.height;
                var value = widthTransform < heightTransform ? widthTransform : heightTransform;
                var matrix = window.getComputedStyle(this.copy, null).getPropertyValue("transform");
                if (this.rtl) {
                    this.copy.setAttribute("style", "transform: scale(" + value.toFixed(3) + ");padding-left: " + pr);
                } else {
                    this.copy.setAttribute("style", "transform: scale(" + value.toFixed(3) + ");padding-right: " + pr);
                }
                var copyBounds = this.copy.getBoundingClientRect();
                var xp = Math.ceil(copyBounds.width * .96 / 2);
                var yp = Math.ceil(copyBounds.height / 2);
                var p = bbb.width - copyBounds.width;
                this.height = height;
                if (this._attached) {
                    this.arrow.innerHTML = "";
                    var s = Math.floor(this.height / 3.3);
                    TweenMax.set(this.arrow, {
                        height: s
                    });
                    var elem = document.createElementNS("http://www.w3.org/2000/svg", "svg");
                    elem.setAttribute("width", s + "px");
                    elem.setAttribute("height", s + "px");
                    elem.line = new Utils.SvgIcon("line1", "M0,0 l" + s / 2 + "," + s / 2 + "l-" + s / 2 + "," + s / 2);
                    elem.line.setAttribute("fill", "none");
                    elem.line.setAttribute("stroke", this.data.color[1] || 0);
                    elem.line.setAttribute("stroke-width", 2);
                    elem.appendChild(elem.line);
                    this.arrow.appendChild(elem);
                }
                if (this.rtl) {
                    this.copy.setAttribute("style", "backface-visibility: hidden; transform: translateZ(0) scale(" + value.toFixed(3) + ") translate(-50%,0); left: 50%;top:50%;margin-top:-" + yp + "px;padding-left: " + pr);
                } else {
                    this.copy.setAttribute("style", "backface-visibility: hidden; transform: translateZ(0) scale(" + value.toFixed(3) + ") translate(-50%,0); left: 50%;top:50%;margin-top:-" + yp + "px;padding-right: " + pr);
                }
            }
        },
        mouseover: {
            value: function() {
                if (!Utils.isMobile) {
                    this.button.classList.add("hover");
                }
                this.arrow.querySelector("svg").line.setAttribute("stroke", this.data.color[0]);
            }
        },
        mouseout: {
            value: function() {
                if (!Utils.isMobile) {
                    this.button.classList.remove("hover");
                }
                this.arrow.querySelector("svg").line.setAttribute("stroke", this.data.color[1]);
            }
        },
        preview: {
            value: function() {}
        }
    });
    document.registerElement(COMPONENT_NAME, {
        prototype: component
    });
})();

(function() {
    var COMPONENT_NAME = "netflix-img";
    if (document.registerElement) {
        var component = Object.create(HTMLElement.prototype, {
            createdCallback: {
                value: function() {
                    var img = document.createElement("img");
                    this.appendChild(img);
                }
            },
            attachedCallback: {
                value: function() {
                    var dom = this;
                    var img = this.children[0];
                    var MonetComponent = document.querySelector("monet-integrator");
                    var imgPath = "";
                    if (MonetComponent) {
                        MonetComponent.register(this);
                        MonetComponent.getMonetData().then(function(data) {
                            var bindSrc = dom.getAttribute("data-dynamic-key");
                            var height = dom.getAttribute("height");
                            var width = dom.getAttribute("width");
                            var imgId = dom.getAttribute("id");
                            try {
                                var imgSrc = data.rootAssets["image." + bindSrc];
                                if (imgSrc) {
                                    imgPath = imgSrc.url;
                                } else {
                                    imgPath = bindSrc;
                                }
                                if (bindSrc.indexOf("assetGroups") > -1) {
                                    imgPath = eval("data." + bindSrc);
                                }
                            } catch (e) {
                                console.error("Monet dynamic ID not found in JSON: ", bindSrc, "trying backup");
                                MonetComponent.getBackupMonetData().then(function(backupData) {
                                    imgPath = backupData.rootAssets["text." + bindSrc].text;
                                    if (bindSrc.indexOf("assetGroups") > -1) {
                                        imgPath = eval("data." + bindSrc);
                                    }
                                }, function(error) {
                                    console.error("Failed to load backup Monet data", error);
                                });
                            }
                            img.setAttribute("src", imgPath);
                            if (width) {
                                img.setAttribute("width", width);
                            }
                            if (height) {
                                img.setAttribute("height", height);
                            }
                            if (imgId) {
                                img.setAttribute("id", imgId + "-img");
                            }
                        });
                    }
                    img.onload = function(event) {
                        dom.dispatchEvent(new CustomEvent("ready"));
                    };
                }
            },
            preview: {
                value: function() {}
            }
        });
        document.registerElement(COMPONENT_NAME, {
            prototype: component
        });
    }
})();

(function() {
    function safeBRReplace(str) {
        var frag = document.createDocumentFragment();
        frag.textContent = str.replace(/<br\s*\/?>/gm, "\n");
        return frag.textContent.replace(/\n/gm, "<br>");
    }
    if (document.registerElement) {
        var elType = "netflix-text";
        var component = Object.create(HTMLElement.prototype, {
            createdCallback: {
                value: function() {
                    var textSpan = document.createElement("span");
                    this.appendChild(textSpan);
                }
            },
            attachedCallback: {
                value: function() {
                    var dom = this;
                    var textSpan = this.children[0];
                    var MonetComponent = document.querySelector("monet-integrator");
                    if (MonetComponent) {
                        MonetComponent.register(this);
                        MonetComponent.getMonetData().then(function(data) {
                            var bindSrc = dom.getAttribute("data-dynamic-key");
                            if (bindSrc.split(".").length == 1) {
                                bindSrc = 'rootAssets["text.' + bindSrc + '"].text';
                            }
                            try {
                                var dynamicText = eval("data." + bindSrc);
                                if (dynamicText) {
                                    textSpan.innerHTML = safeBRReplace(dynamicText);
                                    textSpan.classList.add(Monet.getComponentLocale("text." + dom.getAttribute("data-dynamic-key")).substr(0, 2));
                                }
                                dom.dispatchEvent(new CustomEvent("ready"));
                            } catch (e) {
                                console.error("Monet dynamic ID not found in JSON: ", bindSrc, "trying backup");
                                MonetComponent.getBackupMonetData().then(function(backupData) {
                                    if (backupData) {
                                        var dynamicText = eval("backupData." + bindSrc);
                                        textSpan.innerHTML = safeBRReplace(dynamicText);
                                        textSpan.classList.add(Monet.getComponentLocale("text." + dom.getAttribute("data-dynamic-key")).substr(0, 2));
                                    }
                                    dom.dispatchEvent(new CustomEvent("ready"));
                                }, function(error) {
                                    console.error("Failed to load backup Monet data", error);
                                });
                            }
                        });
                    } else {
                        console.warn('No "monet-integrator" component found. Dynamic binding is disabled');
                    }
                }
            },
            preview: {
                value: function() {}
            }
        });
        document.registerElement(elType, {
            prototype: component
        });
    }
})();