const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="uk">
<style>
/*-------------------------------------------------------------- # General --------------------------------------------------------------*/

@font-face {
    font-family: "icons";
    src: url(../fonts/icons.woff) format("woff");
    src: url(../fonts/icons.svg) format("svg");
    src: url(../fonts/icons.eot) format("eot");
    src: url(../fonts/icons.eot) format("embedded-opentype");
    src: url(../fonts/icons.ttf) format("truetype")
}

:root {
    --primary-color: #302AE6;
    --secondary-color: #536390;
    --font-color: #000;
    --font-color-primary: #617082;
    --font-color-title: #333;
    --bg-color: #fbfbfb;
    --bg-color-box: #f1f1f1;
    --heading-color: #292922;
}

[data-theme="dark"] {
    --primary-color: #9A97F3;
    --secondary-color: #818cab;
    --font-color: #cccccc;
    --font-color-primary: #3d82ea;
    --font-color-title: white;
    --bg-color: #101013;
    --bg-color-box: #161b1f;
    --heading-color: #818cab;
}

.device-1 .fa-dot-circle {
    width: 100%;
    height: 100%;
    margin: 0 auto;
    display: block;
    padding: 23px;
    font-size: 15px;
}
.device-1 hr {
    position: relative;
    top: -35px;
    right: 80px;
    width: 105px;
    border-top: 2px solid #222222;
}

body {
    background: var(--bg-color-box);
    color: var(--font-color);
    font-family: Roboto;
    font-size: 0.8rem;
    font-weight: 200;
    overflow-x: hidden;
}
body[data-theme='dark'] {
    background: #333;
}
.scrollable-element {
    scrollbar-color: red yellow;
}
a {
    color: #007bff;
}

a,
b {
    font-family: Roboto;
}

a:hover,
a:active,
a:focus {
    color: #007bff!important;
    outline: none;
    text-decoration: none;
}

.lang-active {
    color: #007bff!important;
}

img {
    border-style: none;
    width: 100%;
    height: auto;
    /*margin: 70px 0 30px 0;*/
}

#shema img {
    width: 80px;
}

.logo-top {
    width: 50px;
    margin-top: -0px!important;
    padding-right: 10px!important;
}

p {
    padding: 0;
    font-family: Roboto;
    font-size: 0.8rem;
}

h1,
h2,
h3,
h4,
h5,
h6 {
    font-family: 'Roboto', sans-serif!important;
    font-weight: 400;
    margin: 0 0 25px 0;
    padding: 0;
}

h1,
h2 {
    font-family: Roboto!important;
    color: #393a41;
}

/* Prelaoder */

#preloader {
    position: fixed;
    left: 0;
    top: 0;
    z-index: 999;
    width: 100%;
    height: 100%;
    overflow: visible;
    background: white;
url("../img/preloader.svg") no-repeat center center;
}

/* Back to top button */

.back-to-top {
    display: inline;
    box-shadow: 0 3px 20px #0400ff85;
    background: linear-gradient(-60deg, rgba(65, 113, 255, 1) 0%, rgb(3, 66, 255) 100%);
    cursor: pointer;
    position: fixed;
    display: none;
    color: white;
    padding: 6px 12px 9px 12px;
    font-size: 16px;
    border-radius: 50%;
    right: 20px;
    bottom: 20px;
    transition: background 0.5s;
    outline: none;
}

.back-to-top:focus {
    background: linear-gradient(60deg, rgba(65, 113, 255, 1) 0%, rgb(3, 66, 255) 100%);
    color: white;
    outline: none;
}

.back-to-top:hover {
    background: linear-gradient(60deg, rgba(65, 113, 255, 1) 0%, rgb(3, 66, 255) 100%);
    color: white;
    outline: none;
}

@media (max-width: 768px) {
    .back-to-top {
        bottom: 15px;
    }
}

.back-to-top:focus {
    background: linear-gradient(60deg, rgba(65, 113, 255, 1) 0%, rgb(3, 66, 255) 100%);
    color: white;
    outline: none;
}

.back-to-top:hover {
    background: linear-gradient(60deg, rgba(65, 113, 255, 1) 0%, rgb(3, 66, 255) 100%);
    color: white;
    outline: none;
}

/*-------------------------------------------------------------- # Header --------------------------------------------------------------*/

#header {
    padding: 30px 0;
    height: 92px;
    position: fixed;
    left: 0;
    top: 0;
    right: 0;
    transition: all 0.5s;
    z-index: 997;
}

#header #logo {
    float: left;
    margin-top: -5px;
}

#header #logo h1 {
    font-size: 36px;
    margin: 0;
    margin-top: -10px;
    padding: 14px 0;
    line-height: 1;
    font-family: Roboto;
    font-weight: 500;
    letter-spacing: 3px;
    text-transform: uppercase;
}

#header #logo h2 {
    color: #fff;
    font-size: 18px;
}

#header #logo h2 a{
    color: #fff;
    font-size: 15px;
    font-weight: 500;
}

#header #logo h1 a,
#header #logo h1 a:hover {
    color: #fff;
    font-size: 18px;
}

#header #logo img {
    padding: 0;
    margin: 0;
    margin-top: -2px!important;
}

@media (max-width : 768px) {
    #header #logo h1 {
        font-size: 26px;
    }
    #header #logo img {
        max-height: 40px;
    }
}

#header.header-fixed {
    background: #000;
    padding: 15px 0;
    height: 60px;
    transition: all 0.5s;
    z-index: 2002;
}
#header.header-fixed-page {
    background: #000;
    padding: 15px 0;
    height: 60px;
    transition: all 0.5s;
    z-index: 2002;
}

#thread {
    padding: 30px 0 0;
}

#thread h6 {
    letter-spacing: 2px;
    margin: 0!important;
    text-transform: uppercase;
    font-weight: 400!important;
    font-size: 0.7rem!important;
}

#empty {
    padding: 30px
}

.navbar-dark .navbar-brand {
    color: #313942;
}

#shema .shema-container .arrow img {
    width: 30px;
    margin: 5px 15px;
    opacity: 0.6;
}

#shema .shema-container .description {
    text-align: center;
    padding-top: 10px;
    font-size: 13px;
}
#part i {
    font-size: 50px;
    color: #343b40;

}
#about2 td:first-child,
#about2 th:first-child {
    width: 50%;
}
#footer i{
    font-size: 35px;
    padding-right: 10px;
}
#shema .shema-container .fadeInUp img {
    display: block;
    margin: auto;
}

#shema .shema-container img {
    display: block;
    padding: 0;
    margin: 0;
}

#shema .shema-container .arrow {
    display: block;
    margin: 10px auto;
}

#interfaces {
      width: 100%;
  height: 500px;
}
.about-container img {
    border-style: none;
    width: 80px;
    padding-bottom: 20px;
    height: auto;
    display: block;
    margin: auto;
}

.about-container .shema-container img:hover {
    opacity: 1;
    transition: 0.5s;
    transform: scale(1.1, 1.1);
}

#iot .about-container img,
#esp .about-container img {
    border-style: none;
    width: 400px;
    padding-bottom: 0;
    height: auto;
    display: block;
    margin: auto;
    /* //box-shadow: 2px
1px 15px #222; */
}

.part {
    filter: grayscale(100%);
}

.part:hover {
    transition: 0.5s;
    filter: grayscale(0%);
}

.about-container p {
    text-align: center;
}

#chartdiv-curtain {
    width: 100%!important;
}

.white {
    color: white!important;
}

/*--------------------------------------------------------------
# Hero Section --------------------------------------------------------------*/

#hero {
    display: table;
    width: 100%;
    height: 100vh;
    background: linear-gradient(rgba(0, 0, 0, 0.5), rgba(29, 28, 44, 0.5)), url(../img/hero-bg2.webp) top center fixed;
    background-attachment: fixed !important;
    background-size: cover;
}

#about .about-container .content {}

#hero .hero-container {
    display: table-cell;
    margin: 0;
    text-align: center;
    vertical-align: middle;
}

#hero h1 {
    margin: 30px 0 10px 0;
    font-size: 25px;
    font-weight: 500;
    line-height: 56px;
    text-transform: uppercase;
    color: white;
    /* letter-spacing: 3px; */
}

@media (max-width: 768px) {
    #hero h1 {
        font-size: 28px;
        line-height: 36px;
    }
}

#hero h2 {
    color: #eee;
    font-size: 20px;
    letter-spacing: 1px;
    line-height: 30px;
}

@media (max-width: 768px) {
    #hero h2 {
        font-size: 18px;
        line-height: 24px;
        margin-bottom: 30px;
    }
}

#hero .btn-get-started {
    font-family: Roboto;
    text-transform: uppercase;
    font-weight: 500;
    font-size: 16px;
    letter-spacing: 1px;
    display: inline-block;
    padding: 8px 28px;
    border-radius: 50px;
    transition: 0.5s;
    margin: 10px;
    border: 2px solid white;
;
    color: white;
;
}

#hero .btn-get-started:hover {
    background: #007bff;
    border: 2px solid #007bff;
}


/*--------------------------------------------------------------
# Navigation Menu --------------------------------------------------------------*/


/* Nav Menu Essentials */
.padding-20{
    padding-left: 20px;
}
#logo h1 a {
    display: block;
}
.nav-menu,
.nav-menu * {
    margin: 0;
    padding: 0;
    list-style: none;
}

.nav-menu ul {
    position: absolute;
    display: none;
    top: 100%;
    left: 0;
    z-index: 99;
}

.nav-menu li {
    position: relative;
    cursor: pointer;
    /* white; */
    /* -space: nowrap; */
}

.nav-menu>li {
    float: left;
}

.nav-menu li:hover>ul,
.nav-menu li.sfHover>ul {
    display: block;
}

.nav-menu ul ul {
    top: 0;
    left: 100%;
}

.nav-menu ul li {
    min-width: 180px;
}


/* Nav Menu Arrows */

.sf-arrows .sf-with-ul {
    padding-right: 30px;
}

.sf-arrows .sf-with-ul:after {
    content: "\f107";
    position: absolute;
    right: 15px;
    font-family: FontAwesome;
    font-style: normal;
    font-weight: normal;
}

.sf-arrows ul .sf-with-ul:after {
    content: "\f105";
}


/* Nav Meu Container */

#nav-menu-container {
    float: right;
    margin: 0;
}

#nav-menu-container a {
    opacity: 0.8;
}

.menu-active a {
    opacity: 1!important;
}

#nav-menu-container a:hover {
    opacity: 1;
    color: #007bff!important;
}

@media (max-width: 768px) {
    #nav-menu-container {
        display: none;
    }
}


/* Nav Meu Styling */

.nav-menu a {
    padding: 5px 8px;
    text-decoration: none;
    display: inline-block;
    color: white;
    letter-spacing: 1px;
    font-family: Roboto;
    font-weight: 100;
    font-size: 0.8rem;
    outline: none;
}

.nav-menu>li {
    margin-left: 10px;
}

.nav-menu>li>a:before {
    content: "";
    position: absolute;
    width: 100%;
    height: 2px;
    bottom: 0;
    left: 0;
    background-color: #007bff;
    visibility: hidden;
    -webkit-transform: scaleX(0);
    transform: scaleX(0);
    -webkit-transition: all 0.3s ease-in-out 0s;
    transition: all 0.3s ease-in-out 0s;
}

.nav-menu a:hover:before,
.nav-menu li:hover>a:before,
.nav-menu .menu-active>a:before {
    visibility: visible;
    -webkit-transform: scaleX(1);
    transform: scaleX(1);
    color: #007bff!important;
}

a:hover {
    color: #1d96f5!important;
    text-decoration: none!important;
}

.nav-menu ul {
    margin: 4px 0 0 0;
    border: 1px solid #e7e7e7;
}

.nav-menu ul li {
    background: white;
;
}

.nav-menu ul li:first-child {
    border-top: 0;
}

.nav-menu ul li a {
    padding: 10px;
    color: #333;
    transition: 0.3s;
    display: block;
    font-size: 13px;
    text-transform: none;
}

.nav-menu ul li a:hover {
    background: #007bff;
    color: #007bff;
;
}

.nav-menu ul ul {
    margin: 0;
}


/* Mobile Nav Toggle */

#mobile-nav-toggle {
    position: fixed;
    right: 0;
    top: 0;
    z-index: 999;
    margin: 20px 20px 0 0;
    border: 0;
    background: none;
    font-size: 24px;
    display: none;
    transition: all 0.4s;
    outline: none;
    cursor: pointer;
}

#mobile-nav-toggle i {
    color: white;
;
}

@media (max-width : 768px) {
    #mobile-nav-toggle {
        display: inline;
    }
}


/* Mobile Nav Styling */

#mobile-nav {
    position: fixed;
    top: 0;
    padding-top: 18px;
    bottom: 0;
    z-index: 998;
    background: rgba(52, 59, 64, 0.9);
    left: -260px;
    width: 260px;
    overflow-y: auto;
    transition: 0.4s;
}

#mobile-nav ul {
    padding: 0;
    margin: 0;
    list-style: none;
}

#mobile-nav ul li {
    position: relative;
}

#mobile-nav ul li a {
    color: white;
    font-size: 16px;
    overflow: hidden;
    padding: 10px 22px 10px 30px;
    position: relative;
    text-decoration: none;
    width: 100%;
    display: block;
    outline: none;
}

#mobile-nav ul li a:hover {
    color: #007bff;
;
}

#mobile-nav ul li li {
    padding-left: 30px;
}

#mobile-nav ul .menu-has-children i {
    position: absolute;
    right: 0;
    z-index: 99;
    padding: 15px;
    cursor: pointer;
    color: white;
;
}

#mobile-nav ul .menu-has-children i.fa-chevron-up {
    color: #007bff;
}

#mobile-nav ul .menu-item-active {
    color: #007bff;
}

#mobile-body-overly {
    width: 100%;
    height: 100%;
    z-index: 997;
    top: 0;
    left: 0;
    position: fixed;
    background: rgba(52, 59, 64, 0.9);
    display: none;
}


/* Mobile Nav body classes */

body.mobile-nav-active {
    overflow: hidden;
}

body.mobile-nav-active #mobile-nav {
    left: 0;
}

body.mobile-nav-active #mobile-nav-toggle {
    color: white;
;
}


/*--------------------------------------------------------------
# Sections --------------------------------------------------------------*/


/* Sections Header --------------------------------*/

.title {
    font-weight: 500;
    font-size: 25px;
    /* letter-spacing: 3px; */
    color: var(--font-color-title);
}

#header #logo h1 {
    /* opacity:
0.8; */
}

#about2 thead td {
    font-size: 18px;
    padding: 15px 5px;
}

.nav-menu a:hover {
    opacity: 1!important
}

.section-header .section-title {
    font-size: 25px;
    color: var(--font-color-title);
    text-transform: uppercase;
    text-align: center;
    font-weight: 700;
    margin-bottom: 5px;
}

.section-header .section-description {
    text-align: center;
    padding-bottom: 40px;
    color: var(--font-color);
    padding: 0 15px;
}

.section-description {
    color: var(--font-color);
    padding: 0 15px;
}

/* About Us Section --------------------------------*/

#about,
#shema,
#iot {
    background: var(--bg-color-box);
    padding: 80px 0;
}
#esp, #iot{
    padding: 80px 0;
}
#esp img, #iot img {
    position: absolute;
    right: -20%;
    width: 60%!important;
    visibility: visible;
    animation-name: fadeInRight;
}
#esps {
    background: linear-gradient(120deg, #3d82ea, #7f68dc);
    background-repeat: no-repeat;
    background-attachment: fixed !important;
    background-size: auto 100%;
    background-size: cover;
    -webkit-clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
    clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
    padding: 100px 0;
}

#top {
    padding: 100px 0;
    background: linear-gradient(120deg, #3d82ea, #7f68dc);
    background-size: cover;
    color: white;
        -webkit-clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
    clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
}

#top .about-container .title {
    color: #333;
    font-weight: 700;
    font-size: 25px;
    margin-bottom: 60px;
}

#shema .shema-container .title {
    font-weight: 700;
    font-size: 25px;
    margin-bottom: 5px;
}

#shema .col-md-1 {
    padding: 0!important;
}

#about .about-container .background {
    min-height: 400px;
    margin-top: -80px;
    background: url(../img/ARMS_P3.png) center center no-repeat;
    background-size: auto 100%;
}

#about .about-container .content,
#esp .about-container .content,
#iot .about-container .content {
    background: var(--bg-color-box);
}
.sub-icon {
    background: #010101;
    border-radius: 10px;
    font-size: 25px!important;
    padding: 7px;
    margin-right: 10px;
}
h6{
    font-size: 0.8rem!important;
    font-weight: 100!important;
    margin-bottom: 50px!important;
    letter-spacing: 3px;
}
#about .about-container .title,
#esp .about-container .title,
#iot .about-container .title {
    color: var(--font-color-title);
    font-weight: 700;
    font-size: 25px;
    margin-bottom: 5px;
}
#esps .about-container .title {
    color: var(--font-color);
}

@media (max-width: 768px) {
    #about .about-container .title {
        padding-top: 15px;
    }
}
#contact label,
#logo label {
    display: none;
}

#about .about-container p,
#esp .about-container p,
#iot .about-container p {
    line-height: 26px;
    color: var(--font-color);
}
#esps .about-container p {
    line-height: 26px;
    color: white; 
}
#about .about-container p:last-child {
    margin-bottom: 0;
}

#about .about-container .icon-box {
    background: white;
;
    background-size: cover;
    padding: 5px 0;
}

#about .about-container .icon-box .icon {
    float: left;
    background: white;
;
    padding: 16px;
    border-radius: 50%;
    border: 2px solid #007bff;
}

#about .about-container .icon-box .icon i {
    color: #007bff;
    font-size: 24px;
}

#about .about-container .icon-box .title {
    margin-left: 80px;
    font-weight: 500;
    margin-bottom: 5px;
    font-size: 18px;
    text-transform: uppercase;
}

#about .about-container .icon-box .title a {
    color: #111;
}

#about .about-container .icon-box .description {
    margin-left: 50px;
    line-height: 24px;
    font-size: 0.8rem;
}


/* Facts Section --------------------------------*/

#facts {
    background: #f7f7f7;
    padding: 80px 0 60px 0;
}

#facts .counters span {
    font-size: 48px;
    display: block;
    color: #007bff;
}

#facts .counters p {
    padding: 0;
    margin: 0 0 20px 0;
    font-family: Roboto;
    font-size: 0.8rem;
}


/* Services Section --------------------------------*/

#services2 {
    background: var(--bg-color-box);
    background-size: cover;
    padding: 80px 15px 60px 15px;
}

#homepage {
    background-attachment: fixed !important;
    background: url(../img/ipad.jpg) center center!important;
    background-size: auto 100%!important;
    background-size: cover!important;
    position: inherit;
    padding: 80px 15px 80px 15px!important;
    height: 750px;
}

#interface {
    background-attachment: fixed !important;
    background-size: auto 100%!important;
    background-size: cover!important;
    position: inherit;
    padding: 100px 15px 100px 15px!important;
    /* background: linear-gradient(#528ce3, #7782ff);
*/
    background: linear-gradient(120deg, #3d82ea, #7f68dc);
    color: white!important;

        -webkit-clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
    clip-path: polygon(0 10%, 100% 0, 100% 90%, 0 100%);
}

#services .box {
    padding: 20px;
    margin-bottom: 30px;
    border: 1px solid #e6e6e6;
    position: relative;
}

#services .icon {
    position: absolute;
    top: -36px;
    left: calc(50% - 36px);
    transition: 0.2s;
    border-radius: 50%;
    display: inline-block;
    border: 6px solid white;
;
}

#services .data-table img {
    border-style: none;
    width: 40px;
    height: auto;
    float: right;
    margin-top: -10px;
}

#services .data-table a {
    padding-top: 25px;
    width: 95%;
}

#adc_value,
#adc_value-2,
#adc_value-3 {
    display: none;
}

#services .icon a {
    display: inline-block;
    background: #007bff;
    border: 2px solid #007bff;
    padding: 16px;
    border-radius: 50%;
    transition: 0.3s;
}

#services .icon i {
    color: white;
;
    font-size: 24px;
}

#services .box:hover .icon i {
    color: #007bff;
}

#services .box:hover .icon a {
    color: #007bff;
    background: white;
;
}

#services .title {
    font-weight: 500;
    font-size: 18px;
    margin-bottom: 15px;
    text-transform: uppercase;
}

#services .title a {
    color: #111;
}

#services .description {
    font-size: 0.8rem;
    line-height: 24px;
}


/* Call To Action Section --------------------------------*/

/* #call-to-action {
    background: linear-gradient(rgba(0, 0, 0, 0.6), rgba(0, 0, 0, 0.6)), url(../img/call-to-action-bg.jpg) fixed center center;
    background-size: cover;
    padding: 80px 0;
}

#call-to-action .cta-title {
    color: white;
;
    font-size: 28px;
    font-weight: 500;
}

#call-to-action .cta-text {
    color: white;
;
}

@media (min-width: 769px) {
    #call-to-action .cta-btn-container {
        display: flex;
        align-items: center;
        justify-content: flex-end;
    }
}

#call-to-action .cta-btn {
    font-family: Roboto;
    text-transform: uppercase;
    font-weight: 500;
    font-size: 16px;
    letter-spacing: 1px;
    display: inline-block;
    padding: 8px 30px;
    border-radius: 50px;
    transition: 0.5s;
    margin: 10px;
    border: 2px solid white;
;
    color: white;
;
}

#call-to-action .cta-btn:hover {
    background: #007bff;
    border: 2px solid #007bff;
} */


/* Portfolio Section --------------------------------*/

#portfolio {
    background: #f7f7f7;
    padding: 80px 0;
}

#portfolio #portfolio-wrapper {
    padding-right: 15px;
}

#portfolio #portfolio-flters {
    padding: 0;
    margin: 0 0 45px 0;
    list-style: none;
    text-align: center;
}

#portfolio #portfolio-flters li {
    cursor: pointer;
    margin: 0 10px;
    display: inline-block;
    padding: 10px 22px;
    font-size: 0.8rem;
    line-height: 20px;
    color: #666666;
    border-radius: 4px;
    text-transform: uppercase;
    background: white;
;
    margin-bottom: 5px;
    transition: all 0.3s ease-in-out;
}

#portfolio #portfolio-flters li:hover,
#portfolio #portfolio-flters li.filter-active {
    color: white;
;
}

#portfolio .portfolio-item {
    position: relative;
    height: 200px;
    overflow: hidden !important;
    margin-bottom: 15px;
    transition: all 350ms ease;
    transform: scale(1);
}

#portfolio .portfolio-item a {
    display: block;
    margin-right: 15px;
}

#portfolio .portfolio-item img {
    position: relative;
    top: 0;
    transition: all 600ms cubic-bezier(0.645, 0.045, 0.355, 1);
}

#portfolio .portfolio-item .details {
    height: 50px;
    background: #007bff;
    position: absolute;
    width: 100%;
    height: 50px;
    bottom: -50px;
    transition: all 300ms cubic-bezier(0.645, 0.045, 0.355, 1);
}

#portfolio .portfolio-item .details h4 {
    font-size: 0.8rem;
    font-weight: 500;
    color: white;
    padding: 8px 0 2px 8px;
    margin: 0;
}

#portfolio .portfolio-item .details span {
    display: block;
    color: white;
;
    font-size: 13px;
    padding-left: 8px;
}

#portfolio .portfolio-item:hover .details {
    bottom: 0;
}

#portfolio .portfolio-item:hover img {
    top: -30px;
}


/* Team Section --------------------------------*/

#part {
    background: #ececec;
    padding: 30px 0 30px 0;
}

#team,
#for2 {
    background: white;
    padding: 80px 0 60px 0;
}

#for2 h4 {
    color: #222;
}

#for2 h4:hover {
    color: #007bff;
}

#for2 b {
    color: #007bff;
    font-weight: normal!important;
}

#team .member {
    text-align: center;
    margin-bottom: 20px;
}

#team .member .pic {
    margin-bottom: 15px;
    overflow: hidden;
    height: 260px;
}

#team .member .pic img {
    max-width: 100%;
}

#team .member h4 {
    font-weight: 500;
    margin-bottom: 2px;
    font-size: 18px;
}

#team .member span {
    font-style: italic;
    display: block;
    font-size: 13px;
}

#team .member .social {
    margin-top: 15px;
}

#team .member .social a {
    color: #b3b3b3;
}

#team .member .social a:hover {
    color: #007bff;
}

#team .member .social i {
    font-size: 18px;
    margin: 0 2px;
}


/* Contact Section --------------------------------*/

#contact {
    padding: 80px 0 40px 0;
    background-attachment: fixed !important;
    background: linear-gradient(rgba(0, 36, 169, 0.25), rgba(34, 14, 197, 0.35)), url(../img/photo-1451188214936-ec16af5ca155.webp) center center no-repeat;
    іі background-size: auto 100%;
    background-size: cover;
}

#contact #google-map {
    height: 300px;
    margin-bottom: 20px;
}

#contact .info {
    color: white;
}

#contact .info i {
    font-size: 25px;
    color: #007bff;
    float: left;
}

#contact .info p {
    /* padding: 0 0 10px 50px; */
    margin-bottom: 20px;
    line-height: 22px;
    font-size: 0.8rem;
}

#contact .info .email p {
    padding-top: 5px;
}

#contact .social-links {
    padding-bottom: 20px;
}

#contact .social-links a {
    font-size: 18px;
    display: inline-block;
    background: #333;
    color: white;
;
    line-height: 1;
    padding: 8px 0;
    border-radius: 50%;
    text-align: center;
    width: 36px;
    height: 36px;
    transition: 0.3s;
}

#contact .social-links a:hover {
    background: #007bff;
    color: white;
;
}

#contact .form #sendmessage {
    color: #007bff;
    border: 1px solid #007bff;
    display: none;
    text-align: center;
    padding: 15px;
    font-weight: 600;
    margin-bottom: 15px;
}

#contact .form #errormessage {
    color: red;
    display: none;
    border: 1px solid red;
    text-align: center;
    padding: 15px;
    font-weight: 600;
    margin-bottom: 15px;
}

#contact .form #sendmessage.show,
#contact .form #errormessage.show,
#contact .form .show {
    display: block;
}

#contact .form .validation {
    color: red;
    display: none;
    margin: 0 0 20px;
    font-weight: 400;
    font-size: 13px;
}

#contact .form input,
#contact .form textarea {
    border-radius: 0;
    box-shadow: none;
    font-size: 0.8rem;
    border: none;
}

#contact .form button[type="submit"] {
    cursor: pointer;
    background: #007bff;
    border: 0;
    padding: 10px 24px;
    color: white;
    border-radius: 20px;
    transition: 0.4s;
}

#contact .form button[type="submit"]:hover {
    cursor: pointer;
    background: #007bff;
}


/*-------------------------------------------------------------- # Footer --------------------------------------------------------------*/

#footer {
    background: #131417;
    padding: 30px 0 0;
    color: white;
    font-size: 0.8rem;
}

#footer .copyright {
    text-align: center;
    font-size: 0.7rem;
    margin-top: 30px;
    padding: 30px 0;
    background: #010101;
}

#footer .credits {
    padding-top: 10px;
    text-align: center;
    font-size: 13px;
    color: #ccc;
}

@-webkit-keyframes scroll {
    0%,
    20% {
        -webkit-transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
        transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
    }
    10% {
        -webkit-transform: translateY(0px) scaleY(1.2) scaleX(1.2) translateZ(0px);
        transform: translateY(0px) scaleY(1.2) scaleX(1.2) translateZ(0px);
        opacity: 1;
    }
    100% {
        -webkit-transform: translateY(20px) scaleY(2.5) scaleX(0.5) translateZ(0px);
        transform: translateY(20px) scaleY(2.5) scaleX(0.5) translateZ(0px);
        opacity: 0.01;
    }
}

@keyframes scroll {
    0%,
    20% {
        -webkit-transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
        transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
    }
    10% {
        -webkit-transform: translateY(0px) scaleY(1.2) scaleX(1.2) translateZ(0px);
        transform: translateY(0px) scaleY(1.2) scaleX(1.2) translateZ(0px);
        opacity: 1;
    }
    100% {
        -webkit-transform: translateY(20px) scaleY(2.5) scaleX(0.5) translateZ(0px);
        transform: translateY(20px) scaleY(2.5) scaleX(0.5) translateZ(0px);
        opacity: 0.01;
    }
}

@-webkit-keyframes chevron {
    0% {
        opacity: 0;
    }
    50% {
        opacity: 1;
    }
    100% {
        opacity: 0;
    }
}

@keyframes chevron {
    0% {
        opacity: 0;
    }
    50% {
        opacity: 1;
    }
    100% {
        opacity: 0;
    }
}

.mouse {
    border: 4px solid #007aff;
    border-radius: 26px;
    position: absolute;
    top: 85%;
    left: 50%;
    width: 30px;
    height: 55px;
    -webkit-backface-visibility: hidden;
    -webkit-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
}

.mouse::after {
    background-color: #007aff;
    border-radius: 100%;
    content: "";
    position: absolute;
    top: 10px;
    left: 50%;
    margin-left: -2px;
    width: 5px;
    height: 5px;
    opacity: 1;
    -webkit-transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
    transform: translateY(0px) scaleY(1) scaleX(1) translateZ(0px);
    -webkit-animation: scroll 1.5s -1s cubic-bezier(0.68, -0.55, 0.265, 1.55) infinite;
    animation: scroll 1.5s -1s cubic-bezier(0.68, -0.55, 0.265, 1.55) infinite;
}

.mouse-line span {
    width: 14px;
    height: 15px;
    position: absolute;
    top: 85%;
    left: 50%;
    -webkit-transform: rotate(45deg);
    transform: rotate(45deg);
    border-right: 4px solid #007aff;
    border-bottom: 4px solid #007aff;
    margin: 0 0 0 -8px;
    border-radius: 3px;
}

.mouse-line .eins,
.mouse-line .zwei,
.mouse-line .drei {
    -webkit-animation: chevron 2.5s infinite;
    animation: chevron 2.5s infinite;
}

.mouse-line .eins {
    margin-top: 36px;
    -moz-animation-delay: .1s;
    -webkit-animation-delay: .1s;
    -webkit-animation-direction: alternate;
}

.mouse-line .zwei {
    margin-top: 48px;
    -moz-animation-delay: .5s;
    -webkit-animation-delay: .5s;
    -webkit-animation-direction: alternate;
}

.mouse-line .drei {
    margin-top: 60px;
    -moz-animation-delay: .9s;
    -webkit-animation-delay: .9s;
    -webkit-animation-direction: alternate;
}

body {
    background-color: #1d1f20;
}

.dot {
    border-radius: 50%;
    height: 12px;
    width: 12px;
    position: absolute;
    margin: 5px 0;
}

.dot.blue {
    background-color: #26B3FF;
}

.dot.blue span {
    background-color: rgba(85, 216, 232, 0.4);
}

.dot.blue span:after {
    background-color: rgba(85, 216, 232, 0.4);
}

.dot.green {
    background-color: #35E861;
}

.dot.green span {
    background-color: rgba(110, 255, 122, 0.4);
}

.dot.green span:after {
    background-color: rgba(110, 255, 122, 0.4);
}

.dot.red {
    background-color: #FF4B44;
}

.dot.red span {
    background-color: rgba(232, 111, 112, 0.4);
}

.dot.red span:after {
    background-color: rgba(232, 111, 112, 0.4);
}

.dot.orange {
    background-color: #E87337;
}

.dot.orange span {
    background-color: rgba(255, 183, 90, 0.4);
}

.dot.orange span:after {
    background-color: rgba(255, 183, 90, 0.4);
}

@keyframes cursor {
    0% {
        opacity: 0;
    }
    49.9% {
        opacity: 0;
    }
    50% {
        opacity: 1;
    }
    99.9% {
        opacity: 1;
    }
}

#particles {
    position: absolute;
    width: 100%;
    height: 100vh;
    top: 0;
    left: 0;
}

.vert-text {
    display: table-cell;
    position: relative;
    vertical-align: middle;
    text-align: center;
    width: 1%;
}

@-webkit-keyframes sdb {
    0% {
        opacity: 0;
    }
    30% {
        opacity: 1;
    }
    60% {
        box-shadow: 0 0 0 60px rgba(255, 255, 255, 0.1);
        opacity: 0;
    }
    100% {
        opacity: 0;
    }
}

@keyframes sdb {
    0% {
        opacity: 0;
    }
    30% {
        opacity: 1;
    }
    60% {
        box-shadow: 0 0 0 60px rgba(255, 255, 255, 0.1);
        opacity: 0;
    }
    100% {
        opacity: 0;
    }
}

#navbarResponsive {
    height:40px;
}
.nav-link.logo{
    padding: 21px;
}
.logo-svg {
    width: 50px;
    margin-top: 0px!important;
    padding-right: 0px!important;
    margin: 0 auto;
    display: block;
}
.title-logo {
    color:white!important;
}
#chartdiv,
#chartdiv-second,
#chartdiv-2,
#chartdiv-2-second,
#chartdiv-3,
#chartdiv-3-second {
    width: 100%;
    height: 300px;
}

.box {
    box-shadow: 0 0px 1px rgba(0, 0, 0, 0.15);
    background-color: white;
;
}

.box-divider {
    border-bottom: 1px solid rgba(120, 130, 140, 0.13);
    margin: 0 16px;
    height: 0;
}

.row {
    display: -ms-flexbox;
    display: flex;
    -ms-flex-wrap: wrap;
    flex-wrap: wrap;
    margin-right: 0px!important;
    margin-left: 0px!important;
    max-width: 100%;
}

.toggle-btn {
    width: 80px;
    height: 40px;
    border-radius: 50px;
    float: right;
    position: relative;
    background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAyklEQVQ4T42TaxHCQAyENw5wAhLACVUAUkABOCkSwEkdhNmbpHNckzv689L98toIAKjqGcAFwElEFr5ln6ruAMwA7iLyFBM/TPDuQSrxwf6fCKBoX2UMIYGYkg8BLOnVg2RiAEexGaQQq4w9e9klcxGLLAUwgDAcihlYAR1IvZA1sz/+AAaQjXhTQQVoe2Yo3E7UQiT2ijeQdojRtClOfVKvMVyVpU594kZK9zzySWTlcNqZY9tjCsUds00+A57z1e35xzlzJjee8xf0HYp+cOZQUQAAAABJRU5ErkJggg==") no-repeat 50px center #e74c3c;
    cursor: pointer;
    -webkit-transition: background-color .40s ease-in-out;
    -moz-transition: background-color .40s ease-in-out;
    -o-transition: background-color .40s ease-in-out;
    transition: background-color .40s ease-in-out;
    cursor: pointer;
}

.toggle-btn.active {
    background: url("data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAAmUlEQVQ4T6WT0RWDMAhFeZs4ipu0mawZpaO4yevBc6hUIWLNd+4NeQDk5sE/PMkZwFvZywKSTxF5iUgH0C4JHGyF97IggFVSqyCFga0CvQSg70Mdwd8QSSr4sGBMcgavAgdvwQCtApvA2uKr1x7Pu++06ItrF5LXPB/CP4M0kKTwYRIDyRAOR9lJTuF0F0hOAJbKopVHOZN9ACS0UgowIx8ZAAAAAElFTkSuQmCC") no-repeat 10px center #2ecc71;
}

.toggle-btn.active .round-btn {
    left: 45px;
}

.toggle-btn .round-btn {
    width: 30px;
    height: 30px;
    background-color: white;
;
    border-radius: 50%;
    display: inline-block;
    position: absolute;
    left: 5px;
    top: 50%;
    margin-top: -15px;
    -webkit-transition: all .30s ease-in-out;
    -moz-transition: all .30s ease-in-out;
    -o-transition: all .30s ease-in-out;
    transition: all .30s ease-in-out;
}

.toggle-btn .cb-value {
    position: absolute;
    left: 0;
    right: 0;
    width: 100%;
    height: 100%;
    opacity: 0;
    z-index: 9;
    cursor: pointer;
    -ms-filter: "progid:DXImageTransform.Microsoft.Alpha(Opacity=0)";
}

#about2 {
    background-attachment: fixed !important;
    background: linear-gradient(120deg, #3d82ea, #7f68dc);
    background-size: auto 100%;
    background-size: cover;
    padding: 50px;
}

.rellay-div {
    padding: 10px 0;
    margin-bottom: 15px;
}

.ico-div {
    margin: 0;
}

.padding-zero {
    padding: 0!important;
}

#table1,
#table1Temp,
#table1Hum,
table {
    width: 100%;
    background: white;
    font-size: 0.8rem;
    font-family: Roboto;
}
.table-property {
    width: 100%;
    overflow: auto;
}

td,
th {
    padding: 5px!important;
    border-bottom: 1px solid #ffffff3b;
    border-bottom: 1px solid white!important;
}

td:first-child,
th:first-child {
//width: 50%; vertical-align: top; border-bottom: 1px solid white; } td:last-child, th:last-child { padding-right: 20px; border-bottom: 1px solid white!important;
                                                                     }

th {
    border-bottom: 1px solid #ddd;
    position: relative;
}

.redColor {
    background-color: #e62c2c;
    color: white;
}

.greenColor {
    background-color: #0abf44;
    color: white;
}

.row-img {
    position: absolute;
    z-index: 1;
    margin: 0 10%;
    width: 80%;
}

.ico-div img {
    margin: 0!important;
}

.button13 {
    box-shadow: 0 3px 20px #0400ff85;
    background: linear-gradient(-60deg, rgba(65, 113, 255, 1) 0%, rgba(0, 63, 255, 1) 100%)!important;
    cursor: pointer;
}

.b-text{
    color: #222!important;
}

.button {
    cursor: pointer;
    display: inline-block;
    padding: .7em 2.2em;
    border-radius: 1.6em;
    color: #fff;
    font-size: 0.8rem;
    font-family: Roboto;
    font-weight: 500;
    text-align: center;
    text-decoration: none;
    letter-spacing: 1px;
}

.button13:hover {
    background: linear-gradient(-60deg, rgb(48, 95, 235) 0%, rgb(3, 52, 201) 100%);
    color: #fff!important;
}

#about2 .box {
    background-color: transparent;
    color: white;
}

#about2 table tr {
    border-bottom: 1px solid white;
}

#table1,
table {
    background: transparent;
}

@media (max-width: 991px) {
    .col-md-6,
    .col-lg-6 {
        min-height: 0;
        width: 50%
    }
    #about .about-container .background {
        background-size: 100%;
    }
    .boxadmin {
        width: 100%!important;
        //margin-bottom: 30px!important;
        //height: 120px!important;
        //min-height: 120px!important;
    }
    #about2 .col-md-6 {
        width: 100%
    }
}

@media (max-width: 950px) {
    #about2 .col-md-6 {
        width: 100%
    }
    #shema .col-md-1 {
        width: 33.333%;
        padding: 20px!important;
    }
}

@media (max-width: 800px) {
    .col-xs-4 {
        width: 33.333%;
        padding: 20px!important;
    }
    .hide-sm {
        display: none!important;
        background: none!important;
        min-height: 0!important;
    }
    #about .about-container .background {
        background: none;
        min-height: 0;
        background-size: 100%;
    }
    #about .about-container .col-md-6 {
        width: 100%
    }
    #shema .col-md-1 {
        width: 33.333%;
        padding: 20px!important;
    }
    #shema .shema-container .arrow {
        display: none!important;
    }
    .justify-content-center {
        padding: 0!important;
    }
}

@media (max-width: 500px) {
    .col-xs-4 {
        width: 50%
    }
    selection,
    #about2 {
        padding: 30px 0!important;
    }
    .selection {
        padding: 30px 0!important;
    }
    .justify-content-center {
        padding: 0%!important;
    }
}

@media (max-width: 350px) {
    .col-xs-4 {
        width: 100%
    }
}

#footer img {
    width: auto;
    margin: 0!important;
}

#footer b {
    letter-spacing: 3px;
    font-weight: 300;
    line-height: 3;
}

#animation {
    width: 100%;
    height: 100%;
    overflow: auto;
    margin: auto;
    align: middle;
    opacity: 1.0;
}

#footer {
    color: #c4c6c7
}

@-webkit-keyframes preload-show-1 {
    from {
        -webkit-transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-1 {
    from {
        -webkit-transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-1 {
    to {
        -webkit-transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-1 {
    to {
        -webkit-transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-1 {
    5% {
        -webkit-transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    10%,
    75% {
        -webkit-transform: rotateZ(60deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    80%,
    100% {
        -webkit-transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-1 {
    5% {
        -webkit-transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    10%,
    75% {
        -webkit-transform: rotateZ(60deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    80%,
    100% {
        -webkit-transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(60deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-show-2 {
    from {
        -webkit-transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-2 {
    from {
        -webkit-transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-2 {
    to {
        -webkit-transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-2 {
    to {
        -webkit-transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-2 {
    10% {
        -webkit-transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    15%,
    70% {
        -webkit-transform: rotateZ(120deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    75%,
    100% {
        -webkit-transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-2 {
    10% {
        -webkit-transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    15%,
    70% {
        -webkit-transform: rotateZ(120deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    75%,
    100% {
        -webkit-transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(120deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-show-3 {
    from {
        -webkit-transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-3 {
    from {
        -webkit-transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-3 {
    to {
        -webkit-transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-3 {
    to {
        -webkit-transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-3 {
    15% {
        -webkit-transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    20%,
    65% {
        -webkit-transform: rotateZ(180deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    70%,
    100% {
        -webkit-transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-3 {
    15% {
        -webkit-transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    20%,
    65% {
        -webkit-transform: rotateZ(180deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    70%,
    100% {
        -webkit-transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(180deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-show-4 {
    from {
        -webkit-transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-4 {
    from {
        -webkit-transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-4 {
    to {
        -webkit-transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-4 {
    to {
        -webkit-transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-4 {
    20% {
        -webkit-transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    25%,
    60% {
        -webkit-transform: rotateZ(240deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    65%,
    100% {
        -webkit-transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-4 {
    20% {
        -webkit-transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    25%,
    60% {
        -webkit-transform: rotateZ(240deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    65%,
    100% {
        -webkit-transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(240deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-show-5 {
    from {
        -webkit-transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-5 {
    from {
        -webkit-transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-5 {
    to {
        -webkit-transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-5 {
    to {
        -webkit-transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-5 {
    25% {
        -webkit-transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    30%,
    55% {
        -webkit-transform: rotateZ(300deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    60%,
    100% {
        -webkit-transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-5 {
    25% {
        -webkit-transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    30%,
    55% {
        -webkit-transform: rotateZ(300deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    60%,
    100% {
        -webkit-transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(300deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-show-6 {
    from {
        -webkit-transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-show-6 {
    from {
        -webkit-transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-hide-6 {
    to {
        -webkit-transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-hide-6 {
    to {
        -webkit-transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(-90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-cycle-6 {
    30% {
        -webkit-transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    35%,
    50% {
        -webkit-transform: rotateZ(360deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    55%,
    100% {
        -webkit-transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@keyframes preload-cycle-6 {
    30% {
        -webkit-transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
    35%,
    50% {
        -webkit-transform: rotateZ(360deg) rotateY(0) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(0) rotateX(0deg);
        border-left-color: #007bff;
    }
    55%,
    100% {
        -webkit-transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        transform: rotateZ(360deg) rotateY(90deg) rotateX(0deg);
        border-left-color: #6610f2;
    }
}

@-webkit-keyframes preload-flip {
    0% {
        -webkit-transform: rotateY(0deg) rotateZ(-60deg);
        transform: rotateY(0deg) rotateZ(-60deg);
    }
    100% {
        -webkit-transform: rotateY(360deg) rotateZ(-60deg);
        transform: rotateY(360deg) rotateZ(-60deg);
    }
}

@keyframes preload-flip {
    0% {
        -webkit-transform: rotateY(0deg) rotateZ(-60deg);
        transform: rotateY(0deg) rotateZ(-60deg);
    }
    100% {
        -webkit-transform: rotateY(360deg) rotateZ(-60deg);
        transform: rotateY(360deg) rotateZ(-60deg);
    }
}

#loader {
    position: absolute;
    width: 100%;
    background: #222;
    height: 100vh;
    z-index: 999;
    opacity: 1;
    visibility: visible;
}

.done {
    opacity: 0!important;
    visibility: hidden!important;
}

.preloader {
    position: absolute;
    top: 50vh;
    left: 50%;
    font-size: 20px;
    display: block;
    width: 3.75em;
    height: 4.25em;
    margin-left: -1.875em;
    margin-top: -2.125em;
    z-index: 5;
    -webkit-transform-origin: center center;
    transform-origin: center center;
    -webkit-transform: rotateY(180deg) rotateZ(-60deg);
    transform: rotateY(180deg) rotateZ(-60deg);
}

.preloader .slice {
    border-top: 1.125em solid transparent;
    border-right: none;
    border-bottom: 1em solid transparent;
    border-left: 1.875em solid #007bff;
    position: absolute;
    top: 0px;
    left: 50%;
    -webkit-transform-origin: left bottom;
    transform-origin: left bottom;
    border-radius: 3px 3px 0 0;
}

.preloader .slice:nth-child(1) {
    -webkit-transform: rotateZ(60deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(60deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.82s preload-hide-1 both 1;
    animation: 0.15s linear 0.82s preload-hide-1 both 1;
}

.preloader .slice:nth-child(2) {
    -webkit-transform: rotateZ(120deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(120deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.74s preload-hide-2 both 1;
    animation: 0.15s linear 0.74s preload-hide-2 both 1;
}

.preloader .slice:nth-child(3) {
    -webkit-transform: rotateZ(180deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(180deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.66s preload-hide-3 both 1;
    animation: 0.15s linear 0.66s preload-hide-3 both 1;
}

.preloader .slice:nth-child(4) {
    -webkit-transform: rotateZ(240deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(240deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.58s preload-hide-4 both 1;
    animation: 0.15s linear 0.58s preload-hide-4 both 1;
}

.preloader .slice:nth-child(5) {
    -webkit-transform: rotateZ(300deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(300deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.5s preload-hide-5 both 1;
    animation: 0.15s linear 0.5s preload-hide-5 both 1;
}

.preloader .slice:nth-child(6) {
    -webkit-transform: rotateZ(360deg) rotateY(0deg) rotateX(0);
    transform: rotateZ(360deg) rotateY(0deg) rotateX(0);
    -webkit-animation: 0.15s linear 0.42s preload-hide-6 both 1;
    animation: 0.15s linear 0.42s preload-hide-6 both 1;
}

.preloader.loading {
    -webkit-animation: 2s preload-flip steps(2) infinite both;
    animation: 2s preload-flip steps(2) infinite both;
}

.preloader.loading .slice:nth-child(1) {
    -webkit-transform: rotateZ(60deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(60deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-1 linear infinite both;
    animation: 2s preload-cycle-1 linear infinite both;
}

.preloader.loading .slice:nth-child(2) {
    -webkit-transform: rotateZ(120deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(120deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-2 linear infinite both;
    animation: 2s preload-cycle-2 linear infinite both;
}

.preloader.loading .slice:nth-child(3) {
    -webkit-transform: rotateZ(180deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(180deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-3 linear infinite both;
    animation: 2s preload-cycle-3 linear infinite both;
}

.preloader.loading .slice:nth-child(4) {
    -webkit-transform: rotateZ(240deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(240deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-4 linear infinite both;
    animation: 2s preload-cycle-4 linear infinite both;
}

.preloader.loading .slice:nth-child(5) {
    -webkit-transform: rotateZ(300deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(300deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-5 linear infinite both;
    animation: 2s preload-cycle-5 linear infinite both;
}

.preloader.loading .slice:nth-child(6) {
    -webkit-transform: rotateZ(360deg) rotateY(90deg) rotateX(0);
    transform: rotateZ(360deg) rotateY(90deg) rotateX(0);
    -webkit-animation: 2s preload-cycle-6 linear infinite both;
    animation: 2s preload-cycle-6 linear infinite both;
}

#mainNav .navbar-collapse {
    overflow: auto;
    max-height: 75vh;
}

#mainNav .navbar-collapse .navbar-nav .nav-item .nav-link {
    cursor: pointer;
}

#mainNav .navbar-collapse .navbar-nav .nav-item .nav-link:hover {
    background: #fff;
}

#mainNav .navbar-collapse .navbar-sidenav .nav-link-collapse:after {
    float: right;
    content: '\f107';
    font-family: 'FontAwesome';
}

#mainNav .navbar-collapse .navbar-sidenav .nav-link-collapse.collapsed:after {
    content: '\f105';
}

#mainNav .navbar-collapse .navbar-sidenav .sidenav-second-level,
#mainNav .navbar-collapse .navbar-sidenav .sidenav-third-level {
    padding-left: 0;
}

#mainNav .navbar-collapse .navbar-sidenav .sidenav-second-level>li>a,
#mainNav .navbar-collapse .navbar-sidenav .sidenav-third-level>li>a {
    display: block;
    padding: 0.5em 0;
}

#mainNav .navbar-collapse .navbar-sidenav .sidenav-second-level>li>a:focus,
#mainNav .navbar-collapse .navbar-sidenav .sidenav-second-level>li>a:hover,
#mainNav .navbar-collapse .navbar-sidenav .sidenav-third-level>li>a:focus,
#mainNav .navbar-collapse .navbar-sidenav .sidenav-third-level>li>a:hover {
    text-decoration: none;
}

#mainNav .navbar-collapse .navbar-sidenav .sidenav-second-level>li>a {
    padding-left: 1em;
}

#mainNav .navbar-collapse .navbar-sidenav .sidenav-third-level>li>a {
    padding-left: 2em;
}

#mainNav .navbar-collapse .sidenav-toggler {
    display: none;
}

#mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link {
    position: relative;
    min-width: 45px;
}

#mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link:after {
    float: right;
    width: auto;
    content: '\f105';
    border: none;
    font-family: 'FontAwesome';
}

#mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link .indicator {
    position: absolute;
    top: 5px;
    left: 21px;
    font-size: 10px;
}

#mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown.show>.nav-link:after {
    content: '\f107';
}

#mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown .dropdown-menu>.dropdown-item>.dropdown-message {
    overflow: hidden;
    max-width: none;
    text-overflow: ellipsis;
}

.boxadmins {
    background-color: var(--bg-color)!important;
    padding: 20px!important;
    float: left!important;
    border: none!important;
    //min-height: 130px!important;
    border-radius: 10px!important;
    //box-shadow: 0 1.5px 10px #d8d8d8d6!important;
}

.boxadmin {
    padding: 10px;
    float: left;
}

.active-butt {
    color: #ffffff!important;
    text-transform: none!important;
}

.butt {
    background: #ffffff;
    border: 0px solid;
    color: #617083;
    font-weight: 500;
    text-transform: uppercase;
    font-size: 15px;
    outline: none !important;
    padding: 13px 10px 10px 10px;
    margin-right: -5px;
    width: 150px;
}

.first-butt {
    border-radius: 50px 0px 0px 50px;
}

.last-butt {
    border-radius: 0px 50px 50px 0px;
}

.title-box {
    padding: 15px;
    color: #617082;
    z-index: 1;
    padding: 0 0 30px 15px;
}

p {
    margin-top: 0;
    margin-bottom: 0px!important;
}
#services2 .boxadmin svg {
    margin: 0!important;
}
.title-box .section-description {
    color: #617082;
}

#table1,
table {
    font-size: 0.8rem;
}

.title-box h6 {
    margin: 0!important;
    font-size: 0.8rem;
    font-family: Roboto;
}
.table thead th {
    vertical-align: bottom;
    border-bottom: 2px solid #dee2e6;
    font-weight: 100;
}
.sub-item-menu {
  padding-left: 26px!important;
}
@media (min-width: 992px) {
    #mainNav .navbar-brand {
        width: 250px;
    }
    #mainNav .navbar-collapse {
        overflow: visible;
        max-height: none;
        box-shadow: 0 1.5px 10px #dfdfdfa8;
    }
    #mainNav .navbar-collapse .navbar-sidenav {
        position: absolute;
        top: 0;
        left: 0;
        -webkit-flex-direction: column;
        -ms-flex-direction: column;
        flex-direction: column;
        /* margin-top:
56px; */
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item {
        width: 150px;
        padding: 0;
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item>.nav-link {
        padding-left: 1.5em;
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level,
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level {
        padding-left: 0;
        list-style: none;
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li,
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li {
        width: 150px;
        cursor: pointer;
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a {
        padding-left: 3em;
    }
    #mainNav .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a {
        padding-left: 3.75em;
    }
    #mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link {
        min-width: 0;
    }
    #mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link:after {
        width: 24px;
        text-align: center;
    }
    #mainNav .navbar-collapse .navbar-nav>.nav-item.dropdown .dropdown-menu>.dropdown-item>.dropdown-message {
        max-width: 300px;
    }
}

#mainNav.fixed-top .sidenav-toggler {
    display: none;
}

.blue-num {
    color: var(--font-color-primary);
    font-size: 20px;
    font-weight: 600;
}

.diff-div {
    position: absolute;
    margin-top: 8px;
}

@media (min-width: 992px) {
    #mainNav.fixed-top .navbar-sidenav {
        height: calc(100vh - 1px);
    }
    #mainNav.fixed-top .sidenav-toggler {
        position: absolute;
        top: 0;
        left: 0;
        display: flex;
        -webkit-flex-direction: column;
        -ms-flex-direction: column;
        flex-direction: column;
        margin-top: calc(100vh - 42px);
    }
    #mainNav.fixed-top .sidenav-toggler>.nav-item {
        width: 150px;
        padding: 0;
    }
    #mainNav.fixed-top .sidenav-toggler>.nav-item>.nav-link {
        padding: 1em;
    }
}

#mainNav.fixed-top.navbar-dark .sidenav-toggler {
    background-color: #4d5b6e;
}

#mainNav.fixed-top.navbar-dark .sidenav-toggler a i {
    color: white;
}

.breadcrumb {
    display: -webkit-box;
    display: -ms-flexbox;
    display: flex;
    -ms-flex-wrap: wrap;
    flex-wrap: wrap;
    padding: .75rem 1rem;
    margin-bottom: 1rem;
    margin: 15px;
    list-style: none;
    background-color: #9ea5af;
    border-radius: .25rem;
}

.breadcrumb-item.active,
.breadcrumb-item+.breadcrumb-item::before {
    color: #f8f9fa;
}

#mainNav.fixed-top.navbar-light .sidenav-toggler {
    background-color: #212529;
}

#mainNav.fixed-top.navbar-light .sidenav-toggler a i {
    color: rgba(0, 0, 0, 0.5);
}

body.sidenav-toggled #mainNav.fixed-top .sidenav-toggler {
    overflow-x: hidden;
    width: 55px;
}

body.sidenav-toggled #mainNav.fixed-top .sidenav-toggler .nav-item,
body.sidenav-toggled #mainNav.fixed-top .sidenav-toggler .nav-link {
    width: 55px !important;
}

body.sidenav-toggled #mainNav.fixed-top #sidenavToggler i {
    -webkit-transform: scaleX(-1);
    -moz-transform: scaleX(-1);
    -o-transform: scaleX(-1);
    transform: scaleX(-1);
    filter: FlipH;
    -ms-filter: 'FlipH';
}

#mainNav.static-top .sidenav-toggler {
    display: none;
}

@media (min-width: 992px) {
    #mainNav.static-top .sidenav-toggler {
        display: flex;
    }
}

body.sidenav-toggled #mainNav.static-top #sidenavToggler i {
    -webkit-transform: scaleX(-1);
    -moz-transform: scaleX(-1);
    -o-transform: scaleX(-1);
    transform: scaleX(-1);
    filter: FlipH;
    -ms-filter: 'FlipH';
}

.content-wrapper {
    overflow-x: hidden;
    background: #f7f7f9;
}

@media (min-width: 992px) {
    .content-wrapper {
        margin-left: 150px;
    }
}

#sidenavToggler i {
    font-weight: 800;
}

.navbar-sidenav-tooltip.show {
    display: none;
}

@media (min-width: 992px) {
    body.sidenav-toggled .content-wrapper {
        margin-left: 55px;
    }
}

body.sidenav-toggled .navbar-sidenav {
    width: 55px;
}

body.sidenav-toggled .navbar-sidenav .nav-link-text {
    display: none;
}

body.sidenav-toggled .navbar-sidenav .nav-item,
body.sidenav-toggled .navbar-sidenav .nav-link {
    width: 55px !important;
}

body.sidenav-toggled .navbar-sidenav .nav-item:after,
body.sidenav-toggled .navbar-sidenav .nav-link:after {
    display: none;
}

body.sidenav-toggled .navbar-sidenav .nav-item {
    white-space: nowrap;
}

body.sidenav-toggled .navbar-sidenav-tooltip.show {
    display: flex;
}

#mainNav.navbar-dark .navbar-collapse .navbar-sidenav .nav-link-collapse:after {
    color: white;
    padding: 0 10px;
}

#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item>.nav-link {
    color: #9fa6b0;
    font-size: 0.8rem;
    font-weight: 100;
}

#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item>.nav-link:hover {
    color: white;
;
}

#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a,
#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a {
    color: white;
}

#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a:focus,
#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a:hover,
#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a:focus,
#mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a:hover {
    color: white;
}

#mainNav.navbar-dark .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link:after {
    color: white;
}

#main{
    background: var(--bg-color-box);
}
.navbar-dark .navbar-brand {
    color: #313942!important;
}

@media (min-width: 992px) {
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav {
        background: #313942;
        background: -moz-linear-gradient(270deg, #161b1f 0%, rgba(25, 29, 33, 1) 100%);
        /* ff3.6+ */
        background: -webkit-gradient(linear, left top, left bottom, color-stop(0%, #161b1f), color-stop(100%, rgba(25, 29, 33, 1)));
        /* safari4+,chrome */
        background: -webkit-linear-gradient(270deg, #161b1f 0%, rgba(25, 29, 33, 1) 100%);
        /* safari5.1+,chrome10+ */
        background: -o-linear-gradient(270deg, #161b1f 0%, rgba(25, 29, 33, 1) 100%);
        /* opera 11.10+ */
        background: -ms-linear-gradient(270deg, #161b1f 0%, rgba(25, 29, 33, 1) 100%);
        /* ie10+ */
            background: linear-gradient(180deg, #161b1f 0%, rgb(32, 38, 43) 100%);
        filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#313942', endColorstr='#191D21', GradientType=0);
        /* ie6-9 */
    }
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav li.active a {
        color: white !important;
        /* // background-color: #313942 */
    }
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav li.active a:focus,
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav li.active a:hover {
        color: white;
    }
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level,
    #mainNav.navbar-dark .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level {
        background: #313942;
    }
}

#mainNav.navbar-light .navbar-collapse .navbar-sidenav .nav-link-collapse:after {
    color: rgba(0, 0, 0, 0.5);
}

#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item>.nav-link {
    color: rgba(0, 0, 0, 0.5);
}

#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item>.nav-link:hover {
    color: rgba(0, 0, 0, 0.7);
}

#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a,
#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a {
    color: rgba(0, 0, 0, 0.5);
}

#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a:focus,
#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level>li>a:hover,
#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a:focus,
#mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level>li>a:hover {
    color: rgba(0, 0, 0, 0.7);
}

#mainNav.navbar-light .navbar-collapse .navbar-nav>.nav-item.dropdown>.nav-link:after {
    color: rgba(0, 0, 0, 0.5);
}

@media (min-width: 992px) {
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav {
        background: #f8f9fa;
    }
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav li.active a {
        color: #000 !important;
        background-color: #f7f7f9;
    }
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav li.active a:focus,
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav li.active a:hover {
        color: #000;
    }
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-second-level,
    #mainNav.navbar-light .navbar-collapse .navbar-sidenav>.nav-item .sidenav-third-level {
        background: #f8f9fa;
    }
}

.card-body-icon {
    position: absolute;
    z-index: 0;
    top: -25px;
    right: -25px;
    font-size: 5rem;
    -webkit-transform: rotate(15deg);
    -ms-transform: rotate(15deg);
    transform: rotate(15deg);
}

@media (min-width : 576px) {
    .card-columns {
        column-count: 1;
    }
}

@media (min-width: 768px) {
    .card-columns {
        column-count: 2;
    }
}

@media (min-width: 1200px) {
    .card-columns {
        column-count: 2;
    }
}

.card-login {
    max-width: 25rem;
}

.card-register {
    max-width: 40rem;
}

footer.sticky-footer {
    position: absolute;
    right: 0;
    bottom: 0;
    width: 100%;
    height: 56px;
    background-color: #f7f7f9;
    line-height: 55px;
}

@media (min-width: 992px) {
    footer.sticky-footer {
        width: calc(100% - 150px);
    }
}

@media (min-width: 992px) {
    body.sidenav-toggled footer.sticky-footer {
        width: calc(100% - 55px);
    }
}

.title-new {
    display: none;
}

.title-old {
    display: block;
}

.box-new-4 {
    width: 20%!important;
    flex: 0 0 20%!important;
}

.box-new-4-2 {
    width: 20%!important;
    flex: 0 0 20%!important;
    margin-top: 30px;
}

@media (max-width: 900px) {
    .title-new {
        display: block;
        width: 100%!important;
        max-width: none!important;
    }
    .title-new h2 {
        display: block;
        width: 100%!important;
        max-width: none!important;
        text-align: center!important;
    }
    .title-old {
        display: none;
        max-width: none!important;
    }
    .box-new-4 {
        width: 33.3333%!important;
        flex: 0 0 33.3333%!important;
        max-width: none!important;
        margin-top: 30px;
    }
    .box-new-4-2 {
        width: 33.3333%!important;
        flex: 0 0 33.3333%!important;
        max-width: none!important;
        margin-top: 30px;
    }
}

@media (max-width: 995px) {
    .lang-link {
        width: 33.333%!important;
        display: block;
        float: right;
        text-align: center;
    }
}

@media (max-width: 555px) {
    .title-new {
        display: block;
        width: 100%!important;
        max-width: none!important;
    }
    .title-new h2 {
        display: block;
        width: 100%!important;
        max-width: none!important;
        text-align: center!important;
    }
    .title-old {
        display: none;
        max-width: none!important;
    }
    .box-new-4 {
        width: 50%!important;
        flex: 0 0 50%!important;
        max-width: none!important;
        margin-top: 30px;
    }
    .box-new-4-2 {
        width: 50%!important;
        flex: 0 0 50%!important;
        max-width: none!important;
        margin-top: 30px;
    }
}

@media (max-width: 460px) {
    .title-new {
        display: block;
        width: 100%!important;
        max-width: none!important;
    }
    .title-new h2 {
        display: block;
        width: 100%!important;
        max-width: none!important;
        text-align: center!important;
    }
    .title-old {
        display: none;
        max-width: none!important;
    }
    .box-new-4 {
        width: 100%!important;
        flex: 0 0 100%!important;
        max-width: none!important;
        margin-top: 30px;
    }
    .box-new-4-2 {
        width: 100%!important;
        flex: 0 0 100%!important;
        max-width: none!important;
        margin-top: 30px;
    }
}

.bg-dark {
    background: #ffffff!important;
    padding: 0;
}

.spinner input {
    padding: 0;
    font-size: 0.8rem;
    height: 30px;
    border-radius: 0;
    margin: -3px 10px;
    background: var(--bg-color);
    color: var(--font-color-title);
}

#tempchange1:hover,
#tempchange2:hover {
    color: #2196F3;
    cursor: pointer;
}

.input-group-btn-vertical {
    position: relative;
    white-space: nowrap;
    width: 30px;
    vertical-align: middle;
    display: table-cell;
}

.input-group-btn-vertical>.btn {
    display: block;
    float: none;
    width: 100%;
    max-width: 100%;
    padding: 8px;
    margin-left: -1px;
    position: relative;
    border-radius: 0;
}

.input-group-btn-vertical>.btn:first-child {
    border-top-right-radius: 4px;
}

.input-group-btn-vertical>.btn:last-child {
    margin-top: -2px;
    border-bottom-right-radius: 4px;
}

.input-group-btn-vertical i {
    position: absolute;
    top: 0;
    left: 4px;
}

.button06 {
    background-color: rgb(3, 191, 68);
    box-shadow: 0 5px 20px rgba(17, 233, 91, 0.2);
}

.button01 {
    background-color: rgb(230, 44, 44);
    box-shadow: 0 5px 20px rgba(224, 29, 29, 0.15);
}

.to-home-link {
    position: fixed;
    background: #4d5a6e;
    border: 0;
    color: white;
    position: fixed;
    z-index: 1;
    right: 0;
    font-size: 27px;
    padding: 0;
    bottom: 0px;
    height: 70px;
    margin: 10px;
    width: 70px;
    border-radius: 50px;
}

.fa {
    display: inline-block;
    font: normal normal normal 14px/1 FontAwesome;
    font-size: inherit;
    text-rendering: auto;
    -webkit-font-smoothing: antialiased;
    width: 16px;
    -moz-osx-font-smoothing: grayscale;
    text-align: center;
}

.nav-link-text {
    padding-left: 5px;
}

.button-non {
    display: inline-block!important;
    padding: 0.8em 1.5em!important;
    border-radius: 1.6em!important;
    color: #fff!important;
    font-size: 11px!important;
    font-family: 'Roboto', sans-serif!important;
    font-weight: 500!important;
    text-align: center!important;
    text-decoration: none!important;
    border: 0!important;
    font-style: normal!important;
}

#mainNav .navbar-collapse .navbar-nav .nav-item .nav-link:hover {
    background: #f7f7f9;
}

.modal-dialog {
    max-width: 500px!important;
    margin: 20% auto!important;
}

#table_error,
.table_error {
    width: 100%!important;
    height: 200px!important;
    overflow: auto!important;
}

.search {
    width: 40px;
    height: 40px;
    background-color: white;
    position: relative;
    overflow: hidden;
    transition: all 0.5s ease;
}

.search:before {
    content: '';
    display: block;
    width: 3px;
    height: 100%;
    position: relative;
    background-color: #007bff;
    transition: all 0.5s ease;
}

.search.open {
    width: 420px;
}

.search.open:before {
    height: 60px;
    position: absolute;
}

.search-box {
    width: 100%;
    height: 100%;
    box-shadow: none;
    border: none;
    background: transparent;
    color: #323a43;
    padding: 20px 100px 20px 45px;
    font-size: 0.8rem;
}

.search-box:focus {
    outline: none;
}

.search-button {
    width: 40px;
    height: 40px;
    position: absolute;
    right: 0;
    top: 0;
    padding: 5px;
    cursor: pointer;
}

.search-icon {
    width: 15px;
    height: 15px;
    border-radius: 40px;
    border: 3px solid #007bff;
    display: block;
    position: relative;
    margin-left: 7px;
    margin-top: 5px;
    transition: all 0.5s ease;
}

.search-icon:before {
    content: '';
    width: 3px;
    height: 5px;
    position: absolute;
    right: -4px;
    top: 9px;
    display: block;
    background-color: #007bff;
    transform: rotate(-45deg);
    transition: all 0.5s ease;
}

.search-icon:after {
    content: '';
    width: 3px;
    height: 5px;
    position: absolute;
    right: -7px;
    top: 12px;
    display: block;
    background-color: #007bff;
    transform: rotate(-45deg);
    transition: all 0.5s ease;
}

.open .search-icon {
    margin: 0;
    width: 30px;
    height: 30px;
    border-radius: 60px;
}

.open .search-icon:before {
    transform: rotate(52deg);
    right: 10px;
    top: 9px;
    height: 12px;
}

.open .search-icon:after {
    transform: rotate(-230deg);
    right: 10px;
    top: 3px;
    height: 12px;
}

.active-link {
    padding-left: calc(1.5em - 5px);
    color: white;
}

.active-li {
    border-left: 5px solid #007aff;
    background: transparent;
    /* color: #303841; */
    padding-left: 17px!important;
    color: #ffffff!important;
    font-weight: 500;
}

.grid__item {
    position: relative;
    display: grid;
    grid-template-columns: 100%;
    grid-template-rows: 100%;
    align-items: center;
    justify-items: center;
    overflow: hidden;
    padding: 1rem 1.5rem;
}

.grid__item-title {
    font-size: 0.85rem;
    color: var(--color-item-title);
    align-self: flex-start;
    margin: 0;
}

.action {
    position: absolute;
    top: 0;
    right: 0;
    background: none;
    margin: 2rem;
    color: var(--color-action);
    border: 0;
    padding: 0;
    opacity: 0;
    pointer-events: none;
}

.action:focus {
    outline: none;
}

.particles {
    position: relative;
    grid-area: 1 / 1 / 2 / 2;
}

.particles-canvas {
    position: absolute;
    pointer-events: none;
    top: 50%;
    left: 50%;
    transform: translate3d(-50%, -50%, 0);
}

.particles-wrapper {
    position: relative;
    display: inline-block;
    overflow: hidden;
}

.particles-button {
    -webkit-touch-callout: none;
    -webkit-user-select: none;
    -khtml-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
    user-select: none;
    position: relative;
    border-radius: 5px;
    border-radius: var(--radius-button);
    background: var(--color-button-bg);
    color: var(--color-button-text);
    border: 0;
    border: var(--border-button);
    margin: 0;
    padding: 1.5rem 3rem;
    padding: var(--button-padding);
}

.particles-button:focus {
    outline: none;
}

.no-js .particles-button {
    grid-area: 1 / 1 / 2 / 2;
}

.theme-1 {
    --color-item-bg: linear-gradient(120deg, #a8edea 0%, #fed6e3 100%);
    --color-action: #0745ff;
    --color-button-bg: #0543ff;
    --color-button-text: #fff;
    --button-padding: .7rem 4rem;
    --radius-button: 50px;
    --border-button: 0;
}

.navbar-dark .navbar-nav .signout {
    color: rgb(77, 91, 110)!important;
}

.logo {
    padding: 17px;
    font-size: 17px;
    text-align: center;
}

.ml-auto li .row {
    background: white
}
.description {
    padding: 0px 0px;
    font-size: 13px;
    font-weight: 100;
}
.nav-item .signout {
    color: #222;
    height: 40px;
    line-height: 25px;
    background: #fff;
}

#sensor1changeHum .spinner input,
#sensor1changeTemp .spinner input{
    padding: 0;
    font-size: 0.8rem;
    height: 30px;
    border-radius: 0;
    margin: -3px 10px;
}

.device-menu {
    padding: 0 30px;
    float: left;
    width: 1000px;
    position: absolute;
    left: 120px;
}

.log-out-butt {
    padding: 12px!important;
    height: 45px!important;
}



.device-1 {
    width: 63px;
    height: 59px;
    top: 289px;
    left: 496px;
}

.device-1-sub-1 {
    width: 30px;
    height: 60px;
    top: 430px;
    left: 483px;
}

.device-2 {
    width: 170px;
    height: 167px;
    top: 472px;
    left: 572px;
}

.device-3 {
    width: 476px;
    height: 152px;
    top: 223px;
    left: 720px;
}

.plan-details {
    background: #f7f7f9;
    position: absolute;
    top: calc(50% - 51px);
    left: -200px;
    width: 120px;
    padding: 10px;
    background: #fff;
    border-radius: 5px;
    padding: 10px;
    box-shadow: 0 1.5px 10px #d8d8d8;
}

.description-time {
    background: #313942;
    color: white!important;
    font-weight: 100!important;
}

.plan-details b {
    text-align: center!important;
    width: 100%;
    display: block;
    color: #313942;
;
    font-size: 18px; //font-weight: 600;
}

.plan-details p {
    text-align: center!important;
    width: 100%;
    display: block;
    color: #313942;
    font-size: 0.8rem;
    font-weight: 600;
    padding: 0;
}

#selectdevice {
    float: right;
    border: none;
    outline: 0 !important;
}

.svg-icon {
    width: 1em;
    height: 1em;
}

.svg-icon path,
.svg-icon polygon,
.svg-icon rect {
    fill: #0974ed;
}

.svg-icon circle {
    stroke: #0974ed;
    stroke-width: 1;
}

.boxadmin svg {
    width: 20px;
    height: 100%;
    margin: 20px 0px;
}

.title-box .fas,
.data-table .fas {
    font-size: 14px!important;
    color: #617082!important;
    padding: 0!important;
    margin: 0!important;
}
hr {
    border-top: 1px solid #414b57;
    margin: 5px 0;
}
.deviceses .fas,
#cash .fas,
#users .fas {
    width: 20px;
    height: 100%;
    margin: 20px 0px;
    font-size: 30px;
    text-align: center;
    color: #617082;
}

.selection-box-info {
    width: calc(100% - 20px)!important;
    float: right!important;
}


/*
 * The Card
 *
 * ==================== */

.cc,
.cc-back {
    background-color: #313942;
    border-radius: 10px;
    display: block;
    height: 195px;
    letter-spacing: .1rem;
    margin: 15px;
    position: relative;
    text-align: left;
    text-transform: uppercase;
    width: 325px;
    background: -moz-linear-gradient(270deg, rgba(49, 57, 66, 1) 0%, rgba(25, 29, 33, 1) 100%);
    /* ff3.6+ */
    background: -webkit-gradient(linear, left top, left bottom, color-stop(0%, rgba(49, 57, 66, 1)), color-stop(100%, rgba(25, 29, 33, 1)));
    /* safari4+,chrome */
    background: -webkit-linear-gradient(270deg, rgba(49, 57, 66, 1) 0%, rgba(25, 29, 33, 1) 100%);
    /* safari5.1+,chrome10+ */
    background: -o-linear-gradient(270deg, rgba(49, 57, 66, 1) 0%, rgba(25, 29, 33, 1) 100%);
    /* opera 11.10+ */
    background: -ms-linear-gradient(270deg, rgba(49, 57, 66, 1) 0%, rgba(25, 29, 33, 1) 100%);
    /* ie10+ */
    background: linear-gradient(180deg, rgba(49, 57, 66, 1) 0%, rgb(37, 43, 49) 100%);
    filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#313942', endColorstr='#191D21', GradientType=0);
    /* ie6-9 */
}

.chip {
    background: #efb77f;
    border-radius: 5px;
    display: block;
    height: 30px;
    left: 30px;
    position: absolute;
    top: 50px;
    width: 40px;
}

.nubank-logo {
    background-image: url("https://www.nubank.com.br/images/eeb5478f.header_logo.png");
    background-position: 50% 50%;
    background-repeat: no-repeat;
    background-size: 80px;
    display: block;
    -webkit-filter: grayscale(100%);
    filter: grayscale(100%);
}

.nubank-logo:after {
    background: linear-gradient(#eee, #c0c0c0);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    content: 'Platinum';
    display: block;
    text-align: center;
    padding-top: 60px;
}

.cc-number {
    background: linear-gradient(#eee, #c0c0c0);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    bottom: 75px;
    font-size: 20px;
    left: 30px;
    position: absolute;
}

.cc-date {
    background: linear-gradient(#eee, #c0c0c0);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    bottom: 40px;
    left: 30px;
    position: absolute;
}

.cc-date.expiry {
    left: 125px;
}

.dollar {
    font-size: 150px;
    left: 70px;
    position: absolute;
    color: #1a1e21;
}

.cc-date.expiry:after {
    -webkit-text-fill-color: #52185b;
    content: 'Valid thru';
    font-size: 8px;
    left: -30px;
    position: absolute;
    text-transform: none;
    top: -10px;
}

.cc-name {
    background: linear-gradient(#eee, #c0c0c0);
    -webkit-background-clip: text;
    -webkit-text-fill-color: transparent;
    bottom: 15px;
    left: 30px;
    position: absolute;
}


/*
 * Card back
 */

.cc-magnet {
    background: linear-gradient(#eee, #c0c0c0);
    display: block;
    height: 30px;
    position: absolute;
    top: 15%;
    width: 100%;
}


/*
 * MasterCard logo in pure CSS in just ONE element
 * by Jaime Caballero (jaicab.com)
 */

.mastercard {
    font-family: "Droid Sans", Helvetica, sans-serif;
    position: absolute;
    width: 5rem;
    font-size: 0.8rem;
    line-height: 3rem;
    letter-spacing: -0.0666666667rem;
    text-align: center;
    font-weight: bold;
    font-style: italic;
    color: white;
    text-shadow: -0.04rem 0.04rem 0 #16226a;
    text-transform: none;
    top: 15px;
    right: 30px;
    /* margin: 2vh auto; */
    z-index: 2;
}

.mastercard::before {
    content: '';
    position: absolute;
    top: 0;
    right: 0;
    bottom: 0;
    left: 0;
    display: inline-block;
    border-radius: 50%;
    width: 3rem;
    height: 3rem;
    z-index: -1;
    background: linear-gradient(#fe9900 50%, #cd0001 50%);
    background-size: 0.375rem 0.375rem;
    box-shadow: 2rem 0 0 0 #fe9900, 2rem 0 0 0 #cd0001 inset;
}

.mastercard::after {
    content: '\00ae';
    padding-left: .5em;
    font: .25em Helvetica, sans-serif lighter normal;
    text-shadow: none;
}

.cirrus {
    font-family: "Droid Sans", Helvetica, sans-serif;
    position: absolute;
    width: 4em;
    font-size: 0.8rem;
    line-height: 2rem;
    letter-spacing: -0.0666666667rem;
    text-align: center;
    font-weight: bold;
    font-style: italic;
    color: white;
    text-shadow: -0.04rem 0.04rem 0 #16226a;
    text-transform: none;
    top: -20px;
    left: 15px;
    margin: 20vh auto;
    z-index: 2;
}

.cirrus::before {
    content: '';
    position: absolute;
    top: 0;
    right: 0;
    bottom: 0;
    left: 0;
    display: inline-block;
    border-radius: 50%;
    width: 2rem;
    height: 2rem;
    z-index: -1;
    background: linear-gradient(#0085c6 50%, #345399 50%);
    background-size: 0.375rem 0.375rem;
    box-shadow: 1.3333333333rem 0 0 0 #0085c6, 1.3333333333rem 0 0 0 #345399 inset;
}

.cirrus::after {
    content: '\00ae';
    font: .25em Helvetica, sans-serif lighter normal;
    padding-left: .5em;
    text-shadow: none;
}

#chartcolumn {
    position: relative;
    height: 300px;
    font-size: 0.8rem;
    font-family: Roboto;
}

#chartlogic {
    position: relative;
    height: 300px;
    font-size: 0.8rem;
    font-family: Roboto;
}

#chartdivindex {
  width: 100%;
  height: 500px;
}




/*Simple css to style it like a toggle switch*/
.theme-switch-wrapper {
    text-decoration: none;
    display: inline-block;
    padding: 0px 8px;
    text-decoration: none;
    display: inline-block;
    color: white;
    vertical-align: middle;
}
.theme-switch {
display: inline-block;
    height: 16px;
    position: relative;
    width: 30px;
}

.theme-switch input {
  display:none;
}

.slider {
  bottom: 0;
  cursor: pointer;
  left: 0;
  position: absolute;
  right: 0;
  top: 0;
  transition: .4s;
  background: linear-gradient(90deg, #ff7f24, #ff3c60);
}

.slider:before {
    background-color: #fff;
    bottom: 0px;
    content: "";
    height: 16px;
    left: 0px;
    position: absolute;
    transition: .4s;
    width: 16px;

}

input:checked + .slider {
  background: linear-gradient(90deg, #78da50, #30ce26);
}

input:checked + .slider:before {
    transform: translateX(16px);
}

.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;
}






///////////////////////////////// PLAN



.plan {
    width: 1500px;
    height: 600px;
    background: url(../img/plan2.png) top left;
    background-size: 90%;
    background-repeat: no-repeat;
    background-position: center;
    padding: 20px;
    margin: 15px;
    float: left;
}

.device {
    display: block;
    position: absolute;
    color: #222;
    font-weight: 900;
}

.plan-description b {
    width: 14px;
    height: 14px;
    display: block;
    float: left;
    margin: 1px 3px 0px 0px;
}

.plan-description .blue b {
    background: #01fb2080;
}

.plan-description .red b {
    background: rgba(251, 1, 1, 0.5);
}

.plan-description .gray b {
    background: rgba(73, 80, 87, 0.62);
}

.room:hover .device {
    background-color: #007bffab;
    transition: 0.5s;
}


/* .room:hover .plan-details { transition: 0.5s; transform: scale(1.1); } */


/* PARALAX */



.item{
  width: 200px;
  height: 200px;
  color: white;
  display: flex;
  justify-content: center;
  align-items: center;
    transform: translate3d(0,0,0);
-moz-transform: translate3d(0,0,0);
-webkit-transform: translate3d(0,0,0);
}
.item1{
  background: lightBlue; 
}
.item2{
  background: lightGreen;
}
.item3{
  background: lightPink;
}
</style>
<head>
  <meta charset="utf-8">
  <title>SMART ARMS (IoT) Manufacturing Solution</title>
  <!-- Meta Section -->
  <meta content="width=device-width, initial-scale=1.0" name="viewport">
  <meta name="robots" content="index, follow" />
  <meta name="smartarms, SMART ARMS, smart, arms, даталоггер, datalogger, моніторинг, хассп, процесу, промисловість, IoT" content="" >
  <meta name="description" content="Automatic Room Monitoring System Моніторинг контрольних критичних точок технологічного процесу на промисловому виробництві" >
  <meta name="theme-color" content="#222222"/>
  <meta name="author" content="Ihor Berezhnyi">
  <!-- Favicons -->
  <link href="img/favicon.png" rel="icon">
  <!-- Main Stylesheet File -->
  <link href="https://fonts.googleapis.com/css?family=Roboto:300,400,700,900&display=swap&subset=cyrillic" rel="stylesheet">
  <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.9.0/css/all.min.css" rel='stylesheet'/>
  <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel='stylesheet'/>
  <link href="https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.7.2/animate.min.css" rel='stylesheet'/>
  <link href='css/style.css' rel='stylesheet'/>
  <!-- Global site tag (gtag.js) - Adwords -->
  <script async rel="preconnect" src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
  <!-- Global site tag (gtag.js) - Google Analytics -->
  <script async rel="preconnect" src="https://www.googletagmanager.com/gtag/js?id=UA-155100378-1"></script>
  <script data-ad-client="ca-pub-9600604976724684" async rel="preconnect" src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
  <!-- Global site tag (gtag.js) - Google Analytics -->
  <script>
    window.dataLayer = window.dataLayer || [];
    function gtag(){dataLayer.push(arguments);}
    gtag('js', new Date());

    gtag('config', 'UA-112919742-1');
  </script>
</head>
<body>
  <!--==========================
        Header Us Section
  ============================-->
  <header id="header">
    <div class="container">
      <div id="logo" class="pull-left">
        <h2><a href="#arms"><img class="logo-top" src="img/svg/image2vector.svg" alt="Logo Smart Arms"></img>SMART ARMS</a></h2>
      </div>
      <nav id="nav-menu-container">
        <ul class="nav-menu">
          <li class="menu-active"><a href="./#hero"><b>Головна</b></a></li>
          <li><a href="./#about"><b>Про нас</b></a></li>
          <li><a href="./#about2"><b>Сервіси</b></a></li>
          <li><a href="/IoT.html"><b>IoT</b></a></li>
          <li><a href="./#contact"><b>Контакти</b></a></li>
            <a class="hide-sm padding-20">
            <li><a href="index.ua.php" class="lang-active lang-link"><b>UA</b></a></li>
            <li><a href="index.rus.php" class="lang-link"><b>RUS</b></a></li>
            <li><a href="index.en.php" class="lang-link"><b>EN</b></a></li>
            <li>
              <a style="padding: 5px 0px;">
                <div class="theme-switch-wrapper">
                  <label class="theme-switch" for="checkbox">
                    <input type="checkbox" id="checkbox" />
                    <div class="slider round"></div>
                  </label>
                </div>
                Dark Mode
              </a>
            </li>
            <li><a href="login" class="padding-20">&nbsp;<i class="fas fa-sign-in-alt"></i> Вхід</a></li>
          </a>
        </ul>
      </nav>
    </div>
  </header>
  <!--==========================
        About Us Section
  ============================-->
  <main id="main">
      <!--==========================
            Contact Section
      ============================-->
      <section class="row col-md-12" id="services2">
        <div id="first-device" class="row">
          <div class="col-md-12 section-header">
            <h3 class="section-title">ДЕТАЛЬНА ІНФОРМАЦІЯ З ПРИСТРОЮ.</h3>
          </div>
          <div class="col-md-12">
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ТЕМПЕРАТУРА: <em id="tempstatus" class="pull-right animate pulse infinite" style="float: right;"></em></p>
                <div id="temperatureRadial" style="height: 187px;width: 100%;position: relative;padding: 0 15px;"></div>
                <p class="section-description"></br> Mежі від <b id="temp_down">25</b> до <b id="temp_up"> 35</b>
                  <i class="fas fa-wind pull-right" style="font-size: 25px;color: #d2d2d2;padding: 0 5px;float: right;margin: -3px 0;"></i>
                  <i class="far fa-snowflake pull-right" style="font-size: 25px;color: #467fe7;padding: 0 5px;float: right;margin: -3px 0;"></i>
                </p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ВОЛОГІСТЬ: <em id="humstatus" class="pull-right" style="float: right;"></em></br></p>
                <div id="humidityRadial" style="height: 187px;width: 100%;position: relative;padding: 0 15px;"></div>
                <p class="section-description"></br> Mежі від <b id="hum_down">80</b> до <b id="hum_up">100</b>
                  <i class="fas fa-wind pull-right" style="font-size: 25px;color: #467fe7;padding: 0 5px;float: right;margin: -3px 0;"></i>
                  <i class="far fa-snowflake pull-right" style="font-size: 25px;color: #d2d2d2;padding: 0 5px;float: right;margin: -3px 0;"></i>
                </p>
              </div>
            </div>
            <div class="boxadmin col-md-6">
              <div class="boxadmins col-md-12">
                <p class="section-description">ЕНЕРГОЗБЕРЕЖЕННЯ:</br></p>
                <div id="chartdivssss" style="height: 229px;width: 100%;position: relative;padding: 0 15px;"></div>
              </div>
            </div> 

            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ОСВІТЛЕННЯ: </br>
                  <b id="adc_value">321</b>
                  <b id="adc_value_out" class="blue-num"></b> lum
                  <p class="section-description">Споживання : <i class="fas fa-bolt" style="font-size: 15px;color: #d2d2d2;"></i> <b>0.15Kw</b></p>
                </p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">СТАН РЕЛЕ:</br>
                  <b class="blue-num"><i class="fas fa-power-off" style="color: #d2d2d2;"></i> OFF</b>
                  <p class="section-description">Термореле</p>
                </p>
                <p id="device1lustU"></p>
              </div>
            </div>

            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ЯКІСТЬ СИГНАЛУ: </br>
                <b class="number blue-num"><i class="fas fa-rss" style="color: #d2d2d2;"></i> -47.2</b> dBm;</p>
                <p class="section-description">Wi-Fi Роутер</p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ТИСК: </br>
                <b class="number blue-num"><i class="fas fa-tachometer-alt" style="color: #d2d2d2;"></i> 977.76</b> hPa;
                <p class="section-description">В приміщенні</p>
              </div>
            </div>

            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description ">ПРИСТРІЙ : ID : 0006451</br></p>
                </br>
                <p class="section-description"><i class="fas fa-ethernet" style="width:18px;text-align: center;"></i>  IP  : 192.0.0.1</p>
                <p class="section-description"><i class="fas fa-network-wired" style="width:18px"></i> MAC : 48-2C-6A-1E-59-3D</p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ТЕМПЕРАТУРА:</br>
                  <b class="number blue-num"><i class="fas fa-thermometer-half" style="color: #d2d2d2;"></i> 35.76</b> &#8451; <i id="sensor1tempdiff1" class="diff-div"> </i>
                  </br> Mежі від <b id="temp_downs">25</b> до <b id="temp_ups"> 35</b>
                </p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ВИСОТА: </br>
                <b class="number blue-num"><i class="fas fa-arrows-alt-v" style="color: #d2d2d2;"></i> 299.76</b> m;
                <p class="section-description">Wi-Fi Роутер</p>
              </div>
            </div>
            <div class="boxadmin col-md-3">
              <div class="boxadmins col-md-12">
                <p class="section-description">ОСТАННЄ ОНОВЛЕННЯ: </br>
                <b class="number blue-num "><i class="far fa-clock" style="color: #d2d2d2;"></i> 13:06:22</b></p>
                <p class="section-description">2019-12-02</p>
              </div>
            </div>
          </div>

          <div class="col-md-12">
            <div class="box-box">
              <div class="boxadmin col-md-4 data-table">
                <div class="boxadmins col-md-12">
                  <div class="row col-md-12 title-box">
                    <h7 class="col-md-9">ТАБЛИЦЯ ДАНИХ</h7>
                  </div>
                  <div class="col-sm-12 padding-zero">
                    <div class="row">
                      <div id="table1" style="height: 272px;overflow-y: auto;">
                        <table>
                          <thead>
                            <tr>
                              <td><b>Дата</b></td>
                              <td><b>Час</b></td>
                              <td><b>Темп.</b></td>
                              <td><b>Вол.</b></td>
                              <td><b>Осв.</b></td>
                            </tr>
                          </thead>
                          <tbody>
                            <tr>
                              <td>2019-12-02</td>
                              <td>13:06:22</td>
                              <td>35.76 °</td>
                              <td>100 %</td>
                              <td>463</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>13:03:52</td>
                              <td>36.39 °</td>
                              <td>100 %</td>
                              <td>454</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:43:51</td>
                              <td>34.44 °</td>
                              <td>100 %</td>
                              <td>460</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:41:21</td>
                              <td>34.03 °</td>
                              <td>100 %</td>
                              <td>451</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:26:21</td>
                              <td>33.42 °</td>
                              <td>100 %</td>
                              <td>457</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:21:21</td>
                              <td>33.49 °</td>
                              <td>100 %</td>
                              <td>468</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:13:51</td>
                              <td>34.22 °</td>
                              <td>100 %</td>
                              <td>454</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:03:50</td>
                              <td>33.05 °</td>
                              <td>100 %</td>
                              <td>456</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>12:01:20</td>
                              <td>33.07 °</td>
                              <td>100 %</td>
                              <td>470</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:58:50</td>
                              <td>33.32 °</td>
                              <td>100 %</td>
                              <td>472</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:48:50</td>
                              <td>33.52 °</td>
                              <td>100 %</td>
                              <td>465</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:43:50</td>
                              <td>32.59 °</td>
                              <td>100 %</td>
                              <td>475</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:41:20</td>
                              <td>32.14 °</td>
                              <td>100 %</td>
                              <td>470</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:36:20</td>
                              <td>31.99 °</td>
                              <td>100 %</td>
                              <td>464</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:33:50</td>
                              <td>32.17 °</td>
                              <td>100 %</td>
                              <td>459</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:26:20</td>
                              <td>34.89 °</td>
                              <td>100 %</td>
                              <td>466</td>
                            </tr>
                            <tr>
                              <td>2019-12-02</td>
                              <td>11:21:20</td>
                              <td>35.94 °</td>
                              <td>100 %</td>
                              <td>451</td>
                            </tr>                    
                          </tbody>
                        </table>
                      </div>
                    </div>
                    <div class="row col-md-12"><a href="php/UserReport_Export.php"> Eкспорт таблиці в XLS 
                      <img src="img/svg/337958.svg" alt="lgos" style="margin: 0;width: 40px;"></a>
                    </div>
                    </br>
                    <p class="section-description"><i class="fas fa-history"></i> останнє оновлення:
                      <em id="device1lustUP"><?php echo $sensor1time, " ", $sensor1date;?></em>
                    </p>
                  </div>
                </div>
              </div>
            </div>
            <div class="box-box">
              <div class="boxadmin col-md-8">
                <div class="boxadmins col-md-12">
                  <div class="row col-md-12 title-box">
                    <h7 class="col-md-8"><i class="fas fa-thermometer-half" style="color: #a9a9a9;"></i> ГРАФІК ТЕМПЕРАТУР</h7> 
                    <em class="pull-right col-md-4"><i class="fas fa-paperclip"></i> Кількість записів: <?php echo $sensor1sum; ?></em>
                  </div>
                  <div id="chartdiv"></div>
                  </br>
                  <em class="section-description " style='color: #6f8295;'>
                  <i class='fa fa-warning' aria-hidden='true' style='color: #dc3545;'></i> Виявлено порушень в температурі: 21
                  </em>
                  <button type="button" class="button-non button13" data-toggle="modal" data-target="#myModal">Детальніше</button>
                </div>
              </div>
              <div class="box-box">
                <div class="boxadmin col-md-4">
                  <div class="boxadmins">
                    <div class="row col-md-12 title-box">
                      <h7 class="col-md-9">ЗМІНА МЕЖ ВИМІРЮВАНЬ</h7>
                    </div>
                    <div class="col-sm-12">
                  <div class="row">
                    <form method="post" id="sensor1change" class="section-description">
                      <p>Межі вимірювання температури:</p>
                      </br>
                      <div class="input-group spinner">
                        Змінити межі від <input type="text" class="form-control" name="temp_down" value=" 20" style="    padding: 0;
                        font-size: 14px;
                        height: 30px;
                        border-radius: 0;
                        margin: -3px 10px;"> до <input type="text" class="form-control" name="temp_up" value=" 35" style="    padding: 0;
                        font-size: 14px;
                        height: 30px;
                      border-radius: 0;
                      margin: -3px 10px;">
                      </div>
                      </br>
                      <div class="pull-right">
                        <input class="button-non button01" id="cancle1" type="button" value="Відміна">
                        <input class="button-non button06" type="submit" name="edit" value="Змінити">
                      </div>
                    </form>
                  </div>
                </div>
              </div>
            </div>
            <div class="box-box">
              <div class="boxadmin col-md-8">
                <div class="boxadmins col-md-12">
                  <div class="row col-md-12 title-box">
                    <h7 class="col-md-8"><i class="fas fa-tint" style="color: #a9a9a9;"></i> ГРАФІК ВОЛОГОСТІ</h7> <em class="pull-right col-md-4"><i class="fas fa-paperclip"></i> Кількість записів: <?php echo $sensor1sum; ?></em>
                  </div>
                  <div id="chartdiv-second"></div>
                  </br>
                  <em class="section-description" style='color: #6f8295;'>
                    <?php if ($sensor1humerror > 0) { echo " <i class='fa fa-warning' aria-hidden='true' style='color: #dc3545;'></i>";?> Виявлено порушень в вологості:
                    <?php echo $sensor1humerror;  }?>
                  </em>
                  <button type="button" class="button-non button13" data-toggle="modal" data-target="#myModal">Детальніше</button>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>
      <!--==========================
            Contact Section
      ============================-->
      <section id="part">
        <div class="container ">
          <div class="row col-md-12">
            <div class="col-md-2 col-xs-4 part">
              <i class="fas fa-shield-alt"></i>
            </div>
            <div class="col-md-2 col-xs-4 part">
              <i class="fab fa-angular"></i>
            </div>
            <div class="col-md-2 col-xs-4 part">
              <i class="fas fa-wifi"></i>
            </div>
            <div class="col-md-2 col-xs-4 part">
              <i class="fab fa-vuejs"></i>
            </div>
            <div class="col-md-2 col-xs-4 part">
              <i class="fas fa-database"></i>
            </div>
            <div class="col-md-2 col-xs-4 part">
              <i class="fab fa-laravel"></i>
            </div>
          </div>
        </div>
      </section>
      <!--==========================
            Contact Section
      ============================-->
      <section id="contact">
          <div class="container ">
            <div class="section-header">
              <h3 class="section-title white">ЗВ'ЯЗОК З НАМИ.</h3>
              <h6 class="title col-lg-12 text-center white">Ми відповідаємо швидко та зрозуміло.</h6>
            </div>
          </div>
          <div class="container ">
            <div class="row justify-content-center" style="padding: 0 25%;">
              <?php include 'php/sendemail.php';?>
              <div class="col-lg-12 col-md-12">
                <div class="form">
                  <div id="errormessage"></div>
                  <form action="" method="post" role="form" class="contactForm">
                    <div class="form-group">
                      <input type="text" name="name" class="form-control" id="name" placeholder="Ваше ім'я:" data-rule="minlen:4" data-msg="Please enter at least 4 chars" />
                      <label for="name">Ваше ім'я</label>
                      <div class="validation"></div>
                    </div>
                    <div class="form-group">
                      <input type="email" class="form-control" name="email" id="email" placeholder="Електронна пошта:" data-rule="email" data-msg="Please enter a valid email" />
                      <label for="email">Електронна пошта</label>
                      <div class="validation"></div>
                    </div>
                    <div class="form-group">
                      <textarea class="form-control" name="message" rows="5" data-rule="required" data-msg="Please write something for us" placeholder="Повідомлення:"></textarea>
                      <label for="message">Електронна пошта</label>
                      <div class="validation"></div>
                    </div>
                    <div class="text-center">
                      <button type="submit" value="Submit" class="button13">Надіслати</button>
                    </div>
                  </form>
                </div>
              </div>
            </div>
          </div>
      </section>
    </main>
    
    <!--==========================
            ADS
    ============================-->
<!--     <div>
      <ins class="adsbygoogle"
           style="display:block"
           data-ad-client="ca-pub-9600604976724684"
           data-ad-slot="3353463409"
           data-ad-format="auto"
           data-full-width-responsive="true"></ins>
      <script>(adsbygoogle = window.adsbygoogle || []).push({});</script>
    </div> -->
    <!--==========================
            Footer Section
    ============================-->
    <footer id="footer">
      <div class="footer-top">
        <div class="container">
          <div class="row">
            <div class="col-lg-5 col-md-5 col-sm-12">
              <img src="img/svg/image2vector.svg" class="logo-topsub-icon" alt="icon" style="width: 60px; height:50px"></img>
              <a style="font-size:18px;letter-spacing: 3px;vertical-align:sub;">SMART ARMS</a></br></br>
              <p style="width:80%">Моніторинг контрольних критичних точок технологічного процесу на промисловому виробництві за допомогою Wi-Fi технологій.</p></br>
            </div>
            <div class="col-lg-4 col-md-4 col-sm-12">
              <b>ПІДПИШИСЬ</b></br></br>
              <a href="skype:berezhnyj?chat" title="skype"><i class="fab fa-skype sub-icon"></i></a>
              <a href="https://t.me/smartarms" title="telegram"><i class="fab fa-telegram-plane sub-icon"></i></a>
              <a href="https://mail.google.com/mail/u/0/#all" title="google"><i class="fab fa-google sub-icon"></i></a>
              <a href="https://www.linkedin.com/in/ihor-berezhnyi-55806a190/" title="linkedin"><i class="fab fa-linkedin-in sub-icon"></i></a>
              <a href="https://www.patreon.com/bePatron?u=28466424&redirect_uri=http%3A%2F%2Fsmartarms.in.ua%2F&utm_medium=widget" title="patreon"><i class="fab fa-patreon sub-icon"></i></a></br></br>
            </div>
            <div class="col-lg-3 col-md-3 col-sm-12">
              <b>КОНТАКТИ</b></br></br>
              <p><i class="far fa-envelope" style="font-size: 14px;"></i> officialarmsua@gmail.com</p></br>
              <p><i class="fas fa-phone" style="font-size: 14px;"></i> +380632342550</p></br></br>
            </div>
          </div>
        </div>
      </div>
      <div class="copyright">
        <div class="container">
          <div class="col-lg-12 col-md-6 col-sm-12" style="text-align: left;">
            &copy;2018-<script>document.write(new Date().getFullYear());</script> SMART ARMS. All Rights Reserved.
            </br>Disclaimer and Copyright Notice.
            </br>Information on this website, including URL references, is subject to change without notice.
          </div>
        </div>
      </div>
    </footer>

    <a href="#" class="back-to-top"><i class="fas fa-arrow-up"></i></a>
    <!-- JavaScript Libraries -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.4.1/js/bootstrap.bundle.min.js" crossorigin="anonymous"></script>
    <!-- <script src="vendor/easing/easing.min.js"></script> -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.4.1/jquery.easing.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/wow/1.1.2/wow.min.js"></script>
    <script src="js/lazysizes.min.js"></script>
    <script src="vendor/counterup/counterup.min.js"></script>
    <script src="vendor/superfish/hoverIntent.js"></script>
    <script src="vendor/superfish/superfish.min.js"></script>
    <script src="js/particles.js"></script>
    <!-- development version, includes helpful console warnings -->
    <script src="https://www.amcharts.com/lib/4/core.js"></script>
    <script src="https://www.amcharts.com/lib/4/charts.js"></script>
    <script src="https://www.amcharts.com/lib/4/themes/animated.js"></script>
    <script>
	/*
 * Main part of JavaScript
 */
jQuery(document).ready(function($) {
    /*
     * Script to show internet error connection (prevent to navigator)
     */
    setInterval(function(){
        if(navigator.onLine){
            $("#main").show();
            $("#hero a").show();
            $("#hero .items").show();
            $("#hero h1").html('SMART ARMS - Automatic Room Monitoring System<i class="glyphicon glyphicon-star-empty"></i>');
            $("#hero h2").html('Моніторинг контрольних критичних точок технологічного процесу</br> на промисловому виробництві за допомогою Wi-Fi технологій.');
        } else {
            $("#main").hide();
            $("#hero a").hide();
            $("#hero .items").hide();
            $("#hero h1").html('<i class="fas fa-exclamation-triangle"></i> NO INTERNET <i class="fas fa-exclamation-triangle"></i>');
            $("#hero h2").html('Бeдь ласка перевірте налаштування мережі!');
        }
    },1000);
    /* Show Script to show internet error connection (prevent to navigator) */
    window.addEventListener('offline', function(e) { console.log('offline'); });
    window.addEventListener('online',  function(e) { console.log('online');  });
    /*
     * Toggle theme function
     */
    const toggleSwitch = document.querySelector('.theme-switch input[type="checkbox"]');
    function switchTheme(e) {
        if (e.target.checked) {
            document.documentElement.setAttribute('data-theme', 'dark');
        } else {
            document.documentElement.setAttribute('data-theme', 'light');
        }    
    }
    toggleSwitch.addEventListener('change', switchTheme, false);
    function switchTheme(e) {
        if (e.target.checked) {
            document.documentElement.setAttribute('data-theme', 'dark');
            localStorage.setItem('theme', 'dark'); //add this
        } else {
            document.documentElement.setAttribute('data-theme', 'light');
            localStorage.setItem('theme', 'light'); //add this
        }    
    }

    const currentTheme = localStorage.getItem('theme') ? localStorage.getItem('theme') : null;

    if (currentTheme) {
        document.documentElement.setAttribute('data-theme', currentTheme);

        if (currentTheme === 'dark') {
            toggleSwitch.checked = true;
        }
    }
    /*
     * Initiate WOW script
     */
    wow = new WOW(
        {
        boxClass:     'wow',      // default
        animateClass: 'animated', // default
        offset:       0,          // default
        mobile:       true,       // default
        live:         true        // default
    });
    wow.init();
    /*
     * Initiate superfish on nav menu
     */
    $('.nav-menu').superfish({
        animation: { opacity: 'show' },
        speed: 400
    });

    $("head").append("<link rel='stylesheet' href='vendor/font-awesome/css/font-awesome.min.css'/>");

    var number      = parseFloat($('.number').text());
    var fahrenheit  = ((number * 1.8) + 32).toFixed(2);

    var date        = new Date();
    var month       = (date.getMonth() + 1);
    var day         = date.getDate();
    var year        = date.getFullYear();

    $("#date").html(day + '/' + month + '/' + year);

    var adc_value = parseFloat($('#adc_value').text());
    var voltage = 5.0 * (adc_value / 1024.0);
    var resistance = (10.0 * 5.0) / voltage - 10.0;
    var illuminance = (255.84 * (Math.pow(resistance, (-10 / 9)))).toFixed(3);

    $("#adc_value_out").html("<i class='far fa-lightbulb' style='color: #d2d2d2;'></i> " + illuminance);
    $('.fahrenheit').html("<p>Поточна температура: <b>" + fahrenheit + "</b> F<p>");

    var temp_up     = parseFloat($('#temp_up').text());
    var temp_down   = parseFloat($('#temp_down').text());

    if ((number < temp_up) && (number > temp_down)) {
        $("#tempstatus").html("статус : <i class='fas fa-exclamation-circle m-r-sm fa-circle text-success'></i>");
    } else {
        $("#tempstatus").html("статус : <i class='fas fa-exclamation-circle m-r-sm fa-circle text-danger animate pulse infinite'></i>");
    };
    // Статус вологості
    var hum         = parseFloat($('#hum').text());
    var hum_up      = parseFloat($('#hum_up').text());
    var hum_down    = parseFloat($('#hum_down').text());

    if ((hum < hum_up) && (hum > hum_down)) {
        $("#humstatus").html("статус : <i class='fas fa-exclamation-circle m-r-sm fa-circle text-success'></i>");
    } else {
        $("#humstatus").html("статус : <i class='fas fa-exclamation-circle m-r-sm fa-circle text-danger animate pulse infinite'></i>");
    };
    // Header fixed and Back to top button
    $(window).scroll(function() {
        if ($(this).scrollTop() > 100) {
            $('.back-to-top').fadeIn('slow');
            $('#header').addClass('header-fixed');
        } else {
            $('.back-to-top').fadeOut('slow');
            $('#header').removeClass('header-fixed');
        }
    });
    $('.back-to-top').click(function() {
        $('html, body').animate({ scrollTop: 0 }, 1500, 'easeInOutExpo');
        return false;
    });

    // Mobile Navigation
    if ($('#nav-menu-container').length) {
        var $mobile_nav = $('#nav-menu-container').clone().prop({ id: 'mobile-nav' });
        $mobile_nav.find('> ul').attr({ 'class': '', 'id': '' });
        $('body').append($mobile_nav);
        $('body').prepend('<button type="button" id="mobile-nav-toggle"><i class="fas fa-bars"></i></button>');
        $('body').append('<div id="mobile-body-overly"></div>');
        $('#mobile-nav').find('.menu-has-children').prepend('<i class="fas fa-arrow-circle-down"></i>');

        $(document).on('click', '.menu-has-children i', function(e) {
            $(this).next().toggleClass('menu-item-active');
            $(this).nextAll('ul').eq(0).slideToggle();
            $(this).toggleClass("fa-chevron-up fa-chevron-down");
        });

        $(document).on('click', '#mobile-nav-toggle', function(e) {
            $('body').toggleClass('mobile-nav-active');
            $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
            $('#mobile-body-overly').toggle();
        });

        $(document).click(function(e) {
            var container = $("#mobile-nav, #mobile-nav-toggle");
            if (!container.is(e.target) && container.has(e.target).length === 0) {
                if ($('body').hasClass('mobile-nav-active')) {
                    $('body').removeClass('mobile-nav-active');
                    $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
                    $('#mobile-body-overly').fadeOut();
                }
            }
        });
    } else if ($("#mobile-nav, #mobile-nav-toggle").length) {
        $("#mobile-nav, #mobile-nav-toggle").hide();
    }

    // Smoth scroll on page hash links
    $('a[href*="#"]:not([href="#"])').on('click', function() {
        if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') && location.hostname == this.hostname) {

            var target = $(this.hash);
            if (target.length) {
                var top_space = 0;

                if ($('#header').length) {
                    top_space = $('#header').outerHeight();
                    if (!$('#header').hasClass('header-fixed')) {
                        top_space = top_space - 20;
                    }
                }

                $('html, body').animate({
                    scrollTop: target.offset().top - top_space
                }, 1500, 'easeInOutExpo');

                if ($(this).parents('.nav-menu').length) {
                    $('.nav-menu .menu-active').removeClass('menu-active');
                    $(this).closest('li').addClass('menu-active');
                }

                if ($('body').hasClass('mobile-nav-active')) {
                    $('body').removeClass('mobile-nav-active');
                    $('#mobile-nav-toggle i').toggleClass('fa-times fa-bars');
                    $('#mobile-body-overly').fadeOut();
                }
                return false;
            }
        }
    });

    // Porfolio filter
    $("#portfolio-flters li").click(function() {
        $("#portfolio-flters li").removeClass('filter-active');
        $(this).addClass('filter-active');

        var selectedFilter = $(this).data("filter");
        $("#portfolio-wrapper").fadeTo(100, 0);
        $(".portfolio-item").fadeOut().css('transform', 'scale(0)');

        setTimeout(function() {
            $(selectedFilter).fadeIn(100).css('transform', 'scale(1)');
            $("#portfolio-wrapper").fadeTo(300, 1);
        }, 300);
    });

    // jQuery counterUp
    $('[data-toggle="counter-up"]').counterUp({
        delay: 10,
        time: 1000
    });

    particlesJS("particles", {
        "particles": {
            "number": {
                "value": 80,
                "density": {
                    "enable": true,
                    "value_area": 800
                }
            },
            "color": {
                "value": "#ffffff"
            },
            "shape": {
                "type": "circle",
                "stroke": {
                    "width": 0,
                    "color": "#000000"
                },
                "polygon": {
                    "nb_sides": 5
                },
                "image": {
                    "src": "img/github.svg",
                    "width": 100,
                    "height": 100
                }
            },
            "opacity": {
                "value": 0.8,
                "random": false,
                "anim": {
                    "enable": false,
                    "speed": 1,
                    "opacity_min": 0.1,
                    "sync": false
                }
            },
            "size": {
                "value": 4,
                "random": true,
                "anim": {
                    "enable": false,
                    "speed": 40,
                    "size_min": 0.1,
                    "sync": false
                }
            },
            "line_linked": {
                "enable": true,
                "distance": 150,
                "color": "#ffffff",
                "opacity": 0.4,
                "width": 1
            },
            "move": {
                "enable": true,
                "speed": 6,
                "direction": "none",
                "random": false,
                "straight": false,
                "out_mode": "out",
                "bounce": false,
                "attract": {
                    "enable": false,
                    "rotateX": 600,
                    "rotateY": 1200
                }
            }
        },
        "interactivity": {
            "detect_on": "canvas",
            "events": {
                "onhover": {
                    "enable": true,
                    "mode": "grab"
                },
                "onclick": {
                    "enable": true,
                    "mode": "push"
                },
                "resize": true
            },
            "modes": {
                "grab": {
                    "distance": 140,
                    "line_linked": {
                        "opacity": 1
                    }
                },
                "bubble": {
                    "distance": 400,
                    "size": 40,
                    "duration": 2,
                    "opacity": 8,
                    "speed": 3
                },
                "repulse": {
                    "distance": 200,
                    "duration": 0.4
                },
                "push": {
                    "particles_nb": 4
                },
                "remove": {
                    "particles_nb": 2
                }
            }
        },
        "retina_detect": true
    });


    var scrollToElement = function(el, ms) {
        var speed = (ms) ? ms : 600;
        $('html,body').animate({
            scrollTop: $(el).offset().top
        }, speed);
    }

    $(document).ready(function() {
        $('.nav-link').on('click', function(e) {
            e.preventDefault();
            var el = $(this).attr('href');
            scrollToElement(el);
        });

        $(window).scroll(function() {
            var x = $(window).scrollTop();

            if (x >= 42) {
                $("#navbar").fadeIn(300);
            } else {
                $("#navbar").fadeOut(300);
            }

        });
    });

    am4core.ready(function() {

        am4core.ready(function() {
        // Themes begin
        am4core.useTheme(am4themes_animated);
        // Themes end
        // Create chart instance
        var chart = am4core.create("chartdiv", am4charts.XYChart);
        // Add data
        chart.dataSource.url = "http://smartarms.in.ua/php/device_1/temp-chart.php";
        chart.dataSource.parser = new am4core.JSONParser();
        chart.dataSource.parser.options.emptyAs = 0;
        chart.numberFormatter.numberFormat = "#.'°'";
        // Create axes
        var categoryAxis = chart.xAxes.push(new am4charts.CategoryAxis());
        categoryAxis.dataFields.category = "time";
        // Create value axis
        var valueAxis = chart.yAxes.push(new am4charts.ValueAxis());
        // Create series
        var series = chart.series.push(new am4charts.LineSeries());
        series.dataFields.valueY = "temp";
        series.dataFields.categoryX = "time";
        series.name = "Температура";
        series.strokeWidth = 3;
        series.tensionX = 0.7;

        series.tooltipText = "{temp}'°'";
        series.tooltip.pointerOrientation = "vertical";
        series.fillOpacity = 1;

        var range = valueAxis.createSeriesRange(series);
        range.value = temp_up;
        range.endValue = temp_down;
        range.contents.stroke = am4core.color("#0abf44");
        range.contents.fill = range.contents.stroke;

        var range2 = valueAxis.createSeriesRange(series);
        range2.value = 0;
        range2.endValue = temp_down;
        range2.contents.stroke = am4core.color("#e62c2c");
        range2.contents.fill = range2.contents.stroke;

        var range3 = valueAxis.createSeriesRange(series);
        range3.value = temp_up;
        range3.endValue = 150;
        range3.contents.stroke = am4core.color("#e62c2c");
        range3.contents.fill = range3.contents.stroke;
        // Pre zoom
        chart.events.on("datavalidated", function () {
          categoryAxis.zoomToIndexes(Math.round(chart.data.length * 0.0), Math.round(chart.data.length * 1));
        });
        // Add scrollbar
        var scrollbarX = new am4charts.XYChartScrollbar();
        scrollbarX.series.push(series);
        chart.scrollbarX = scrollbarX;
        chart.cursor = new am4charts.XYCursor();
        // chart.cursor.xAxis = dateAxis;
        chart.cursor.snapToSeries = series;
        chart.legend = new am4charts.Legend();

        // Themes begin
        var chart2 = am4core.create("chartdiv-second", am4charts.XYChart);
        // Add data
        chart2.dataSource.url = "http://smartarms.in.ua/php/device_1/hum-chart.php";
        chart2.dataSource.parser = new am4core.JSONParser();
        chart2.dataSource.parser.options.emptyAs = 0;
        chart.numberFormatter.numberFormat = "#.'%'";
        // Create axes
        var categoryAxis2 = chart2.xAxes.push(new am4charts.CategoryAxis());
        categoryAxis2.dataFields.category = "time";
        // Create value axis
        var valueAxis2 = chart2.yAxes.push(new am4charts.ValueAxis());
        // Create series
        var series2 = chart2.series.push(new am4charts.LineSeries());
        series2.dataFields.valueY = "hum";
        series2.dataFields.categoryX = "time";
        series2.name = "Вологість";
        series2.strokeWidth = 3;
        series2.tensionX = 0.7;
        series.tooltipText = "{hum}";
        series.tooltip.pointerOrientation = "vertical";
        var range0 = valueAxis2.createSeriesRange(series2);
        range0.value = hum_up;
        range0.endValue = hum_down;
        range0.contents.stroke = am4core.color("#0abf44");
        range0.contents.fill = range0.contents.stroke;
        //
        var range20 = valueAxis2.createSeriesRange(series2);
        range20.value = 0;
        range20.endValue = hum_down;
        range20.contents.stroke = am4core.color("#e62c2c");
        range20.contents.fill = range20.contents.stroke;
        //
        var range30 = valueAxis2.createSeriesRange(series2);
        range30.value = hum_up;
        range30.endValue = 150;
        range30.contents.stroke = am4core.color("#e62c2c");
        range30.contents.fill = range30.contents.stroke;
        // Pre zoom
        chart2.events.on("datavalidated", function () {
          categoryAxis2.zoomToIndexes(Math.round(chart2.data.length * 0.0), Math.round(chart2.data.length * 1.0));
        });
        // Add scrollbar
        var scrollbarX2 = new am4charts.XYChartScrollbar();
        scrollbarX2.series.push(series2);
        chart2.scrollbarX = scrollbarX2;
        chart2.cursor = new am4charts.XYCursor();
        // chart2.cursor.xAxis = dateAxis;
        chart2.cursor.snapToSeries = series2;
        chart2.legend = new am4charts.Legend();
        }); // end am4core.ready()

        $('.cb-value').click(function() {
            var mainParent = $(this).parent('.toggle-btn');
            if ($(mainParent).find('input.cb-value').is(':checked')) {
                $(mainParent).addClass('active');
            } else {
                $(mainParent).removeClass('active');
            }
        });

        var chartes = am4core.create("chartdivindex", am4charts.ChordDiagram);


        chartes.data = [
            { from: "A", to: "D", value: 10 },
            { from: "B", to: "D", value: 8 },
            { from: "B", to: "E", value: 4 },
            { from: "B", to: "C", value: 2 },
            { from: "C", to: "E", value: 14 },
            { from: "E", to: "D", value: 8 },
            { from: "C", to: "A", value: 4 },
            { from: "G", to: "A", value: 7 },
            { from: "D", to: "B", value: 1 }
        ];

        chartes.dataFields.fromName = "from";
        chartes.dataFields.toName = "to";
        chartes.dataFields.value = "value";

        // make nodes draggable
        var nodeTemplate = chartes.nodes.template;
        nodeTemplate.readerTitle = "Click to show/hide or drag to rearrange";
        nodeTemplate.showSystemTooltip = true;

        var nodeLink = chartes.links.template;
        var bullet = nodeLink.bullets.push(new am4charts.CircleBullet());
        bullet.fillOpacity = 1;
        bullet.circle.radius = 5;
        bullet.locationX = 0.5;

        // create animations
        chartes.events.on("ready", function() {
            for (var i = 0; i < chartes.links.length; i++) {
                var link = chartes.links.getIndex(i);
                var bullet = link.bullets.getIndex(0);

                animateBullet(bullet);
            }
        })

        function animateBullet(bullet) {
            var duration = 3000 * Math.random() + 2000;
            var animation = bullet.animate([{ property: "locationX", from: 0, to: 1 }], duration)
            animation.events.on("animationended", function(event) {
                animateBullet(event.target.object);
            })
        }
    });
});

jQuery(document).ready(function($) {
    am4core.ready(function() {
        /**
         * ---------------------------------------
         * This demo was created using amCharts 4.
         * 
         * For more information visit:
         * https://www.amcharts.com/
         * 
         * Documentation is available at:
         * https://www.amcharts.com/docs/v4/
         * ---------------------------------------
         */
        // Themes begin
        am4core.useTheme(am4themes_animated);
        /**
         * Chart design taken from Samsung health app
         */
        var chart4 = am4core.create("chartdivssss", am4charts.XYChart);
        chart4.hiddenState.properties.opacity = 0; // this creates initial fade-in

        chart4.data = [{
            "date": "2018-01-01",
            "steps": 4561
        }, {
            "date": "2018-01-02",
            "steps": 5687
        }, {
            "date": "2018-01-03",
            "steps": 6348
        }, {
            "date": "2018-01-04",
            "steps": 4878
        }, {
            "date": "2018-01-05",
            "steps": 9867
        }, {
            "date": "2018-01-06",
            "steps": 7561
        }, {
            "date": "2018-01-07",
            "steps": 1287
        }, {
            "date": "2018-01-08",
            "steps": 3298
        }, {
            "date": "2018-01-09",
            "steps": 5697
        }, {
            "date": "2018-01-10",
            "steps": 4878
        }, {
            "date": "2018-01-11",
            "steps": 8788
        }, {
            "date": "2018-01-12",
            "steps": 9560
        }, {
            "date": "2018-01-13",
            "steps": 11687
        }, {
            "date": "2018-01-14",
            "steps": 5878
        }, {
            "date": "2018-01-15",
            "steps": 9789
        }, {
            "date": "2018-01-16",
            "steps": 3987
        }, {
            "date": "2018-01-17",
            "steps": 5898
        }, {
            "date": "2018-01-18",
            "steps": 9878
        }, {
            "date": "2018-01-19",
            "steps": 13687
        }, {
            "date": "2018-01-20",
            "steps": 6789
        }, {
            "date": "2018-01-21",
            "steps": 4531
        }, {
            "date": "2018-01-22",
            "steps": 5856
        }, {
            "date": "2018-01-23",
            "steps": 5737
        }, {
            "date": "2018-01-24",
            "steps": 9987
        }, {
            "date": "2018-01-25",
            "steps": 16457
        }, {
            "date": "2018-01-26",
            "steps": 7878
        }, {
            "date": "2018-01-27",
            "steps": 6845
        }, {
            "date": "2018-01-28",
            "steps": 4659
        }, {
            "date": "2018-01-29",
            "steps": 7892
        }, {
            "date": "2018-01-30",
            "steps": 7362
        }, {
            "date": "2018-01-31",
            "steps": 3268
        }];

        chart4.dateFormatter.inputDateFormat = "YYYY-MM-dd";
        chart4.zoomOutButton.disabled = true;

        var dateAxis4 = chart4.xAxes.push(new am4charts.DateAxis());
        dateAxis4.renderer.grid.template.strokeOpacity = 0;
        dateAxis4.renderer.minGridDistance = 10;
        dateAxis4.dateFormats.setKey("day", "d");
        dateAxis4.tooltip.hiddenState.properties.opacity = 1;
        dateAxis4.tooltip.hiddenState.properties.visible = true;
        dateAxis4.tooltip.adapter.add("x", function (x, target) {
            return am4core.utils.spritePointToSvg({ x: chart4.plotContainer.pixelX, y: 0 }, chart4.plotContainer).x + chart4.plotContainer.pixelWidth / 2;
        })
        var valueAxis4 = chart4.yAxes.push(new am4charts.ValueAxis());
        valueAxis4.renderer.inside = true;
        valueAxis4.renderer.labels.template.fillOpacity = 0.3;
        valueAxis4.renderer.grid.template.strokeOpacity = 0;
        valueAxis4.min = 0;
        valueAxis4.cursorTooltipEnabled = false;
        // goal guides
        var axisRange4 = valueAxis4.axisRanges.create();
        axisRange4.value = 6000;
        axisRange4.grid.strokeOpacity = 0.1;
        axisRange4.label.text = "Goal";
        axisRange4.label.align = "right";
        axisRange4.label.verticalCenter = "bottom";
        axisRange4.label.fillOpacity = 0.8;

        valueAxis4.renderer.gridContainer.zIndex = 1;

        var axisRange24 = valueAxis4.axisRanges.create();
        axisRange24.value = 12000;
        axisRange24.grid.strokeOpacity = 0.1;
        axisRange24.label.text = "2x goal";
        axisRange24.label.align = "right";
        axisRange24.label.verticalCenter = "bottom";
        axisRange24.label.fillOpacity = 0.8;

        var series4 = chart4.series.push(new am4charts.ColumnSeries);
        series4.dataFields.valueY = "steps";
        series4.dataFields.dateX = "date";
        series4.tooltipText = "{valueY.value}";
        series4.tooltip.pointerOrientation = "vertical";
        series4.tooltip.hiddenState.properties.opacity = 1;
        series4.tooltip.hiddenState.properties.visible = true;
        series4.tooltip.adapter.add("x", function (x, target) {
            return am4core.utils.spritePointToSvg({ x: chart4.plotContainer.pixelX, y: 0 }, chart4.plotContainer).x + chart4.plotContainer.pixelWidth / 2;
        })

        var columnTemplate4 = series4.columns.template;
        columnTemplate4.width = 30;
        columnTemplate4.column.cornerRadiusTopLeft = 20;
        columnTemplate4.column.cornerRadiusTopRight = 20;
        columnTemplate4.strokeOpacity = 0;

        var cursor4 = new am4charts.XYCursor();
        cursor4.behavior = "panX";
        chart4.cursor = cursor4;
        cursor4.lineX.disabled = true;

        chart4.events.on("datavalidated", function () {
            dateAxis4.zoomToDates(new Date(2018, 0, 21), new Date(2018, 1, 1), false, true);
        });

        var middleLine4 = chart4.plotContainer.createChild(am4core.Line);
        middleLine4.strokeOpacity = 1;
        middleLine4.stroke = am4core.color("#3d82ea");
        middleLine4.strokeDasharray = "2,2";
        middleLine4.align = "center";
        middleLine4.zIndex = 1;
        middleLine4.adapter.add("y2", function (y2, target) {
            return target.parent.pixelHeight;
        })
        cursor4.events.on("cursorpositionchanged", updateTooltip);
        dateAxis4.events.on("datarangechanged", updateTooltip);

        function updateTooltip() {
            dateAxis4.showTooltipAtPosition(0.5);
            series4.showTooltipAtPosition(0.5, 0);
            series4.tooltip.validate(); // otherwise will show other columns values for a second
        }
        var label4 = chart4.plotContainer.createChild(am4core.Label);
        label4.text = "Pan chart to change date";
        label4.x = 90;
        label4.y = 50;
        // Create shadow
        let shadow4 = series4.filters.push(new am4core.DropShadowFilter());
        shadow4.blur = 10;
        shadow4.color = "#3d82ea";
        // Create gradient
        let gradient4 = new am4core.LinearGradient();
        gradient4.addColor("#6871dc");
        gradient4.addColor("#3d82ea");
        series4.fill = gradient4;
        columnTemplate4.fill = "#3d82ea";

        /* Chart code */
        am4core.useTheme(am4themes_animated);
        // Themes end
        // Create chart instance
        var chart = am4core.create("temperatureRadial", am4charts.RadarChart);
        // Add data
        chart.data = [{
        "category": "Температура",
        "value": 35.76,
        "full": 100
        }];
        // Make chart not full circle
        chart.startAngle = -90;
        chart.endAngle = 270;
        chart.innerRadius = am4core.percent(80);
        // Set number format
        chart.numberFormatter.numberFormat = "#.#'%'";
        // Create axes
        var categoryAxis = chart.yAxes.push(new am4charts.CategoryAxis());
        categoryAxis.dataFields.category = "category";
        categoryAxis.renderer.grid.template.location = 0;
        categoryAxis.renderer.grid.template.strokeOpacity = 0;
        categoryAxis.renderer.labels.template.horizontalCenter = "right";
        categoryAxis.renderer.labels.template.fontWeight = 100;
        categoryAxis.renderer.labels.template.disabled = true;
        // Create axes
        var valueAxis = chart.xAxes.push(new am4charts.ValueAxis());
        valueAxis.renderer.grid.template.strokeOpacity = 0;
        valueAxis.min = 0;
        valueAxis.max = 100;
        valueAxis.strictMinMax = true;
        valueAxis.renderer.opposite = false;
        valueAxis.disabled = true;
        // Create series
        var series1 = chart.series.push(new am4charts.RadarColumnSeries());
        series1.dataFields.valueX = "full";
        series1.dataFields.categoryY = "category";
        series1.clustered = false;
        series1.columns.template.fill = new am4core.InterfaceColorSet().getFor("alternativeBackground");
        series1.columns.template.fillOpacity = 0.08;
        series1.columns.template.cornerRadiusTopLeft = 10;
        series1.columns.template.strokeWidth = 0;
        series1.columns.template.radarColumn.cornerRadius = 10;
        // Create series2
        var series2 = chart.series.push(new am4charts.RadarColumnSeries());
        series2.dataFields.valueX = "value";
        series2.dataFields.categoryY = "category";
        series2.clustered = false;
        series2.columns.template.strokeWidth = 0;
        series2.columns.template.tooltipText = "{category}: [bold]{value}[/]";
        series2.columns.template.radarColumn.cornerRadius = 10;
        // Create yearLabel
        var yearLabel = chart.radarContainer.createChild(am4core.Label);
        yearLabel.text = "35.76°";
        yearLabel.fontSize = 20;
        yearLabel.fontWeight = 700;
        yearLabel.horizontalCenter = "middle";
        yearLabel.verticalCenter = "middle";
        yearLabel.fontFamily = "Arial";
        yearLabel.fill = "#617082";
        // Create shadow
        let shadow = series2.filters.push(new am4core.DropShadowFilter());
        shadow.blur = 10;
        shadow.color = "#3d82ea";
        // Create gradient
        let gradient = new am4core.LinearGradient();
        gradient.addColor("#6871dc");
        gradient.addColor("#3d82ea");
        series2.fill = gradient;
        var humidityRadial = am4core.create("humidityRadial", am4charts.RadarChart);
        // Add data
        humidityRadial.data = [{
        "category": "Вологість",
        "value": 53.2,
        "full": 100
        }];
        // Make chart not full circle
        humidityRadial.startAngle = -90;
        humidityRadial.endAngle = 270;
        humidityRadial.innerRadius = am4core.percent(80);
        // Set number format
        humidityRadial.numberFormatter.numberFormat = "#.#'%'";
        // Create axes
        var categoryAxis2 = humidityRadial.yAxes.push(new am4charts.CategoryAxis());
        categoryAxis2.dataFields.category = "category";
        categoryAxis2.renderer.grid.template.location = 0;
        categoryAxis2.renderer.grid.template.strokeOpacity = 0;
        categoryAxis2.renderer.labels.template.horizontalCenter = "right";
        categoryAxis2.renderer.labels.template.fontWeight = 100;
        categoryAxis2.renderer.labels.template.disabled = true;
        var valueAxis2 = humidityRadial.xAxes.push(new am4charts.ValueAxis());
        valueAxis2.renderer.grid.template.strokeOpacity = 0;
        valueAxis2.min = 0;
        valueAxis2.max = 100;
        valueAxis2.strictMinMax = true;
        valueAxis2.renderer.opposite = false;
        valueAxis2.disabled = true;
        // Create series
        var series11 = humidityRadial.series.push(new am4charts.RadarColumnSeries());
        series11.dataFields.valueX = "full";
        series11.dataFields.categoryY = "category";
        series11.clustered = false;
        series11.columns.template.fill = new am4core.InterfaceColorSet().getFor("alternativeBackground");
        series11.columns.template.fillOpacity = 0.08;
        series11.columns.template.cornerRadiusTopLeft = 10;
        series11.columns.template.strokeWidth = 0;
        series11.columns.template.radarColumn.cornerRadius = 10;
        var series22 = humidityRadial.series.push(new am4charts.RadarColumnSeries());
        series22.dataFields.valueX = "value";
        series22.dataFields.categoryY = "category";
        series22.clustered = false;
        series22.columns.template.strokeWidth = 0;
        series22.columns.template.tooltipText = "{category}: [bold]{value}[/]";
        series22.columns.template.radarColumn.cornerRadius = 10;
        var yearLabel2 = humidityRadial.radarContainer.createChild(am4core.Label);
        yearLabel2.text = "53.2%";
        yearLabel2.fontSize = 20;
        yearLabel2.fontWeight = 700;
        yearLabel2.horizontalCenter = "middle";
        yearLabel2.verticalCenter = "middle";
        yearLabel2.fontFamily = "Arial";
        yearLabel2.fill = "#617082";
        let shadow2 = series22.filters.push(new am4core.DropShadowFilter());
        shadow2.blur = 10;
        shadow2.color = "#3d82ea";
        let gradient2 = new am4core.LinearGradient();
        gradient2.addColor("#6871dc");
        gradient2.addColor("#3d82ea");
        series22.fill = gradient2;
    });
});
	</script>
  </body>
</html>
)=====";