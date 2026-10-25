##############################################
############ BUILD XGPU-SPEC #################
##############################################

SPEC_NAME  := xgpu-spec
SPEC_SRC   := spec
SPEC_TOP   := $(SPEC_SRC)/$(SPEC_NAME).adoc
SPEC_BUILD := build_spec
SPEC_DEPS  := $(shell find $(SPEC_SRC) -name '*.adoc')
THEME_DIR  := $(SPEC_SRC)/themes
SPEC_THEME      := $(THEME_DIR)/xgpu-theme.yml
PDF_OPTS   := -a pdf-theme=$(SPEC_THEME) \
              -a pdf-fontsdir="$(THEME_DIR)/fonts;GEM_FONTS_DIR"

spec: $(SPEC_BUILD)/$(SPEC_NAME).pdf #$(SPEC_BUILD)/$(SPEC_NAME).html

$(SPEC_BUILD)/$(SPEC_NAME).pdf: $(SPEC_DEPS) $(SPEC_THEME)
	@mkdir -p $(SPEC_BUILD)
	asciidoctor-pdf -r asciidoctor-diagram $(PDF_OPTS) $(SPEC_TOP) -o $@


#$(SPEC_BUILD)/$(SPEC_NAME).html: $(SPEC_DEPS)
#	@mkdir -p $(SPEC_BUILD)
#	asciidoctor -r asciidoctor-diagram $(SPEC_TOP) -o $@

clean_spec:
	rm -rf $(SPEC_BUILD) .asciidoctor

.PHONY: spec clean_spec

##############################################
############## END XGPU-SPEC #################
##############################################